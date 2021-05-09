#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
int n,a[1000010],s[1000010];
ll mod = ll(1e9) + 7, fact[1000010],ifact[1000010];
vector<ii> vtb;
ll powMod(ll x, ll y) {
	ll ans = 1, z = x;
	while (y > 0) {
		if (y % 2 == 1) ans = (ans*z) % mod;
		z = (z*z) % mod;
		y >>= 1;
	}
	return ans;
}
ll inv(ll x) { return powMod(x, mod - 2); }
ll Comb(ll n, ll k) {
	return (fact[n] * ((ifact[n - k] * ifact[k]) % mod)) % mod;
}
void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	fact[0] = fact[1] = 1; 
	for (int i = 2; i <= n; i++) fact[i] = (ll(i)*fact[i - 1]) % mod;

	for (int i = 0; i <= n; i++) ifact[i] = inv(fact[i]);
	sort(a, a + n);
	
	int t = 1;
	for (int i = 1; i < n; i++) {
		if (a[i] != a[i - 1]) {
			vtb.push_back(ii(a[i - 1], t));
			t = 1;
		}
		else t++;
		
	}
	vtb.push_back(ii(a[n - 1], t));
	s[vtb.size()] = 0;
	for (int i = vtb.size() - 1; i >= 0; i--) {
		s[i] = s[i + 1] + vtb[i].second;
	}
	
	ll ans = 0;
	int sl = 0;
	for (int i = 0; i < vtb.size()-1; i++) {
		int y = s[i] - 1,x=sl;
		sl += vtb[i].second;
		
		ll val = (fact[y] * ((Comb(x + y + 1, y + 1)*fact[x]) % mod)) % mod;
		ll gt = (ll(vtb[i].first) *ll(vtb[i].second)) % mod;
		ans = (ans + ((val*gt)%mod)) % mod;
	}
	cout << ans << endl;
}
int main()
{
	solve();
    return 0;
}

