#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef vector<int> vi;
int n,k=0,par[310],a[310],check[310];
vi adj[310],childs[310];
bool rel[310][310];
vi cal(int u) {
	vi leaves;
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (par[u] != v) {
			par[v] = u;
			vi ls = cal(v);
			childs[u].push_back(v);
			for (int j = 0; j < ls.size(); j++) leaves.push_back(ls[j]),rel[u][ls[j]]=true;
		}
	}
	if (childs[u].size() == 0) {
		k++; leaves.push_back(u);
	}
	return leaves;
}
void solve() {
	cin >> n;
	for (int i = 1; i < n; i++) {
		int x, y; cin >> x >> y;
		adj[x].push_back(y); adj[y].push_back(x);
		par[i] = 0;
	}
	par[n] = 0;
	cal(1);
	for (int i = 0; i < k; i++) cin >> a[i];
	vi path;
	int u = a[0],p=par[u],x=a[0];
	while (x != 1) { path.push_back(x); x = par[x]; }
	path.push_back(1); reverse(path.begin(), path.end());
	path.push_back(p);
	for (int i = 0; i < path.size() - 2; i++) check[path[i]] = 1;
	for (int i = 1; i < k; i++) {
		int v = a[i];
		while (p!=0 && check[p] == childs[p].size()) {
			p = par[p];
			if (p != 0) path.push_back(p);
		}
		if (!rel[p][v]) {
			cout << -1 << endl; return;
		}
		else {
			int x = v;
			vi vt; vt.push_back(v);
			while (x != p) {
				x = par[x];
				vt.push_back(x);
				check[x]++;
			}

			for (int i = vt.size() - 2; i >=0; i--) path.push_back(vt[i]);
			p = par[v]; path.push_back(p);
		}
	}
	x = p;
	while (x != 1) {
		x = par[x]; path.push_back(x);
	}
	for (int i = 0; i < path.size(); i++) cout << path[i] << " "; cout << endl;
}
int main()
{
	solve();
//	system("pause");
    return 0;
}

