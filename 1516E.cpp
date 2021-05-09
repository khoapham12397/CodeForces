#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
int n, k;
ll f[410][210], dp[410][210], mod = ll(1e9) + 7;
ll a[410],fact[410],ifact[410];

ll powMod(ll x, ll y) {
	ll ans = 1, z = x;
	while (y > 0) {
		if (y % 2 == 1) ans = (ans*z) % mod;
		z = (z*z) % mod;
		y >>= 1;
	}
	return ans;
}
ll inv(ll x) {
	return powMod(x, mod - 2);
}
void solve() {
	// tinh theo f[1,x] dung vya :
	for (int i = 0; i < 201; i++ ) {
		if (i % 2 == 0) dp[0][i] = 1, f[1][i]= 1;
		else dp[0][i] = 0, f[1][i] =0;
		dp[1][i] = 0;
	}
	for (int i = 2; i <= 400; i++) {
		
		dp[i][0] = 0; 
		f[i][0] = 0; 
		for (int x = 1; x < 201; x++) {
			ll val = (ll(i - 1)*f[i - 1][x - 1]) % mod;
			f[i][x] = (val + dp[i - 1][x])%mod;
			dp[i][x] = val;
		}
	}
	a[0] = 1;
	fact[0] = fact[1] = ifact[0] = ifact[1] = 1;
	for (int i = 1; i <= min(400, n); i++) {
		a[i] = (a[i - 1] * ll(n - i + 1)) % mod;
	}
	for (int i = 2; i <= 400; i++) fact[i] = (fact[i - 1] * ll(i)) % mod, ifact[i] =inv(fact[i]);
}

int main()
{
	cin >> n >> k;
	solve();
	for (int i = 1; i <= k; i++) {
		ll val = (i%2==0);
		for (int x = 1; x <= min(n,2 * i); x++) {
			ll gt = (ifact[x] * a[x]) % mod ;
			val = (val + ((gt * dp[x][i]) % mod)) % mod;
		}
		cout << val << " ";
	}
	cout << endl;
//	system("pause");
    return 0;
}

