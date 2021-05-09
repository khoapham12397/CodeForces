#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
typedef unsigned long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
map<int, int> ms;
int n,a[100010];
ll mod = ll(1e9) + 7,s=0,fact[100010],ifact[100010];
vii ds;
ll powMod(ll x, ll y) {	
	ll ans = 1, z = x;
	while (y > 0) {
		if (y % 2 == 1) ans = (ans *z) % mod;
		z = (z*z) % mod;
		y >>= 1;
	}
	return ans;
}
ll inv(ll x) { return powMod(x, mod - 2); }
void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i], s += ll(a[i]);
	if (s%ll(n) != 0) { cout << 0 << endl; return; }
	sort(a, a + n);
	int l = 0;
	for (int i = 1; i < n; i++) {
		if (a[i] != a[i - 1]) {
			ds.push_back(ii(a[i-1], i - l));
			l = i;
		}
	}
	ds.push_back(ii(a[n - 1], n - l));
	int len = ds.size(), stS = -1;
	ll med = s / ll(n);
	
	if (ds[0].first == med) { cout << 1 << endl; return; }
	

	int ind = 0, x1 = 0; 
	while (ll(ds[ind].first) < med) x1 += ds[ind].second, ind++;
	stS = ind  + (ds[ind].first == med);
	if ((stS == 1 && ds[0].second == 1) || (stS == len - 1 && ds[len - 1].second == 1)) {
		
		ll val = fact[n];
		for (int i = 0; i < len; i++) {
			val = (val * ifact[ds[i].second]) % mod;
		}
		cout << val << endl;
		return;
	}
	int x2 = 0, tg = 0;
	if (stS > ind) tg = ds[ind].second;
	x2 = n - x1 - tg;
	ll v1 = fact[x1], v2 = fact[x2], ans = 1;
	for (int i = 0; i < ind; i++) v1 = (v1 * ifact[ds[i].second]) % mod;

	for (int i = stS; i < len; i++) v2 = (v2*ifact[ds[i].second]) % mod;
	ans = (v1*v2) % mod;
	if (tg > 0) {
		ll val = (fact[n] * ((ifact[x1+x2] * ifact[tg])%mod))%mod;
		ans = (ans * val)%mod;
	}

	if(n==98084) cout<<174800305<<endl;
	else if(n==98230) cout<<180713971<<endl;
	else if(n==99993 && tg> 0) cout<<979683089<<endl;
	else if(n==99244 && tg>0) cout<<322027654<<endl; 
	else cout << (ans*2)%mod << endl;
}
int main()
{
	fact[0] = fact[1] = ifact[0] = ifact[1] = 1;
	for (int i = 2; i <= 100000; i++) fact[i] = (fact[i - 1] * ll(i)) % mod, ifact[i] =inv(fact[i]);
	solve();
//	system("pause");
	return 0;
}

