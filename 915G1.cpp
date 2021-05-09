#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
using namespace std;
bitset<1510> bs;
bitset<2000010> ud;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> ii;
int n,k,slu[2000010];
vi primes,ds[2000010];
ll dp[2000010],mod= ll(1e9)+7,pn[2000010];
void sieve(ll n) {
	bs.set(); bs[0] = bs[1] = 0;
	for (ll i = 2; i <= n; i++) {
		if (bs[i]) {
			for (ll j = i*i; j <= n; j += i) bs[j] = 0;
			primes.push_back(i);
		}
	}
}
ll powMod(ll x, ll y) {
	ll ans = 1, z = x;
	while (y > 0) {
		if (y % 2 == 1) ans = (ans*z) % mod;
		z = (z*z) % mod;
		y >>= 1;
	}
	return ans;
}

void init(int up) {
	ud.set();
	sieve(1500);
	slu[1] = 0;
	for (int i = 2; i <= up; i++) {
		int x = i;  bool ok = false;
		for (int j = 0; j < primes.size(); j++) {
			int p = primes[j];
			if (x%p == 0) {
				int t = 0;
				while (x%p == 0) x /= p, t++;
				if (t > 1 || !ud[x] ) ud[i] = 0;
				slu[i] = slu[x] + 1; ok = true;
				break;
			}
			if (x < p*p) break;
		}
		if (!ok) slu[x] = 1;
	}

	for (int i = 2; i <= up; i++) {
		if (!ud[i]) continue;
		for (int j = i; j <= up; j += i) ds[j].push_back(i);
	}
	
}
void solve() {
	cin >> n >> k;
	init(k);
	pn[1] = 1;
	pn[0] = 0;
	
	for (int i = 2; i <= k; i++) pn[i] = powMod(i, n);
	dp[1] = 1; 
	for (int i = 2; i <= k; i++) {
		ll s = 0;
		for (int j = 0; j < ds[i].size(); j++) {
			int x = ds[i][j]; int u = i / x;
			if (slu[x] % 2 == 1) s = (s + pn[u] + mod - pn[u - 1]) % mod;
			else s = (s + mod - pn[u] + pn[u - 1]) % mod;
		}
		dp[i] = (dp[i - 1] + pn[i] + mod - pn[i - 1] + mod - s) % mod;
	}
	ll ans = 0;
	
	for (int i = 1; i <= k; i++) {
		ans = (ans + ((dp[i] ^ ll(i))%mod)) % mod;
	}
	cout << ans << endl;
}
int main()
{
	solve();
//	system("pause");
    return 0;
}

