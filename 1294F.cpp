#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef vector<int> vi;
int n,par[200001],root=0,gtmax=0,f2[200001],par1[200001];
int ln1[200001], ln2[200001];
vi adj[200001];
int cal(int u) {
	int x1=0, x2=0,v1=0,v2=0;
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (par[u] != v) {
			par[v] = u;
			int x=cal(v);
			if (x >= x1) {
				v2 = v1; v1 = v;
				x2 = x1; x1 = x;
			}
			else if (x > x2) x2 = x,v2=v;
		}
	}
	if (x1 == 0 && x2 == 0) {
		ln1[u] = u; ln2[u] = u;
		f2[u] = 1; 
		return 1;
	}
	if (x1 + x2 + 1 > gtmax) {
		root = u; gtmax = x1 + x2 + 1;
	}

	ln1[u] = ln1[v1]; ln2[u] = ln1[v2];
	f2[u] = x2 + 1;
	return x1 + 1;
}
int tinh(int u) {
	int ans = 1;
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (par1[u] != v) {
			par1[v] = u;
			ans=max(ans,tinh(v)+1);
		}
	}
	return ans;
}
void solve() {
	cin >> n;
	for (int i = 1; i < n; i++) {
		par[i] = 0;
		int x, y; cin >> x >> y;
		adj[x].push_back(y); adj[y].push_back(x);
	}
	par[n] = 0;
	cal(1);
	
	int l1 = ln1[root], l2 = ln2[root],l3;
	int x = par[l1],n1,n2;
	int ans = gtmax - 1,val=0;
	if (x == root) n1 = l1;
	while (x != root) {
		if (val < f2[x] - 1) {
			val = f2[x] - 1;
			l3 = ln2[x];
		}
		if (par[x] == root) n1 = x;
		x = par[x];
	}

	x = par[l2];
	if (x != 0) {
		while (x != root) {
			if (val < f2[x] - 1) {
				val = f2[x] - 1;
				l3 = ln2[x];
			}
			if (par[x] == root) n2 = x;
			x = par[x];
		}
	}
	if (l2 == 0) l2 = root,n2=0;
	
	for (int i = 0; i < adj[root].size(); i++) {
		int x = adj[root][i];
		if (x != n1 && x != n2) {
			int y= tinh(x)-1;
			if (y > val) { val = y; l3 = ln1[x]; }
		}
	}
	
	ans += val;
	cout << ans << endl;
	cout << l1 << " " << l2 << " " << l3<<endl;
}
int main()
{
	solve();
//	system("pause");
    return 0;
}

