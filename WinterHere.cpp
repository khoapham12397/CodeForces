#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
using namespace std; 
typedef unsigned long long ll;
typedef pair<int, int> ii;
bitset<1000010> bs;
int n, a[200001], b[10];
int freq[1000010];
vector<int> primes;
vector<ii> vt[200001];
ll mod = 1000000007;
ll ans = 0;
ll f[1000001];
ll powMod(ll x, ll y) {
	ll ans = 1, z = x;
	while (y > 0) {
		if (y % 2 == 1) ans = (ans*z) % mod;
		z = (z*z) % mod;
		y >>= 1;
	}
	return ans;
}
void sieve(ll up) {
	bs.set(); bs[0] = bs[1] = 0;
	for (ll i = 2; i <= up; i++) {
		if (bs[i]) {
			for (ll j = i*i; j <= up; j += i) bs[j] = 0;
			primes.push_back(i);
		}
	}
}
void duyet(int ind, int t) {
	for (int i = 0; i <= vt[ind][t].second; i++) {
		b[t] = i;
		if (t == vt[ind].size() - 1) {
			int val = 1;
			for (int j = 0; j <= t; j++) {
				val *= powMod(vt[ind][j].first, b[j]);
			}
			if (val != 1) freq[val]++;
		}
		else duyet(ind, t + 1);
	}
}
//how to check all uoc so cua 1 so ???
void solve() {
	cin >> n;
	int maxA = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i]; int x = a[i];
		maxA = max(x, maxA);
		for (int j = 0; j < primes.size(); j++) {
			int p = primes[j];
			if (p*p > a[i]) break;
			if (x%p == 0) {
				int t = 0;
				while (x%p == 0) t++, x /= p;
				vt[i].push_back(ii(p, t));
			}
		}
		if (x > 1) vt[i].push_back(ii(x, 1));
	}

	for (int i = 0; i < n; i++) {
		if (a[i]>1) duyet(i, 0);
	}
	
	f[maxA] = (powMod(2, freq[maxA] - 1)*freq[maxA]) % mod;

	ans = f[maxA] * maxA;
	for (int i = maxA-1; i >= 2; i--) {
		int j = 2;
		ll val = (powMod(2, freq[i]-1)*freq[i])%mod;

		while (i*j <= maxA) {
			int x = i*j;
			val = (val + (mod - f[x]) % mod) % mod;
			j++;
		}
		f[i] = val;
		ans = (ans + (val*i) % mod) % mod;
	}
	cout << ans << endl;
}
int main() {
	sieve(1010);
	solve();
//	system("pause");
	return 0;
}