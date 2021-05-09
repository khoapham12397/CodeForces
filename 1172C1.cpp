#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int>ii;
int n,m,b[51],a[51];
ll dp[51][51][51][51] , rx[3000],mod= 998244353;
ll powMod(ll x, ll y ) {
	ll ans = 1, z = x;
	while (y > 0) {
		if (y % 2 == 1) ans = (ans*z) % mod;
		z = (z*z) % mod;
		y >>= 1;
	}
	return ans;
}
ll inv(ll x) { return powMod(x, mod - 2); }
void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> b[i];
	rx[0] = 0;

	int s=0, sp=0, sn=0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i]; 
		s += a[i];
		sp += a[i] * b[i];
		sn += a[i] * (!b[i]);
	}
	for (int u = 0; u <= n; u++) for (int i = 0; i <= m; i++) for (int j = 0; j <= m; j++)for (int t = 0; t <= m; t++) dp[i][j][u][t] = 0;
	for (int i = 1; i < 3000; i++) rx[i] = inv(i);
	
	for (int u = 1; u <= n; u++) {
		if (b[u]) {
			dp[1][1][u][0] = (ll(sp - a[u])*rx[s]) % mod;
			dp[1][1][u][1] = (ll(a[u])*rx[s]) % mod;
			dp[1][0][u][0] = (ll(sn)*rx[s]) % mod;

			dp[1][0][u][1] = 0; 
			for (int i = 2; i <= m; i++) {
				for (int j = 0; j <= i; j++) {
					if (sn < i - j) continue;
					for (int t = 0; t <= j; t++) {
						ll gt = 0;
						
						
						if (i > j) {
							int cs = s + j - ((i - 1) - j), csn = sn - (i - 1) + j;
							
							if (csn >= 0) {
								gt = (gt + ((dp[i - 1][j][u][t] * ((ll(csn) * rx[cs]) % mod)) % mod)) % mod;
							}
						}
						if (j > 0) {
							
							//dp[i-1][j-1][u][t], chon 1 gt thich 
							int cs = s + j - 1 - (i - 1) + j - 1, csp = sp + j - 1, cu = a[u] + t;
							
							gt = (gt + ((dp[i - 1][j - 1][u][t] * ((ll(csp - cu)*rx[cs]) % mod)) % mod)) % mod;
							
							if (t > 0) {
								//dp[i-1][j-1][u][t-1] // chon 1 gia tri la u:

								int cs = s + j - 1 - (i - 1) + j - 1, cu = a[u] + t - 1;
								gt = (gt + ((dp[i - 1][j - 1][u][t - 1] * ((ll(cu)*rx[cs]) % mod)) % mod)) % mod;
							}
						}
						dp[i][j][u][t] = gt;
					}
				}
			}
		}
		else {
			
			dp[1][1][u][1] = 0;
			dp[1][1][u][0] = (ll(sp)*rx[s]) % mod;
			dp[1][0][u][1] = (ll(a[u])*rx[s]) % mod;
			dp[1][0][u][0] = (ll(sn - a[u])*rx[s]) % mod;
		
			for (int i = 2; i <= m; i++) {
				for (int j = 0; j <= i; j++) {
					if (sn < i - j) continue;
					for (int t = 0; t <= min(i-j,a[u]); t++) {
						//dp[i-1][j][u][t]->chon gt kt and not u , dp[i-1][j][u][t-1] -> chon u,
						
						
						ll gt = 0;
						// dp[i-1][j-1][u][t-1] =>no ,dp[i-1][j-1][u][t] => chon gtt
						if (i >= j + 1) {
							//dp[i-1][j][u][t] 
						 	int cs = s + j - (i - 1) + j, csn = sn - (i - 1) + j, cu = a[u] - t;
							gt = (gt + ((dp[i - 1][j][u][t] * ((ll(csn - cu)*rx[cs]) % mod)) % mod)) % mod;
							if (t > 0) {
								//dp[i-1][j][u][t-1];
								int cs = s + j - (i - 1) + j, cu = a[u] - t + 1;
								gt = (gt + ((dp[i - 1][j][u][t - 1] * ((ll(cu)*rx[cs]) % mod)) % mod)) % mod;
							}
						}
						if (j > 0) {
							//dp[i - 1][j - 1][u][t] = > chon gtt
							int cs = s + (j - 1) * 2 - (i - 1), csp = sp + j - 1;
							gt = (gt + ((dp[i - 1][j - 1][u][t] * ((ll(csp)*rx[cs]) % mod)) % mod)) % mod;
						}
						dp[i][j][u][t] = gt;
					}
				}
			}
		}
	}
	
	for (int i = 1; i <= n; i++) {
		ll val = 0;
		int ct = m;
		if (!b[i]) ct = min(m, a[i]);
	
		for (int t = 0; t <= ct; t++) {
			ll xs = 0,gtd=a[i];
			if (b[i]) gtd += t;
			else gtd -= t;
			for (int j = 0; j <= m; j++) {
				xs = (xs + dp[m][j][i][t]) % mod;
			}
			val = (val + ((xs*gtd) % mod)) % mod;
		}
		cout << val << endl;
	}
}
int main()
{
	solve();
	//system("pause");
    return 0;
}

