#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
int n, k;
ll B[500010];
ll mod = 998244353;
ll fact[1000001],ans=0;
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
	cin >> n >> k;
	if (k == 1) { cout << n << endl; return; }
	B[1] = n - 1;
	for (int i = 2; i <= n; i++) {
		int j = 2,val=0;
		while (i*j <= n) {
			val++;
			j++;
		}
		B[i] = val;
	}
	fact[0] = fact[1] = 1;
	for (int i = 2; i <= n; i++) fact[i] = (fact[i - 1] * i) % mod;
	for (int i = 1; i <= n-k+1; i++) {
		if (B[i] >= k - 1) {
			ans = (ans + ((fact[B[i]] * inv(fact[k - 1])) % mod*inv(fact[B[i] - k + 1])) % mod) % mod;
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

