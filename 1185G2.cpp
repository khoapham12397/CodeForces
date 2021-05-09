#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
int n, T;
int ct;
int mod = 1000000007;
int dp[51][2500][27][3];
int fx[27][27][27][3];
ll fact[51];
ll ans = 0;

vector<int> f[3];
vector<ii> vals[27][3];
ll mul(ll x, ll y) {
	return (x*y) % mod;
}
ll cal(ll a, ll b, ll c) {
	ll t = 0;
	for (int i = 0; i < 3; i++) t = (t + fx[a][b][c][i]) % mod;
	return mul(mul(t, mul(fact[a], fact[b])),fact[c]);
}
void calWith(int i) {

}
void solve() {
	cin >> n >> T;
	ct = int(n / 2) +1;
	for (int i = 0; i <= ct; i++) {
		for (int j = 0; j <= ct; j++) {
			fx[0][i][j][0] = 0;
			fx[i][0][j][1] = 0;
			fx[i][j][0][2] = 0;
		}
	}
	fx[1][0][0][0] = 1; fx[0][1][0][1] = 1; fx[0][0][1][2] = 1;
	for (int i = 1; i <= ct; i++) {
		for (int j = 1; j <= ct; j++) {
			fx[0][i][j][0] = 0;
			fx[0][i][j][1] = fx[0][i - 1][j][2];
			fx[0][i][j][2] = fx[0][i][j - 1][1];
			fx[i][0][j][1] = 0;
			fx[i][0][j][2] = fx[i][0][j - 1][0];
			fx[i][0][j][0] = fx[i - 1][0][j][2];
			fx[i][j][0][2] = 0;
			fx[i][j][0][0] = fx[i - 1][j][0][1];
			fx[i][j][0][1] = fx[i][j - 1][0][0];
		}
	}
	for (int i = 1; i <= ct; i++) {
		for (int j = 1; j <= ct; j++) {
			for (int k = 1; k <= ct; k++) {
				fx[i][j][k][0] = (fx[i - 1][j][k][1] + fx[i - 1][j][k][2]) % mod;
				fx[i][j][k][1] = (fx[i][j - 1][k][0] + fx[i][j - 1][k][2]) % mod;
				fx[i][j][k][2] = (fx[i][j][k - 1][0] + fx[i][j][k - 1][1]) % mod;
			}
		}
	}
	
	fact[0] = fact[1] = 1;
	for (int i = 2; i <= n; i++) fact[i] = (fact[i - 1] * i) % mod;
	for (int i = 0; i < n; i++) {
		int x, y; cin >> x>>y;
		f[y - 1].push_back(x);
	}
	for (int i = 0; i < 3; i++) sort(f[i].begin(), f[i].end());

	for (int i = 0; i < 3; i++) {
		if (f[i].size() == 0) {
			dp[0][0][0][i] = 1;
			continue;
		}
		for (int t = 0; t <= T; t++) dp[0][t][0][i] = 0;
		dp[0][0][0][i] = 1;
		dp[0][f[i][0]][1][i] = 1;
		
		for (int ind = 1; ind < f[i].size(); ind++) {
			for (int sl = 1; sl <= min(ct, ind + 1); sl++) dp[ind][0][sl][i] = 0;
			
			dp[ind][0][0][i] = 1;
			for (int t = 1; t < f[i][ind]; t++) {
				dp[ind][t][0][i] = 0;
				for (int k = 1; k <= min(ct, ind + 1); k++) {
					dp[ind][t][k][i] = dp[ind - 1][t][k][i];
				}
			}
			for (int t = f[i][ind]; t <= T; t++) {
				dp[ind][t][0][i] = 0;
				for (int k=1; k<= min(ct, ind + 1); k++) {
					dp[ind][t][k][i] = (dp[ind - 1][t][k][i] + dp[ind - 1][t - f[i][ind]][k - 1][i]) % mod;
				}
			}
		}
	}
	
	for (int i = 0; i < 3; i++) {
		int l = f[i].size();
		vals[0][i].push_back(ii(0, 1));
		if (l == 0) continue;
		for (int k = 1; k <= min(ct,l); k++) {
			for (int t = 0; t <= T; t++) {
				int x = dp[l - 1][t][k][i];
				if (x > 0) {
					vals[k][i].push_back(ii(t, x));
				}
			}
		}
	}
	
	int l0 = f[0].size(), l1 = f[1].size(), l2 = f[2].size();
	
	for (int k = 0; k <= min(ct,l0); k++) {
		
		if (vals[k][0].size() == 0) continue;
		for (int j = 0; j < vals[k][0].size(); j++) {
			int t = vals[k][0][j].first, d = vals[k][0][j].second;
			for (int k1 = 0; k1 <= min(l1,ct); k1++) {
				if (vals[k1][1].size() == 0) continue;
				for (int j1 = 0; j1 < vals[k1][1].size(); j1++) {
					int t1 = vals[k1][1][j1].first, d1 = vals[k1][1][j1].second;
					
					if (t1 + t > T) continue;
					for (int k2 = 0; k2 <= min(ct, l2); k2++) {
						int km = max(k, k1),t2=T-t1-t; km = max(km, k2);
						int r = k + k1 + k2 - km;
						if (km > (r + 1) || t2<0) continue;
						int d2 = dp[max(l2 - 1,0)][t2][k2][2];
						
						if ((k == 0 && k1 == 0 && k2 == 0 )|| d2==0) continue;
						ans= (ans+ ((cal(ll(k), ll(k1), ll(k2))*mul(ll(d1),ll(d2)))%mod)*d)%mod;
						
					}
				}
			}
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

