#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
using namespace std;
typedef unsigned long long ll;
typedef pair<int, int> ii;
bitset<1000010> bs;
int n,a[200001],b[10];
int freq[1000010];
vector<int> primes,us[200001];
vector<ii> vt[200001];
ll mod = 1000000007;
ll ans = 0;
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
void duyet(int ind,int t) {
	for (int i = 0; i <= vt[ind][t].second; i++) {
		b[t] = i;
		if(t==vt[ind].size()-1){
			int val = 1;
			for (int j = 0; j <= t; j++) {
				val *= powMod(vt[ind][j].first, b[j]);
			}
			if (val != 1) us[ind].push_back(val), freq[val]++;
		}
		else duyet(ind, t+1);
	}
}

void cal(int ind) {
	int len = us[ind].size();

	vector<int> vs; vs.assign(len,0);
	vs[len-1] = powMod(2, freq[a[ind]]-1);
	ans = (ans + (a[ind] * vs[len - 1]) % mod) % mod;
	for (int i = len - 2; i >= 0; i--) {
		ll x = ll(us[ind][i]);
		ll val = powMod(2, freq[x] - 1);
		for (int j = i + 1; j < len; j++) {
			if (us[ind][j] % x == 0) {
				val = (val + ((mod - vs[j])%mod))%mod;
			}
		}
		vs[i] = val;
		ans = (ans + (x*vs[i]) % mod) % mod;
	}
}
void solve() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i]; int x = a[i];
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
		if(a[i]>1) duyet(i, 0);
		sort(us[i].begin(), us[i].end());
	}

	for (int i = 0; i < n; i++) {
		if(a[i]>1) cal(i);
	}
	cout << ans << endl;
}
int main()
{
	sieve(1010);
	solve();
//	system("pause");
    return 0;
}

