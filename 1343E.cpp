#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
int n, m, p[200010],a,b,c,da[200010],db[200010],dc[200010];
ll f[200010];
vi adj[200010];

void solve() {
	cin >> n >> m >> a >> b >> c;
	
	for (int i = 1; i <= n; i++) adj[i].clear();
	for (int i = 0; i < m; i++) {
		cin >> p[i];
	}
	
	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		adj[x].push_back(y); adj[y].push_back(x);
	}
	queue<int> q; q.push(a);
	vector<bool> vs(n + 1,false);
	vs[a] = 1; da[a] = 0;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int i = 0; i < adj[u].size(); i++) {
			int v = adj[u][i];
			if (!vs[v]) {
				da[v] = da[u] + 1; q.push(v); vs[v] = 1;
			}
		}
	}
	vs.assign(n + 1, 0);
	q.push(b); vs[b] = 1; db[b] = 0;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int i = 0; i < adj[u].size(); i++) {
			int v = adj[u][i];
			if (!vs[v]) {
				db[v] = db[u] + 1; q.push(v); vs[v] = 1;
			}
		}
	}
	vs.assign(n + 1, 0);
	q.push(c); vs[c] = 1; dc[c] = 0;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int i = 0; i < adj[u].size(); i++) {
			int v = adj[u][i];
			if (!vs[v]) {
				dc[v] = dc[u] + 1; q.push(v); vs[v] = 1;
			}
		}
	}
	sort(p, p + m);
	f[0] = p[0];
	for (int i = 1; i < m; i++) f[i] = f[i - 1] + ll(p[i]);
	ll ans = ll(1e17);
	for (int i = 1; i <= n; i++) {
		if (i != a && i != b && i != c) {
			int x = db[i], y= da[i],z= dc[i];
			if (x + y + z <= m) ans = min(ans, f[x + y + z - 1] + f[x - 1]);
		}
	}

	int x = da[c], y=dc[b],z= da[b];
	if(x+y<=m) ans = min(ans,f[x + y - 1] + f[y - 1]);
	if(y+z<=m) ans = min(ans, f[y + z - 1]);
	if(z+x<=m) ans = min(ans, f[z + x - 1] + f[z - 1]);
	cout << ans << endl;

}
int main()
{
	int t; cin >> t;
	while (t--) solve();
//	system("pause");
    return 0;
}

