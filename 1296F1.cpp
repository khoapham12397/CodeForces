#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef pair<ii, int> i3;
int n, m,par[5010],sub[5010][5010],root[5001];
i3 infos[5001];
bool tt[5010][5010];
ii edges[5010];
vi adj[5010];
void cal(int u, vi vt) {
	for (int i = 0; i < vt.size(); i++) {
		tt[vt[i]][u] = 1;
	}
	vt.push_back(u);
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (par[u] != v) {
			par[v] = u;
			cal(v, vt);
		}
	}
}
void solve() {
	cin >> n;
	for (int i = 1; i < n; i++) {
		par[i] = 0;
		int x, y; cin >> x >> y;
		adj[x].push_back(y); adj[y].push_back(x);
		edges[i-1] = ii(x, y);
	}
	par[n] = 0;
	cal(1,vi());
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		infos[i].first = ii(a, b); infos[i].second = c;
	}
	for (int i = 0; i < m; i++) {
		int a = infos[i].first.first, b = infos[i].first.second, c = infos[i].second;
		if (tt[a][b]) {
			int x = b,y;
			while (x != a) {
				y = par[x];
				sub[x][y] = sub[y][x] = max(sub[x][y], c);
				x = y;
			}
			root[i] = a;
		}
		else {
			if (tt[b][a]) {
				int x = a, y;
				while (x != b) {
					y = par[x];
					sub[x][y] = sub[y][x] = max(sub[x][y], c);
					x = y;
				}
				root[i] = b;
			}
			else {
				int x = a,y,x1;
				while (!tt[x][b]) {
					y = par[x];
					sub[x][y] = sub[y][x] = max(sub[x][y], c);
					x = y;
				}
				x1 = b;
				while (x1 != x) {
					y = par[x1];
					sub[x1][y] = sub[y][x1] = max(sub[x1][y], c);
					x1 = y;
				}
				root[i] = x;
			}
		}
	}
	for (int i = 0; i < m; i++) {
		int a = infos[i].first.first, b = infos[i].first.second, c = infos[i].second;
		int u = root[i];
		int x = a,y, sc =0 ,scc=0;
		while (x != u) {
			y = par[x]; sc++;
			if (sub[y][x] > c) scc++;
			x = y;
		}
		x = b;
		while (x != u) {
			y = par[x]; sc++;
			if (sub[y][x] > c)scc++;
			x = y;
		}
		if (scc == sc) { cout << -1 << endl; return; }
	}
	for (int i = 0; i < n-1; i++) {
		int x = edges[i].first, y = edges[i].second;
		if (sub[x][y] == 0) cout << 1 << " ";
		else cout << sub[x][y] << " ";
	}
	cout << endl;
}
int main()
{
	solve();
//	system("pause");
    return 0;
}
