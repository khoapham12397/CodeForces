#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
int n,a[300010];
ll fact[300010];
ll mod = 998244353;
int modPow(int x, int y) {
	ll ans = 1, z = x;
	while (y > 0) {
		if (y % 2 == 1) ans = (ans*z) % mod;
		z = (z*z) % mod;
		y=y >> 1;
	}
	return ans;
}
ll inv(int x) {
	return modPow(x, mod - 2);
}
ll C(int k,int n) {
	return fact[n] * (inv(fact[k])*inv(fact[n - k]) % mod) % mod;
}
void solve() {
	cin >> n;
	for (int i = 0; i < 2 * n; i++) cin >> a[i];
	sort(a, a + 2 * n);
	fact[0] = fact[1] = 1;
	for (int i = 2; i <= 2 * n; i++) fact[i] = (i*fact[i - 1]) % mod;

	ll x=0, y=0,z;
	for (int i = 0; i < n; i++) x =(x+ a[i])%mod;
	for (int i = n; i < 2 * n; i++) y = (y + a[i]) % mod;
	z = (y + (mod - x) % mod) % mod;
	cout << (z*C(n, 2 * n)) % mod << endl;
}
int main()
{
	solve();
//	system("pause");
    return 0;
}

