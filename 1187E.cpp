#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
int par[200010];
bool isLeaf[200010];
vi adj[200010];
ll f[200010],dp[200010],s[200010] ,ans  = 0,n;
void duyet(int u) {
	s[u] = 1; f[u] = 0;
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (par[u] != v) {
			par[v] = u;
			duyet(v);
			s[u] += s[v];
			f[u] += f[v];
		}
	}
	
	f[u] += s[u];
}
void cal(int u) {
	ll tong = 0;
	dp[u] = dp[par[u]] - 2*s[u] + n;
	ans = max(ans, dp[u]);
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (par[u] != v) {
			cal(v);
		}
	}
}
void solve() {
	cin >> n;
	for (int i = 1; i < n; i++) {
		int x, y; cin >> x >> y;
		par[i] = 0;
		adj[x].push_back(y); adj[y].push_back(x);
	}par[n] = 0;
	duyet(1); dp[1] = f[1];
	
	for (int i = 0; i < adj[1].size(); i++) {
		int v = adj[1][i]; 
		cal(v);
	}
	cout << ans << endl;
}
int main()
{
	solve();
//	system("pause");
    return 0;
}

