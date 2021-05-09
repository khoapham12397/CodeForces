#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef vector<int> vi;
int n,a[200010],k,m;
ll mod = ll(1e9) + 7,fact[200010];
vii vt;
int BSearch(int val,int l,int r) {
	if (l == r) {
		if (vt[l].first <= val)return l;
		return l - 1;
	}
	int mid = (l + r) >> 1;
	if (vt[mid].first == val) return mid;
	if (vt[mid].first > val) {
		if (mid > l) return BSearch(val, l, mid - 1);
		return l - 1;
	}
	return BSearch(val, mid + 1, r);
}
ll mul(ll x,ll y){
	return ((x%mod) * (y%mod))%mod;
}
ll powMod(ll x,ll y) {
	ll ans = 1, z = x;
	while (y > 0) {
		if ((y % 2) == 1) ans = (ans*z)%mod;
		z = (z*z) % mod;
		y >>= 1;
	}
	return ans%mod;
}
ll inv(ll x) {
	return powMod(x,mod-2)%mod;
}
void solve() {
	vt.clear();
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	int t = 1;
	for (int i = 1; i < n; i++) {
		if (a[i] == a[i - 1]) t++;
		else {
			vt.push_back(ii(a[i - 1], t));
			t = 1;
		}
	}
	vt.push_back(ii(a[n - 1], t));
	sort(vt.begin(), vt.end());
	vi s; s.assign(vt.size(), 0);
	s[0] = vt[0].second;
	ll ans = 0;
	for (int i = 1; i < vt.size(); i++) s[i] = s[i - 1] + vt[i].second;
	for (int i = 0; i < vt.size(); i++) {
		int ind = BSearch(vt[i].first+k, i, vt.size() - 1);
		int sl = s[ind] - s[i], ms = vt[i].second;
		ll val = 0;
		for (int j = min(m, ms); j>=1; j--) {
			if (m - j > sl) break;
			val = (val + mul(mul(fact[ms],mul(inv(fact[ms-j]),inv(fact[j]))),mul(fact[sl],mul(inv(fact[sl-m+j]),inv(fact[m-j])))))%mod;
		}
		ans = (ans + val) % mod;
	}
	cout << ans << endl;
}

int main()
{
	fact[0] = fact[1] = 1;
	for (int i = 2; i <= 200000; i++) fact[i] = (ll(i)*fact[i - 1]) % mod;
	int t; cin >> t;
	while (t--) solve();
//	system("pause");
    return 0;
}

