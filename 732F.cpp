#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>
using namespace std;
typedef pair<int, int>ii;
typedef pair<int, ii> i3;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<i3> vi3;
int n,m,visited[400010], num[400010], low[400010] , dfsCount=0,par[400010], grId[400010];

int slg=0 , grMax=0,idGM=0;
stack<int> st;
vii bridges,es;
map<ii,int> edges;

vi adj[400010],dirs;

vector<vi3> eds;

void findBridges(int u) {
	num[u] = low[u] = dfsCount; dfsCount++;
	visited[u] = 1;
	st.push(u);
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (visited[v]==0) {
			par[v] = u;
			findBridges(v);
			low[u] = min(low[u], low[v]);
			
			if (low[v] > num[u]) {
				bridges.push_back(ii(u, v));
				slg++; int t = 1;
				while (st.top()!=v) {
					grId[st.top()] = slg;
					st.pop(); t++;
				}
				if (t > grMax) grMax = t, idGM = slg; 
				grId[v] = slg; st.pop();
			}
			else {
				int x = edges[ii(u, v)];
				if (x == 0) { int y = edges[ii(v, u)]; dirs[y] = 1; }
			}
		}
		else {
			if (par[u] != v) {
				low[u] = min(low[u], low[v]);
				if(visited[v]==1) { 
					int x = edges[ii(u, v)];
					if (x == 0) { int y = edges[ii(v, u)]; dirs[y] = 1; }
				}
			}
		}
	}
	visited[u] = 2;
}
void duyet(int u ,int pre) {
	for (int i = 0; i < eds[u].size(); i++) {
		int v = eds[u][i].first;
		if (v != pre) {
			int x = eds[u][i].second.first, y = eds[u][i].second.second;
			int al = edges[ii(y, x)];
			if (!al) { dirs[edges[ii(x, y)]] = 1; }
			duyet(v, u);
		}
	}
}

void solve() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		edges[ii(x, y)] = i + 1;
		es.push_back(ii(x, y));
		adj[x].push_back(y); adj[y].push_back(x);
	}
	dirs.assign(m + 1, 0);

	for (int i = 1; i <= n; i++) sort(adj[i].begin(), adj[i].end()),visited[i]=0;
	findBridges(1);
	slg++; int t = 0;
	while (!st.empty()) {
		int x = st.top(); st.pop();
		grId[x] = slg; t++;
	}
	if (t > grMax) grMax = t, idGM = slg;
	

	eds.assign(slg + 1, vi3());

	for (int i = 0; i < bridges.size(); i++) {
		int u = bridges[i].first, v = bridges[i].second;
		eds[grId[u]].push_back(i3(grId[v], ii(u, v)));
		eds[grId[v]].push_back(i3(grId[u], ii(v, u)));
	}
	duyet(idGM, 0);
	
	cout << grMax << endl;
	for (int i = 1; i <= m; i++) {
		int u = es[i - 1].first, v = es[i - 1].second;
		if (dirs[i]) cout << v << " " << u << endl;
		else cout << u << " " << v << endl;
	}
}
int main()
{
	solve();
//	system("pause");
    return 0;
}

