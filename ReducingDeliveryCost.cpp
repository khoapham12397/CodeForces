#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>
#include <vector>
using namespace std;
const int inf = 1000000007;
typedef pair<int, int> ii;
typedef vector<ii> vii;
int n,m,k;
int f[1001][1001];
vii adj[1001],routes,edges;

void djk(int root) {
	priority_queue < ii, vii, greater<ii>>q;
	for (int i = 0; i <= n; i++) f[root][i] = inf;
	f[root][root] = 0;
	q.push(ii(0, root));
	while (!q.empty()) {
		ii front = q.top(); q.pop();
		int u = front.second;
		if (f[root][u] < front.first) continue;
		for (int i = 0; i < adj[u].size(); i++) {
			ii v = adj[u][i];
			if (f[root][v.first] > f[root][u] + v.second) {
				f[root][v.first] = f[root][u] + v.second;
				q.push(ii(f[root][v.first], v.first));
			}
		}
	}

}
void solve() {
	cin >> n >> m>>k;
	
	for (int i = 0; i < m; i++) {
		int x, y, w; cin >> x >> y >> w;
		adj[x].push_back(ii(y, w));
		adj[y].push_back(ii(x, w));
		edges.push_back(ii(x, y));
	}
	for (int i = 0; i < k; i++) {
		int x, y; cin >> x >> y;
		routes.push_back(ii(x, y));
	}
	for (int i = 1; i <= n; i++) djk(i);
	int ans = inf;
	for (int i = 0; i < m; i++) {
		int u = edges[i].first, v = edges[i].second;
		int vals = 0;
		for (int j = 0; j < k; j++) {
			int x1 = routes[j].first, x2 = routes[j].second;
			int v1 = min(f[x1][u] + f[v][x2], f[x1][v] + f[u][x2]);
			vals += min(f[x1][x2],v1);
		}
		ans = min(ans, vals);
	}
	cout << ans << endl;
}

int main()
{
	solve();
//	system("pause");
    return 0;
}

