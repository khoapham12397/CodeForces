#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
int n,fb[29],par[200010], w[200010];
vii adj[200010];
int BSearch(int val ,int l,int r,int u) {
	if (l == r) {
		return l;
	}
	int mid = (l + r) >> 1;
	if (val == adj[u][mid].first) return mid;
	if (adj[u][mid].first > val) {
		return BSearch(val, l, mid - 1, u);
	}
	return BSearch(val, mid + 1, r, u);
}
void duyet(int u) {
	int t = 1;
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i].first;
		if (v != par[u]) {
			par[v] = u;
			duyet(v); t += w[v];
		}
	}
	w[u] = t;
}
int find(int u,int val1, int val2) {
	
	if (w[u] < val2) return 0;
	for (int i = 0; i < adj[u].size(); i++) {
		ii v = adj[u][i];
		int v1 = v.first;
		if (!v.second && v1 != par[u]) {
			if (w[v1] == val1 || w[v1]==val2) {
				return v1;
			}
			if (w[v1] > val2) {
				int x = find(v1,val1,val2);
				if (x > 0) return x;
			}
		}
	}
	return 0;
}
bool cal(int u ,int t) {
	if (t == 1 || t==0) return true;
	int v = find(u, fb[t-1],fb[t - 2]);
	if (v == 0) return false;
	int p = par[v],del = w[v];
	int ind = BSearch(v, 0, adj[p].size() - 1, p);
	adj[p][ind].second = 1;
	int x = p;
	while (x != u) {
		w[x] -= del;
		x = par[x];
	}
	w[u] -= del;
	if (del == fb[t - 2]) {
		if (!cal(v, t - 2)) return false;
		return cal(u, t - 1);
	}
	else {
		if (!cal(v, t - 1)) return false;
		return cal(u, t - 2);
	}
}
void solve() {
	cin >> n;
	for (int i = 1; i< n; i++) {
		int x, y; cin >> x >> y;
		adj[x].push_back(ii(y,0)); adj[y].push_back(ii(x,0));
		par[i] = 0;
	}
	par[n] = 0;
	fb[0] = fb[1] = 1;
	for (int i = 2; i < 28; i++) fb[i] = fb[i - 1] + fb[i - 2];
	int s = -1;
	for (int i = 0; i < 28; i++) if (fb[i] == n) {
		s = i; break;
	}
	if (s == -1) {
		cout << "NO" << endl; return;
	}
	for (int i = 1; i <= n; i++) sort(adj[i].begin(), adj[i].end());
	duyet(1);
	if (cal(1, s)) cout << "YES" << endl;
	else cout << "NO" << endl;
}
int main()
{
	solve();
//	system("pause");
    return 0;
}

