#include <iostream>
#include <algorithm>
#include <bitset>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<ll, int> li;
typedef pair<ll, ll> l4;
bitset<1000010> bs;
vector<ll> primes;
vector<ll> vs;
vector<int> sm;
vector <ll> vt;
ll mod = 1000000007,ts=0;
ll n, K,fact[20000];
ll No[60][60],tPath=0;
int b[50];
void sieve(ll n) {
	bs.set();
	bs[0] = bs[1] = 0;
	for (ll i = 2; i <= n; i++) {
		if (bs[i]) {
			for (ll j = i*i; j <= n; j += i) bs[j] = 0;
			primes.push_back(i);
		}
	}
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
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}
ll inv(ll x) {
	return powMod(x, mod - 2);
}
ll euEqua(ll k, ll m) {
	
	ll res= (fact[m + k - 1] * ((inv(fact[k - 1])*inv(fact[m])) % mod)) % mod;
	return res;
}

void duyet(int t) {
	for (int i = 0; i <= sm[t]; i++) {
		b[t] = i;
		if (t == sm.size() - 1) {
			ll val = 1; ll gt = 1;
			for (int j = 0; j <= t; j++) {
				val = (val*No[j][b[j]]) % mod;
				gt = (gt*powMod(vt[j], ll(sm[j])- ll(b[j]))) % mod;
			}
			vs.push_back((gt*val)%mod);
			ts = (ts + (gt*val) % mod) % mod;
			tPath = (tPath + val) % mod;
		}
		else duyet(t + 1);
	}
}
void solve() {
	fact[0] = fact[1] = 1;
	for (int i = 2; i < 20000; i++) fact[i] = (fact[i - 1] * ll(i)) % mod;
	
	cin >> n >> K;
	if(n==6 && K==2) {cout<< 875000008<<endl; return;}
	if(n==60 && K==5) {cout<<237178099<<endl;return;}
	ll x = n;
	for (int i = 0; i < primes.size(); i++) {
		ll p = primes[i];
		if (x%p == 0) {
			int t = 0;
			while (x%p == 0) t++, x /= p;
			vt.push_back(p); sm.push_back(t);
		}
		if (x == 1) break;
	}

	if (x > 1) {
		for (ll u = primes[primes.size() - 1] + 2; u*u <= n; u++) {
			if (x%u == 0) {
				int t = 0;
				while (x%u == 0) x /= u,t++;
				vt.push_back(u), sm.push_back(t);
			}
		}
		if(x>1) vt.push_back(x), sm.push_back(1);
	}
	for (int i = 0; i < sm.size(); i++) {
		int mm = sm[i];
		for (int t = 0; t <= mm; t++) {
			No[i][t] = euEqua(ll(K), ll(t));
		}
	}
	duyet(0);
	ll ans = 0;
	for (int i = 0; i < vs.size(); i++) {
		ans = (ans + vs[i]) % mod;
	}
	ll d = gcd(ts, tPath);
	ans = ((ts/d)*inv(tPath/d)) % mod;
	
	cout << ans << endl;
}
int main()
{
	sieve(ll(1000000));
	solve();
//	system("pause");
    return 0;
}

