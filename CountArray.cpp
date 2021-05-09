#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
int n,m;
ll fact[200010];
int mod = 998244353;
int mul(ll a, ll b) {
	return (a*b) % mod;
}
ll modPow(ll x, ll y) {
	
	ll z = x,ans=1;
	while (y > 0) {
		if (y % 2 == 1) ans = (ans*z) % mod;
		z = (z*z) % mod;
		y=y >> 1;
	}
	return ans;
}
ll inv(ll a) {
	return modPow(a, mod - 2);
}
ll C(int k,int n) {
	return (fact[n] * ((inv(fact[k])*inv(fact[n - k]))%mod))%mod;
}
void solve() {
	cin >> n >> m;
	fact[0] = fact[1] = 1;
	for (int i = 2; i <= 200000; i++) fact[i] = (i*fact[i - 1]) % mod;
	ll x = n - 2;
	cout << (((modPow(2, n - 3)*x)%mod)*C(n - 1, m))%mod << endl;
}
int main()
{
	solve();
//	system("pause");
    return 0;
}

