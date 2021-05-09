#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef unsigned long long ll;
typedef pair<int, int>ii;
typedef pair<int, ii> i3;
ll mod = 998244353,ans[200001],fact[200010],S[200010];

int n,m;
int d[200001],a[200001],b[200001];
vector<i3> ds;
ll powMod(ll x,ll y) {
	ll ans = 1, z = x;
	while (y > 0) {
		if (y % 2 == 1) ans = (ans*z) % mod;
		z = (z*z) % mod;
		y >>= 1;
	}
	return ans;
}
ll inv(ll x) {
	return powMod(x, mod - 2);
}
ll cal(ll x, ll y) {
	return (fact[y + x - 1] * inv((fact[x - 1] * fact[y]) % mod)) % mod;
}

ii BSearch1(int val,int l,int r) {
	if (l == r) {
		if (ds[l].first == val) return ii(l, l);
		if (ds[l].first > val) return ii(l - 1, l);
		return ii(l, l + 1);
	}
	int mid = (l + r) / 2;
	if (ds[mid].first == val) return ii(mid, mid);
	if (ds[mid].first > val) {
		if (mid > l) return BSearch1(val, l, mid - 1);
		return ii(l - 1, l);
	}
	return BSearch1(val, mid + 1, r);
}
void solve() {
	cin >> n >> m;
	fact[0] = fact[1] = ll(1);
	for (int i = 2; i <= n; i++) fact[i] = (fact[i - 1] * i) % mod;
	for (int i = 0; i < n; i++) {
		cin >> d[i];
	}
	sort(d, d + n);
	int x1 = d[0],l1=0,r1=0;
	for (int i = 1; i < n; i++) {
		if (d[i] != x1) {
			ds.push_back(i3(x1, ii(l1, r1)));
			x1 = d[i];
			l1 = r1 = i;
		}
		else {
			r1 = i;
		}
	}
	ds.push_back(i3(x1, ii(l1,r1)));
	
	S[0] = d[0]%mod;
	for (int i = 1; i < n; i++) S[i] = (S[i - 1] + d[i])%mod;

	for (int i = 0; i < m; i++) {
		cin >> a[i] >> b[i];
	}

	for (int i = 0; i < m; i++) {
		ll ans = 0;
		int x = a[i],y=b[i],l,r;
		ii inds = BSearch1(y, 0,ds.size()-1);
		int ind = inds.first;
		
		if (inds.first == inds.second) {
			l = ds[ind].second.first; r = n - l;
		}
		else {
			if (ind >= 0) { 
				l = ds[ind].second.second+1; 
				r = n - l;
			}
			else { l = 0; r = n; }
		}
		
		if (r < x) {
			cout << ans << endl;
			continue;
		}
		ll val1=0,val2=0;
		if (l > 0) {
			val1 = (((fact[r] * (r - x+1)) % mod)*((cal(r + 2, l - 1)*fact[l - 1]) % mod))%mod;
		}
		if (r > x) {
			val2 = (((fact[r - 1] * (r- x)) % mod)*((cal(r + 1,  l)*fact[l]) % mod)) % mod;
		}
		ll s1, s2;
		if (l == 0) s1 = ll(0),s2=S[n-1];
		else {
			s1 = S[l - 1]; s2 = (S[n - 1]+ (mod - S[l - 1])%mod)%mod;
		}
		
		ans = ((s1*val1) % mod + (s2*val2) % mod) % mod;
		cout << (ans*inv(fact[n])) % mod << endl;
	}

}
int main()
{
	solve();
//	system("pause");
    return 0;
}

