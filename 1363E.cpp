#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<int> vi;
int n,c[200010],b[200010],par[200010], r0[200010],r1[200010];
bool vs[200010];
ii a[200010];
vi adj[200010];

void cal(int u) {
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (par[u] != v) {
			par[v] = u; cal(v);
		}
	}
}
ii duyet(int u) {
	vs[u] = 1;
	int x0 = 0, x1 = 0;
	if (!b[u] && c[u]) x0++;
	if (b[u] && !c[u]) x1++;
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (par[u] != v) {
			if (vs[v]) {
				x0 += r0[v]; x1 += r1[v];
			}
			else {
				ii val = duyet(v);
				x0 += val.first; x1 += val.second;
			}
		}
	}
	return ii(x0, x1);
}
void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].first>>b[i]>>c[i];
		a[i].second = i;
		par[i] = 0; vs[i] = 0; 
		r0[i] = r1[i] = 0;
	}
	for (int i = 1; i < n; i++) {
		int x, y; cin >> x >> y;
		adj[x].push_back(y); adj[y].push_back(x);
	}
	sort(a + 1, a + n + 1);
	cal(1);
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		int id = a[i].second;
		
		if (vs[id]) continue;
		ii val = duyet(id);
		int x0 = val.first, x1 = val.second;
		int gtmin = min(x0, x1);
		ans +=ll(a[i].first) *ll(gtmin) *2;
		r0[id] = x0 - gtmin; r1[id] = x1 - gtmin;
	}
	if (r0[1] > 0 || r1[1] > 0) cout << -1 << endl;
	else cout << ans << endl;
}
int main()
{
	solve();
//	system("pause");
    return 0;
}

