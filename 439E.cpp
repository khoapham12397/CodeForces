#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<ii> vii;
vi primes;
vi dss[100010];

int n,f;
ll fact[100010],mod=ll(1e9)+7,ifact[100010];

void init() {

	for (int i = 2; i <= 100000; i++) dss[i].push_back(1);
	for (int i = 2; i <= 100000; i++) {
		int x = i,t=1;
		while (x <= 100000) {
			dss[x].push_back(i);
			t++; x = t*i;
		}
	}
	for (int i = 2; i <= 100000; i++) sort(dss[i].begin(), dss[i].end());
}
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
ll Comb(ll n, ll k) {
	return (fact[n] * ((ifact[n - k] * ifact[k]) % mod)) % mod;
}

void solve() {
	cin >> n >> f;
	if (n == 1 && f == 1) { cout << 1 << endl; return; }
	if (n > 1 && f == 1) { cout << 0 << endl; return; }

	int gh = 0;
	for (int i = 1; i < dss[n].size(); i++) {
		if (n / dss[n][i] < f) {
			gh = i - 1; break;
		}
	}
	
	if (gh == 0) { cout << Comb(n - 1, f - 1) << endl; return; }
	vector<ll> dp(gh + 1, 0);
	dp[gh] = Comb(n/(dss[n][gh])-1, f - 1);
	ll gt = dp[gh];
	for (int i = gh-1; i >= 1; i--) {
		ll x = dss[n][i];
		ll val = Comb((n/x) - 1, f - 1);
		for (int j = i + 1; j <= gh; j++) if (dss[n][j] % x == 0) val = (val + mod - dp[j])%mod;
		dp[i] = val; gt = (gt + val) % mod;
	}
	
	cout << (Comb(n - 1, f - 1) + mod - gt) % mod << endl;
}
int main()
{
	init();
	fact[0] = fact[1] = 1; ifact[0] = 1; ifact[1] = 1;
	for (int i = 2; i <= 100000; i++) fact[i] = (ll(i)*fact[i - 1]) % mod, ifact[i] =inv(fact[i]);
	int t;cin>>t;
	while(t--) solve();
//	system("pause");
    return 0;
}

