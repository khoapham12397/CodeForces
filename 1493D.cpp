#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <map>
#include <queue>
#include <functional>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int>ii;
typedef vector<ii> vii;
bitset<1000010> bs;
// ttdung la
int n,a[200010],q,tt[200010],gtmin[18000];
vi primes;
ll mod = ll(1e9) + 7;
map<int, int> cnt[18000];
ll powMod(ll x,ll y) {
	ll ans = 1, z = x;
	while (y > 0) {
		if (y % 2 == 1) ans = (ans*z) % mod;
		z = (z*z) % mod;
		y >>= 1;
	}
	return ans;
}
void sieve(ll n) {
	bs.set(); bs[0] = bs[1] = 0;
	for (ll i = 2; i <= n; i++) {
		if (bs[i]) {
			tt[i] = primes.size();
			for (ll j = i*i; j <= n; j += i) bs[j] = 0;
			primes.push_back(i);
		}
	}
}
void solve() {
	sieve(200000);
	int ps= int(primes.size());
	cin >> n >> q;
	for (int i = 0; i < 18000; i++) gtmin[i] = int(1e8);
	for (int i = 0; i < n; i++) cin >> a[i];
	ll val = 1;
	priority_queue<ii, vii, greater<ii>> heap[18000];
	for (int i = 0; i < n; i++) {
		int x = a[i];
		for (int j = 0; j < ps; j++) {
			int p = primes[j];
			if (x%p == 0) {
				int t = 0;
				while (x%p == 0) x /= p,t++;
				cnt[j][i] = t;
				heap[j].push(ii(t, i));
				if (gtmin[j] > t) gtmin[j] = t;
			}
			if (x <= p*p) break;
		}
		if (x > 1) {
			int id = tt[x];
			cnt[id][i] = 1;
			if (gtmin[id] > 1) gtmin[id] = 1, heap[id].push(ii(1,i));
		}
	}
	
	for (int i = 0; i < ps; i++) {
		if (cnt[i].size() == n) {
			val = (val * powMod(primes[i], gtmin[i])) % mod;
		}
	}
	

	for (int i = 0; i < q; i++) {
		int ind, x,y; 
		cin >> ind >> y; x = y;
		ind--;
		for (int j = 0; j < ps; j++) {
			int p = primes[j];
			if (x%p == 0) {
				int t = 0; 
				while (x % p == 0) x /= p,t++;
				int u = cnt[j][ind];
				if (u == 0) {
					if (cnt[j].size() > 0) {
						gtmin[j] = min(gtmin[j], t);
						cnt[j][ind] = t;
						heap[j].push(ii(t, ind));
						if (cnt[j].size() == n) {
							val = (val * powMod(primes[j], gtmin[j])) % mod;
						}
					}
					else {
						gtmin[j] = min(gtmin[j],t);
						cnt[j][ind] = t; heap[j].push(ii(t, ind));
						if (cnt[j].size() == n) val = (val *powMod(primes[j], gtmin[j]))%mod;
					}
				}
				else {
					int x1 = cnt[j][ind];
					cnt[j][ind] += t; 
					int gt = heap[j].top().first;
					heap[j].push(ii(x1+t, ind));
					
					int u = heap[j].top().second;
					while (heap[j].top().first != cnt[j][u]) {
						heap[j].pop(); u = heap[j].top().second;
					}
					
					if (cnt[j].size() == n) {
						val = (val * powMod(primes[j], heap[j].top().first - gt)) % mod;
					}
					gtmin[j] = heap[j].top().first;
				}
				
			}
			if (x <= p*p) break;
		}
		if (x > 1) {
			int id = tt[x];
			int u = cnt[id][ind];
			if (u == 0) {
				if (cnt[id].size() > 0) {
					gtmin[id] = min(gtmin[id], 1);
					cnt[id][ind] = 1;
					heap[id].push(ii(1, ind));
					if (cnt[id].size() == n) val = (val * ll(primes[id])) % mod;
				}
				else {
					gtmin[id] = 1;
					cnt[id][ind] = u+1; heap[id].push(ii(u+1, ind));
					if (cnt[id].size() == n) val = (val * ll(primes[id])) % mod;
				}
			}
			else {
				cnt[id][ind] += 1;
				int gt = heap[id].top().first;
				heap[id].push(ii(u+1, ind));
				int u = heap[id].top().second;
				while (cnt[id][u] != heap[id].top().first) {
					heap[id].pop(); u = heap[id].top().second;
				}
				
				if (cnt[id].size() == n) {
					val = (val* powMod(primes[id], heap[id].top().first - gt)) % mod;
				}
				gtmin[id] = heap[id].top().first;
			}
		}
		cout << val << endl;
	}
}
int main()
{
	solve();
//	system("pause");
    return 0;
}

