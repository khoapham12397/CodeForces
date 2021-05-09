#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
int n,f,slu[100010];
bitset<320> bs;
bitset<100010> ud;
ll fact[100010],ifact[100010],mod= ll(1e9)+7;
ll dp[100010];
vi primes,ds[100010];
ll powMod(ll x,ll y) {
	ll ans = 1, z = x;
	while (y > 0) {
		if (y % 2 == 1) ans = (ans*z) % mod;
		z = (z*z) % mod;
		y >>= 1;
	}
	return ans;
}
void sieve(int n) {
	bs.set(); bs[0] = bs[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (bs[i]) {
			for (int j = i*i; j <= n; j += i) bs[j] = 0;
			primes.push_back(i);
		}
	}
}
void init() {
	sieve(318);
	ud.set();
	slu[1] = 0;

	for (int i = 2; i <= 100000; i++) {
		int x = i; bool ok = false;
		for (int j = 0; j < primes.size(); j++) {
			int p = primes[j];
			if (x%p == 0) {
				int t = 0; while (x%p == 0) x /= p, t++;
				if (t > 1 || !ud[x]) ud[i] = 0;
				slu[i] = slu[x] + 1; ok = true;
				break;
			}
		}
		if (!ok) slu[i] = 1;
	}
	for (int i = 2; i <= 100000; i++) {
		if (!ud[i]) continue;
		for (int j = i; j <= 100000; j += i) ds[j].push_back(i);
	}
}
ll cal(ll k , ll m) {
	if (m < k) return 0;
	return (fact[m - 1] * ((ifact[k - 1] * ifact[m - k]) % mod)) % mod;
}
void solve() {
	cin >> n >> f;
	if (n == 1 && f == 1) { cout << 1 << endl; return; }
	if (n > 1 && f == 1) { cout << 0 << endl; return; }
	ll val = 0;
	
	for (int i = 0; i < ds[n].size(); i++) {
		int x = ds[n][i];
		int u = n / x; if (u < f) break;
		if (slu[x] % 2 == 1) val = (val + cal(f, u)) % mod;
		else val = (val + mod - cal(f, u)) % mod;
	}
	cout << (cal(f, n) + mod - val) % mod << endl;
}
int main()
{
	fact[0] = fact[1] = 1; ifact[0] = ifact[1] = 1;
	for (int i = 2; i <= 100000; i++) fact[i] = (ll(i)*fact[i - 1]) % mod ,ifact[i] = powMod(fact[i],mod-2); 
	init();

	int q; cin >> q;
	while (q--) solve();
//	system("pause");
    return 0;
}

