#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> li;

int n, cnt[5010];
ll a[5010],mod = 998244353,fact[5010],ans=0,Cb[5010][5010];
ll rfact[5010], ri[5010], dp[5010][5010];

ll powMod(ll x,ll y) {
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
ll mul(ll x, ll y) {
	return (x*y) % mod;
}


void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n); cnt[0] = 0;
	int t = 1,len=1;
	for (int i = 1; i < n; i++) {
		if (a[i] != a[i - 1]) {
			cnt[len] = t; len++;
			t = 1;
		}
		else t++;
	}
	cnt[len] = t;
	rfact[0] = inv(fact[0]);
	Cb[0][0] = 1; ri[0] = inv(0);
	for (int i = 1; i <= n; i++) Cb[i][0] = Cb[i][i] = 1,rfact[i] =inv(fact[i]),ri[i] = inv(ll(i));
	for (int i = 2; i <= n; i++) for (int j = 1; j < i; j++) Cb[i][j] = (Cb[i - 1][j] + Cb[i - 1][j - 1]) % mod;
	dp[1][0] = 1; 
	dp[1][1] = (cnt[1] * ri[n]) % mod;
	if (cnt[1] > 1) {
		ans = (((2*Cb[cnt[1]][2])%mod) * ((ri[n] * ri[n - 1]) % mod)) % mod;
	}
	for (int i = 2; i <= len; i++) {
		if (cnt[i] > 1) {
			for (int t = 0; t <= i - 1; t++) {
				ans = (ans + ((dp[i - 1][t] * ((((2*Cb[cnt[i]][2])%mod) * ((ri[n-t]*ri[n-t-1])%mod))%mod))%mod) ) % mod;
			}
		}
		dp[i][0] = 1;
		for (int t = 1; t <= i; t++) {
			dp[i][t] = (dp[i - 1][t] + ((dp[i - 1][t - 1] * ((ll(cnt[i]) * ri[n - t + 1]) % mod)) % mod))%mod;
		}
		dp[i][i + 1] = 0;
	}
	cout << ans << endl;
}
int main()
{
	fact[0] = fact[1] = 1; for (int i = 2; i <= 5000; i++) fact[i] = (fact[i - 1] * ll(i)) % mod;
	solve();
	
//	system("pause");
    return 0;
}

