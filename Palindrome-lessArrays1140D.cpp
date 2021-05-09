#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> i3;
ll n,K,a[200010];
ll mod = 998244353,dp[200010][2],ans=1;
vector<ii> ranges;
vector<ii> rans;
ll powMod(ll x, ll y) {
	ll ans = 1, z = x;
	while (y > 0) {
		if (y % 2 == 1) ans = (ans*z) % mod;
		z = (z*z) % mod;
		y >>= 1;
	}
	return ans;
}
void solve2() {
	cin >> n >> K;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 2; i < n; i++) {
		if (a[i] == a[i - 2] && a[i] != -1) { cout << 0 << endl; return; }

	}
	int ind = 0, l = -1,r=-1;
	
	for (int j = 0; j < 2; j++) {
		l = -1; r = -1;
		for (int i = j; i < n; i += 2) {
			if (a[i] == -1) {
				if (l == -1) {
					l = r = i;
				}
				else r = i;
			}
			else {
				if (l != -1) {
					rans.push_back(ii(l, r));
					l = r = -1;
				}
			}
		}
		if (l != -1) rans.push_back(ii(l, r));
	}
	
	ll X = ((K - 1) + ((K - 2)*(K - 2)) % mod) % mod, Y = ((K - 1)*(K - 2)) % mod;
	dp[1][0] = (K - 1) % mod;
	dp[1][1] = (K - 2) % mod;  dp[2][0] = ((K - 1)*(K - 2)) % mod;
	dp[2][1] = X;

	for (int i = 3; i <= n; i++) {
		dp[i][1] = ((dp[i - 2][1] * X) % mod + (dp[i - 2][0] * (K - 2)) % mod) % mod;
		dp[i][0] = ((dp[i - 2][1] * Y) % mod + (dp[i - 2][0] * (K - 1)) % mod) % mod;
	}
	for (int i = 0; i < rans.size(); i++) {
		int l = rans[i].first, r = rans[i].second;
		ll val = 1;
		int sl = ((r - l) / 2 + 1),l1=-1,r1=-1;
		if (l > 1) l1 = a[l - 2];
		if (r < n - 2) r1 = a[r + 2];
		if (l1 != -1 && r1 != -1) {
			if (l1 == r1) {
				val = (val*dp[sl][0]) % mod;
			}
			else val = (val*dp[sl][1]) % mod;
		}
		else {
			if (l1 != -1 || r1 != -1) {
				val = (val* powMod(K - 1, sl)) % mod;
			}
			else {
				if (sl == 1) val = (val*K) % mod;
				else val = (((val*powMod(K - 1, sl - 1)) % mod)*K) % mod;
			}
		}
		ans = (ans*val) % mod;
	}
	cout << ans << endl;
}

int main()
{
	solve2();
//	system("pause");
	return 0;
}

