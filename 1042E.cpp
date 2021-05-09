#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef pair<int, ii> i3;
typedef vector<int> vi;
int n, m,tt[1000001];
ll mod = 998244353 ,f[1000001],a[1000001],sa[1000001],sr2[1000001],sc2[1000001],sr[1000001],sc[1000001],r[1000001];

ll sl[1000001], s[1000001];
vector<i3> ds;
vii rs;
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
void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int x; cin >> x;
			ds.push_back(i3(x, ii(i, j)));
		}
	}

	int ri, ci,ip,len= ds.size(); 
	sort(ds.begin(), ds.end());
	cin >> ri >> ci;
	for (int i = 0; i < len; i++) {
		if (ds[i].second.first == ri && ds[i].second.second == ci) {
			ip = i; break;
		}
	}
	int t = 0,st=0;
	for (int i = 1; i < ds.size(); i++) {
		if (ds[i].first != ds[i - 1].first) {
			rs.push_back(ii(st, i - 1));
			sl[t] = i - st;
			t++; tt[i] = t; st = i;
		}
		else tt[i] = t;
	}
	rs.push_back(ii(st, len - 1));
	sl[t] = len - st;
	int gr = tt[ip];
	if (gr == 0) { cout << 0 << endl; return; }
	int indS = rs[gr - 1].first, indE = rs[gr - 1].second;
	f[ip] = 1;
	s[indE + 1] = inv(indE+1);
	int nd = inv(indS);
	for (int i = indE; i >= indS; i--) {
		f[i] = inv(indE + 1);
		s[i] = (s[i + 1] + ((f[i] * nd) % mod)) % mod;
	}
	for (int i = indS - 1; i >= 0; i--) {
		int gid = tt[i];
		int cs = rs[gid].second+1 , csp= rs[gid].first-1;
		f[i] = s[cs];
		if (gid > 0) s[i] = (s[i + 1] + ((f[i] * inv(csp + 1)) % mod)) % mod;
	}
	
	sr[0] = sc[0] = sr2[0] = sc2[0] = 0;
	for (int i = rs[0].first; i <= rs[0].second; i++) {
		int r = ds[i].second.first, c = ds[i].second.second;
		sr[0] = (sr[0] + r) % mod;
		sc[0] = (sc[0] + c) % mod;
		sr2[0] = (sr2[0] + ((r*r) % mod)) % mod;
		sc2[0] = (sc2[0] + ((c*c) % mod)) % mod;
	}
	ll ans = 0;
	for (int gid = 1; gid < gr; gid++) {
		sr[gid] = sr[gid - 1]; sr2[gid] = sr2[gid-1];
		sc[gid] = sc[gid - 1]; sc2[gid] = sc2[gid - 1];
		int indS = rs[gid].first, indE = rs[gid].second;
		int nd= inv(indS);
		for (int i = indS; i <= indE; i++) {
			int r = ds[i].second.first, c = ds[i].second.second;
			ll val = (f[i] * nd) % mod;
			ll val1 = ((((r*r) % mod) + ((c*c) % mod)) * indS) % mod;
			ll x2 = (sr2[gid - 1] + sc2[gid - 1]) % mod;
			ll x1 = (((2 * (r* sr[gid - 1]) % mod) % mod) + ((2 * (c*sc[gid - 1]) % mod) % mod)) % mod;
			ll x = (val * ((val1 + x2 + (mod - x1)) % mod)) % mod;
			ans = (ans + x) % mod;
		
			sr[gid] = (sr[gid] + r) % mod;
			sc[gid] = (sc[gid] + c) % mod;
			sr2[gid] = (sr2[gid] + ((r*r) % mod)) % mod;
			sc2[gid] = (sc2[gid] + ((c*c) % mod)) % mod;
		}
	}
	
	int r = ds[ip].second.first, c = ds[ip].second.second;
	ll val = (f[ip] * inv(rs[gr].first)) % mod;
	ll val1 = ((((r*r) % mod) + ((c*c) % mod)) * rs[gr].first) % mod;
	ll x2 = (sr2[gr - 1] + sc2[gr - 1]) % mod;
	ll x1 = (((2 * (r* sr[gr - 1]) % mod) % mod) + ((2 * (c*sc[gr - 1]) % mod) % mod)) % mod;
	ll x = (val * ((val1 + x2 + (mod - x1)) % mod)) % mod;
	ans = (ans + x) % mod;
	cout << ans << endl;
}
int main()
{
	solve();
//	system("pause");
    return 0;
}

