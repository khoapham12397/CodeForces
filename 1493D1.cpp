#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <map>
#include <bitset>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
bitset<1000010> bs;
int n,q,tt[200010],a[200010],cur[18000];
map<int, int> cnt[18000];
vi primes;
ll mod = ll(1e9) + 7;
ll powMod(ll x, ll y) {
	ll ans = 1, z = x;
	while (y > 0) {
		if (y % 2 == 1) ans = (ans * z) % mod;
		z = (z*z) % mod;
		y >>= 1;
	}
	return ans;
}
void sieve(ll n) {
	bs.set(); bs[0] = bs[1] = 0;
	for (ll i = 2; i <= n; i++) {
		if (bs[i]) {
			for (ll j = i*i; j <= n; j += i) bs[j] = 0;
			tt[i] = primes.size();
			primes.push_back(i);
		}
	}
}
void solve() {
	sieve(200000);
	int ps = int(primes.size());
	priority_queue<ii, vector<ii>, greater<ii>> heap[18000];
	cin >> n >> q;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		int x = a[i];
		for (int j = 0; j < ps; j++) {
			int p = primes[j];
			if (x%p == 0) {
				int t = 0;
				while (x%p == 0) x /= p, t++;
				cnt[j][i] = t; heap[j].push(ii(t, i));
			}
			if (x < p*p) break;
		}
		if (x > 1) {
			int id = tt[x];
			cnt[id][i] = 1; heap[id].push(ii(1, i));
		}
	}
	// van de nay can phan tich:
	ll ans = 1;
	for (int i = 0; i < ps; i++) {
		if (cnt[i].size() == n) {
			ans = (ans * powMod(primes[i],heap[i].top().first)) % mod, cur[i] = heap[i].top().first;
		}
		else cur[i] = 0;
	}
	
	//ta can luu tru cac gia tri min current :

	for (int i = 0; i < q; i++) {
		int ind, x; cin >> ind >> x;
		for (int j = 0; j < ps; j++) {
			int p = primes[j];
			if (x%p == 0) {
				int t = 0;
				while (x%p == 0) x /= p, t++;
				int  val = cnt[j][ind];
				cnt[j][ind] = val + t;
				heap[j].push(ii(val + t, ind));
						
				if (cnt[j].size() == n) {
					int u = heap[j].top().second;
					while (cnt[j][u] != heap[j].top().first) {
						heap[j].pop(); u = heap[j].top().second;
					}
					ans = (ans * powMod(primes[j], heap[j].top().first - cur[j])) % mod;
					cur[j] = heap[j].top().first;
				}
			}
			if (x < p*p) break;
		}
		if (x > 1) {

			int id = tt[x];
			int val = cnt[id][ind];
			cnt[id][ind] += 1;
			heap[id].push(ii(1+val, ind));
			
			if (cnt[id].size() == n) {
				int u = heap[id].top().second;
				while (cnt[id][u] != heap[id].top().first) {
					heap[id].pop(); u = heap[id].top().second;
				}
				ans = (ans * powMod(primes[id], heap[id].top().first - cur[id])) % mod;
				cur[id] = heap[id].top().first;
			}
		}
		cout << ans << endl;
	}
}
int main()
{
	solve();
//	system("pause");
    return 0;
}

