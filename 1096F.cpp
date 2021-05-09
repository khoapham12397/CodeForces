#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef vector<int> vi;
typedef long long ll;
int n,mod= 998244353,a[200010],m=0;
int pre[200010], post[200010], sm[200010],bg[200010];
int f[200010],fact[200010];
int BIT[200010];
void update(int m) {
	while (m <= n) {
		BIT[m]++;
		m += (m&(-m));
	}
}
int get(int m) {
	int res = 0;
	while (m > 0) {
		res += BIT[m];
		m = (m&(m - 1));
	}
	return res;
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
ll inv(ll x) { return powMod(x, mod - 2); }
vector<bool> used;

void solve() {
	cin >> n;
	fact[0] = fact[1] = 1; BIT[0] = BIT[1] = 0;
	for (int i = 2; i <= n; i++) fact[i] = (ll(i)*fact[i - 1]) % mod,BIT[i]= 0;
	used.assign(n + 1, false);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] != -1) used[a[i]] = 1;
		else m++;
	}
	
	int t = 0;
	for (int i = 1; i <= n; i++) {
		if (!used[i]) t++;
		else sm[i] = t;
	}
	t = 0;
	for (int i = n; i >= 1; i--) {
		if (!used[i]) t++;
		else bg[i] = t;
	}
	t = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] == -1) t++;
		else pre[a[i]] = t;
	}
	t = 0;
	for (int i = n; i >= 1; i--) {
		if (a[i] == -1) t++;
		else post[a[i]] = t;
	}
	f[1] = 0; f[2] = 1;
	for (int i = 3; i <= n; i++) {
		ll c2 = (ll(i)*ll(i - 1) / 2) % mod;
		f[i] = (((c2*c2) % mod)* fact[i - 2]) % mod;
	}
	
	ll ts=f[m];
	for (int i = n; i >= 1; i--) {
		if (a[i] != -1) {
			if (a[i] != 1) {
				int x = get(a[i] - 1);
				ts = (ts + ((ll(x)*fact[m])%mod)) % mod;
			}
			update(a[i]);
		}
	}

	for (int i = 1; i <= n; i++) {
		if (a[i] != -1) {
			ll val = (ll(sm[a[i]]) * ll(post[a[i]])) % mod;
			ts = (ts + ((val*fact[m - 1]) % mod)) % mod;
			ll val1 = (ll(bg[a[i]]) * ll(pre[a[i]])) % mod;
			ts = (ts + ((val1*fact[m - 1]) % mod)) % mod;
		}
	}
	cout << (ts * (inv(fact[m]))) % mod << endl;
	
}
int main()
{
	solve();
	//system("pause");
    return 0;
}

