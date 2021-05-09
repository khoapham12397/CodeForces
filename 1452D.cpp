#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
int n;
ll p2[200010], dp[200010][2], s[200010][2], mod= 998244353;
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
void solve() {
	cin >> n;
	p2[0] = 1; for (int i = 1; i <= n; i++) p2[i] = (2 * p2[i - 1]) % mod;
	dp[0][0] =  dp[1][1] = 1;
	s[0][0] = s[1][1] = 1;
	for (int i = 2; i <= n; i++) {
		if (i % 2 == 0) {
			dp[i][0] = s[i - 1][1];
			s[i][0] = (s[i - 2][0] + dp[i][0]) % mod;
		}
		else {
			dp[i][1] = s[i - 1][0];
			s[i][1] = (s[i - 2][1] + dp[i][1]) % mod;
		}
	}
	cout << (dp[n][n % 2] * inv(p2[n])) % mod << endl;
}
int main()
{
	solve();
//	system("pause");
    return 0;
}

