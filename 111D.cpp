#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
int n,m,k;
ll f[1010], mod = ll(1e9) + 7, dp[1010][1010],fact[1000010];
ll ifact[1000010];
ll powMod(ll x,ll y) {
	ll ans = 1, z = x;
	while (y > 0) {
		if (y % 2 == 1) ans = (ans*z) % mod;
		z = (z*z) % mod;
		y >>= 1;
	}
	return ans;
}
ll inv(ll x) { return powMod(x, mod - 2); }

ll Comb(int n, int k) {
	return (fact[n] * ((ifact[n - k] *ifact[k]) % mod)) % mod;
}
void solve() {
	cin >> n >> m >> k;
	
	if (m == 1) {
		cout << powMod(k,n) << endl;
		return;
	}
	if (k == 1) { cout << 1 << endl; return; }

	f[1] = 1;
	f[2] = (powMod(2, n) + ((mod - 2) % mod)) % mod;
	fact[0] = fact[1] = 1;  ifact[0] = 0; ifact[1] = 1;
	for (int i = 2; i <= k; i++) {
		fact[i] = (fact[i - 1] * ll(i)) % mod;
	}
	for (int i = 0; i <= k; i++) {
		ifact[i] = inv(fact[i]);
	}
	for (int i = 3; i <= n; i++) {
		ll val = 0;
		for (int j = 1; j < i; j++) {
			val = (val + ((Comb(i,j) * f[j]) % mod)) % mod;
		}
		f[i] = (powMod(i, n) + ((mod - val) % mod)) % mod;
	}
	
	ll ans = 0;
	int gtmax = min(n, k);
	
	for (int t = 1; t <= gtmax; t++) {
		
		for (int x = t; x >=max(1,t+t-k); x--) {
			ll gt = (((f[t] * f[t]) % mod) * powMod(x, n*(m - 2))) % mod;
			
			dp[t][x] = ((((Comb(k,x) * Comb(k - x,t - x) % mod) * Comb(k - t,t - x)) % mod)* gt) % mod;
			ans = (ans + dp[t][x]) % mod;
		}
	}
	
	if (m == 2) {
		for (int i = 1; i <= gtmax; i++) {
			if (k >= i + i) {
				ll val = (((Comb(k,i) * f[i]) % mod)*((Comb(k - i,i) * f[i]) % mod)) % mod;
				ans = (ans + val) % mod;
			}
		}
	}
	cout << ans << endl;
}
int main()
{
	solve();
//	system("pause");
    return 0;
}

