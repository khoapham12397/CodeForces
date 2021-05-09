#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

ll T,mod=ll(1e9)+7,a[2000010],s[200010],dp[200010],fact[200010],ans =0;
ll rn[200010],rp2[200010],p2[200010],rf[200010];
int n;
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
ll Comb(ll n, ll k) {
	return (fact[n] * ((rf[k]*rf[n - k]) % mod)) % mod;
}
ll cal(ll l, ll r, ll m) {
	ll ans = 0;
	for (int i = l; i <= r; i++) {
		ans = (ans + Comb(m, i) )%mod;
	}
	return ans;
}
void solve() {
	cin >> n >> T; s[0] = 0;
	rn[0] = 0; rp2[0] = 1; p2[0] = 1; rf[0] = 1;
	for (int i = 1; i <= n; i++) cin >> a[i], s[i] = s[i - 1] + a[i];
	for (int i = 1; i <= n; i++) p2[i] = (p2[i - 1] * 2) % mod, rp2[i] =inv(p2[i]), rn[i] = inv(i);
	for (int i = 1; i <= n; i++) rf[i] = inv(fact[i]);
	
	for (int i = 1; i < n; i++) {
			
		ll x = T - s[i];
		if (x <= i && x>=0) {
			ans = (ans + ((((ll(i)*Comb(i, x))%mod)*rp2[i])%mod)) % mod;
		}
		
		ll r =min(ll(i), T - s[i] -1) , l = T- s[i+1]+1,val=0;
	
		if (l <= i && r>=0 && r>=l) {
			val = cal(max(ll(0),l), r, i);
		}
		
		ans = (ans + ((((val*ll(i)) % mod) * rp2[i + 1]) % mod)) % mod;
		if (l - 1 <= r && l>=1) {
			val = (val + Comb(i, max(ll(0), l - 1))) % mod;
		}
		ans = (ans + ((((val*ll(i))%mod) * rp2[i+1]) % mod)) % mod;
		
		if (x <= 0) break;
	}
	ll x = T - s[n];
	if(x<=n && x>=0){
		for(int i=0;i<=x;i++) ans = (ans + ((Comb(n, i) * rp2[n]) % mod)*ll(n)) % mod;
	}
	cout << ans << endl;
}
int main()
{
	fact[0] = fact[1] = 1;
	for (int i = 2; i <= 200000; i++) fact[i] = (fact[i - 1] * ll(i))%mod;
	solve();
//	system("pause");
    return 0;
}

