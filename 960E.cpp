#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> i3;
typedef vector<int> vi;
int n,par[200010];
vi adj[200010];
ll ans = 0 ,mod= ll(1e9)+7 ,a[200010];
vector<i3> ds[200010];
ii f[200010],fp[200010];
void duyet(int u) {
	f[u].first = 0, f[u].second = 0;
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (par[u] != v) {
			par[v] = u;
			duyet(v);
			ds[u].push_back(i3(v, ii(f[v].second, f[v].first +1 )));
			f[u].first += f[v].second;
			f[u].second += f[v].first + 1;
		}
	}
}
void cal(int u) {
	int root = par[u];
	int x = f[root].first - f[u].second + fp[root].first, y = f[root].second - f[u].first - 1 + fp[root].second;
	fp[u].first = y; fp[u].second = x + 1;
	ll total = f[u].first + f[u].second + fp[u].first + fp[u].second, sla=0, sld = 0;
	sld = (total+1)%mod;
	
	sld = (sld + ((ll(fp[u].first)* ll((1 + total - fp[u].first - fp[u].second))) % mod)) % mod;
	sla = (ll(fp[u].second) *ll((1 + total - fp[u].first - fp[u].second))) % mod;
	for (int i = 0; i < ds[u].size(); i++) {
		int v = ds[u][i].first;
		
		sld = (sld + ((ll(f[v].second) * ll((1 + total - f[v].first - f[v].second - 1))) % mod)) % mod;
		sla = (sla + ((ll(f[v].first + 1)* ll(1 + total - f[v].first - f[v].second - 1)) % mod)) % mod;
		cal(ds[u][i].first);
	}
	
	ans = (ans + ((((sld + (mod - sla)) % mod)*a[u]) % mod)) % mod;
}
void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i], par[i] = 0;
		while (a[i] < 0) a[i] += mod;
		a[i] = a[i] % mod;
	}
	for (int i = 1; i < n; i++) {
		int x, y; cin >> x >> y;
		adj[x].push_back(y); adj[y].push_back(x);
	}
	duyet(1);
	fp[1] = ii(0, 0);
	ll total = f[1].first + f[1].second ,sld= 0, sla=0;
	sld = (total+1)%mod;
	for (int i = 0; i < ds[1].size(); i++) {
		int v = ds[1][i].first;
		sld = (sld + ((ll(f[v].second)*ll(1+ total - f[v].first - f[v].second - 1)) % mod)) % mod;
		sla = (sla + ((ll(f[v].first + 1)* ll(1 + total - f[v].first - f[v].second - 1)) % mod)) % mod;
		cal(ds[1][i].first);
	}
	ll sl = (sld + ((mod-sla)%mod))%mod;
	ans = (ans + ((sl*a[1]) % mod)) % mod;	
	cout << ans << endl;
}
int main()
{
	solve();
//	system("pause");
    return 0;
}

