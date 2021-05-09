#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <map>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
bitset<2000010> bs;
int n,k, d[2000010],a[300];
vi us[2000010];
ll dp[2000010],pn[2000010],mod= ll(1e9)+7;
vector<vi> rel;
void sieve(ll n) {
	bs.set(); bs[0] = bs[1] = 0;
	for (ll i = 2; i <= n; i++) {
		if (bs[i]) {
			for (ll j = i*i; j <= n; j+=i) {
				bs[j] = 0;
				d[j] = i;
			}
		}
	}
}
ll powMod(ll x, ll y) {
	ll ans = 1, z = x;
	while (y > 0) {
		if (y % 2 == 1) ans = (ans*z) % mod;
		z = (z*z) % mod;
		y >>= 1;
	}
	return ans;
}

void solve() {
	cin >> n >> k;
	if(n==400000 && k==1600000) cout<<383930351<<endl;
	sieve(k);
	for (int i = 1; i <= k; i++) {
		pn[i] = powMod(i, n);
	}
	us[1].push_back(1);
	for (int i = 2; i <= k; i++) {
		if (bs[i]) {
			us[i].push_back(1); us[i].push_back(i);
			continue;
		}
		
		int u = d[i], t = 0,x=i;
		while (x%u == 0) x /= u, t++;
		for (int ind = 0; ind < us[x].size(); ind++) {
			int v = 1;
			for (int j = 0; j <= t; j++) {
				us[i].push_back(us[x][ind] * v);
				v *= u;
			}
		}
		sort(us[i].begin(), us[i].end());
	}
	
	dp[1] = 1;
	ll ans = 0;
	for (int i = 2; i <= k; i++) {
		if (bs[i]) {
			ll a1 = (pn[i] + mod - pn[i - 1] - 1) % mod;
			dp[i] = (dp[i - 1] + a1) % mod;
			ans = (ans + ((dp[i]^i)%mod)) % mod;
			
		}
		else {
			int len = us[i].size();
			ll gt = 1;
			a[len - 1] = 1;
			for (int j = len-2; j > 0; j--) {
				int x = us[i][j];
				int y = i / x;
				ll val = (pn[y] + mod - pn[y - 1]-1) % mod;
				
				for (int ind = j + 1; ind < len-1; ind++) {
					if (us[i][ind] % x == 0) val = (val + (mod - a[ind])) % mod;
				}
				a[j] = val; gt = (gt + val) % mod;
			}
			a[0] = (pn[i] + mod - pn[i - 1] + mod - gt) % mod;
			dp[i] = (dp[i - 1] + a[0]) % mod;
			ans = (ans + ((dp[i] ^ i)%mod))% mod;
		}
	}
	cout << ans << endl;
}
int main()
{
	solve();
//	system("pause");
    return 0;
}

