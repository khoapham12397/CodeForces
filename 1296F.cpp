#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ii, int> i3;
int n,m,par[5010],cr[5010][5010],sub[5010][5010],childs[5010][5010],slc[5010];
vi adj[5010];
vector<ii> edges;
i3 que[5010];
// vi du them vao cai gi ???
// dung chua ne :

void cal(int u) {
	int sl = 1;
	childs[u][0] = u; slc[u] = 1;
	bool isLeaf = true;
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (par[u] != v) {
			par[v] = u; isLeaf = false;
			cal(v);  
			for (int j = 0; j < slc[v]; j++) {
				cr[u][childs[v][j]] = cr[childs[v][j]][u] = u;
				childs[u][sl++]=childs[v][j];
			}
		}
	}
	slc[u] = sl;
	if (isLeaf) return;
	int len = int(adj[u].size());
	if (len == 2) return;
	for (int i = 0; i < len-1; i++) {
		int v = adj[u][i];
		if (v == par[u]) continue;
		for (int j = i + 1; j < len; j++) {
			int w = adj[u][j];
			if (w == par[u]) continue;
			for (int j1 = 0; j1 < slc[v]; j1++) {
				for (int j2 = 0; j2 < slc[w]; j2++) {
					cr[childs[v][j1]][childs[w][j2]] = cr[childs[w][j2]][childs[v][j1]] = u;
				}
			}
		}
	}
	
}
void solve() {
	cin >> n;
	for (int i = 1; i < n; i++) {
		int x, y; cin >> x >> y;
		adj[x].push_back(y); adj[y].push_back(x);
		par[i] = 0;
		edges.push_back(ii(x, y));
	}
	par[n] = 0;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) sub[i][j] = 0;
	// but ta can co:

	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		que[i].first = ii(a, b);
		que[i].second = c;
	}
	cal(1);
	for (int i = 0; i < m; i++) {
		int a = que[i].first.first, b = que[i].first.second , c=que[i].second;
		int root = cr[a][b] , st1=0 , st2=0;
		if (root == a) st1 = b, st2 = 0;
		if (root == b) st1 = a, st2 = 0;
		if (root != a && root != b) st1 = a, st2 = b;
		
		int x = st1,y; 
		while (x != root) {
			y = par[x];
			sub[x][y] = sub[y][x] = max(sub[x][y], c);
			x = y;
		}
		
		if (st2 != 0) {
			x = st2;
			while (x != root) {
				y = par[x];
				sub[x][y] = sub[y][x] = max(sub[x][y], c);
				x = y;
			}
		}
	}
	for (int i = 0; i < m; i++) {
		int a = que[i].first.first, b = que[i].first.second, c = que[i].second;
		int root = cr[a][b], st1 = 0, st2 = 0;
		if (root == a) st1 = b, st2 = 0;
		if (root == b) st1 = a, st2 = 0;
		if (root != a && root != b) st1 = a, st2 = b;
		int x = st1,y,sc=0, scc = 0;
		while (x != root) {
			y = par[x]; sc++;
			if (sub[y][x] > c) scc++;
			x = y;
		}
		if (st2 != 0) {
			x = st2; 
			while (x != root) {
				y = par[x]; sc++;
				if (sub[y][x] > c) scc++;
				x = y;
			}
		}
		if (sc == scc) { cout << -1 << endl; return; }
	}
	for (int i = 0; i < edges.size(); i++) {
		int u = edges[i].first, v = edges[i].second;
		if (sub[u][v] == 0) cout << 1 << " ";
		else cout << sub[u][v] << " ";
	}
	cout << endl;
}
int main()
{
	solve();
//	system("pause");
    return 0;
}

