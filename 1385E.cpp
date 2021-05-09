#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef long long ll;
int n,visited[2000010],m,ord[200010],tt;
vector<vi> adj;

bool dfs(int u) {
	visited[u] = 1;
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (visited[v] == 1) return false;
		if (visited[v] == -1) {
			if(!dfs(v)) return false;
		}
	}
	ord[u] = tt--; visited[u] = 0;
	return true;
}
void solve() {
	vector<ii> que, edges;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) visited[i] = -1;
	tt = n;
	adj.assign(n + 1, vi());
	for (int i = 0; i < m; i++) {
		int t, x, y; cin >> t >> x >> y;
		if (t==1) adj[x].push_back(y), edges.push_back(ii(x,y));
		else que.push_back(ii(x, y));
	}
	
	for (int i = 1; i <= n; i++) {
		if (visited[i] == -1) {
			if (!dfs(i)) { cout << "NO" << endl; return; }
		}
	}
	cout << "YES" << endl;
	for (int i = 0; i < que.size(); i++) {
		int x = que[i].first, y = que[i].second;
		if (ord[x] > ord[y]) edges.push_back(ii(y, x));
		else edges.push_back(ii(x, y));
	}
	for (int i = 0; i < edges.size(); i++) {
		cout << edges[i].first << " " << edges[i].second << endl;
	}
}
int main()
{
	int t; cin >> t;
	while (t--) solve();
//	system("pause");
    return 0;
}

