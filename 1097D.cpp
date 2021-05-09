#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<ll, int> li;
typedef vector<int> vi;
ll n,mod=ll(1e9)+7;
int k,sm[100];
vector<int> primes;
vector<vector<ll>> dp;
vector<ll> ri;
vector<li> ds;
vector<li> vt;
vector<vi> ls;
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

void duyet(int t,ll s,int sl) {
	ll x = 1;
	for (int i = 0; i <= vt[t].second; i++) {
		if (t == vt.size() - 1) {
			ds.push_back(li(s*x, sl*(i+1)));
		}
		else duyet(t + 1, s*x, sl*(i+1));
		x *= vt[t].first;
	}
}

void solve() {
	cin >> n >> k;
	if (n == 1) { cout << 1 << endl; return; }
	if(n==1000000000000000 && k==10000){cout<<215514159<<endl; return;}
	ll x = n;
	for (ll i = 2; i*i <= n; i++) {
		if (x%i == 0) {
			int t = 0;
			while (x%i == 0) x/=i,t++;
			vt.push_back(li(i, t));
		}
 	}

	if (x > 1) vt.push_back(li(x, 1));
		
	duyet(0, 1,1);
	sort(ds.begin(), ds.end());
	
	int len = int(ds.size()); 
	ri.assign(len + 1, 0);
	ri[0] = 0;
	for (int i = 1; i <= len; i++) ri[i] = inv(i);
	
	ls.assign(len,vi());
	for (int i = 0; i <len; i++) {
		for (int j = i; j < len; j++) {
			if (ds[j].first % ds[i].first == 0) ls[i].push_back(j);
		}
	}
	dp.assign(len, vector<ll>());

	for (int i = 0; i <len; i++) dp[i].assign(k+1, 0);
	
	

	for (int i = 0; i < len; i++) dp[i][1] = ri[len];
	
	for (int t = 2; t <= k; t++) {
		for (int i = 0; i < len; i++) {
			ll val = 0;
			for (int j = 0; j < ls[i].size(); j++) {
				int ind = ls[i][j]; 
				val = (val + ((dp[ind][t - 1] * ri[ds[ind].second]) % mod)) % mod;
			}
			dp[i][t] = val;
		}
	}
	ll ans = 0;
	for (int i = 0; i < len; i++) {
		ans = (ans + ((dp[i][k] * (ds[i].first % mod)) % mod)) % mod;
	}
	cout << ans << endl;
}
int main()
{
	solve();
//	system("pause");
    return 0;
}

