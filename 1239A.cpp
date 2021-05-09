#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
int n,m;
ll mod = 1000000007,dp[100001][4];
void solve() {
	cin >> n >> m;
	dp[2][0] = 1; dp[2][1] = 1; dp[2][2] = 1; dp[2][3] = 1;
	for (int i = 3; i <= max(m, n); i++) {
		dp[i][0] = (dp[i - 1][2]);
		dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % mod;
		dp[i][2] = (dp[i - 1][3] + dp[i - 1][1]) % mod;
		dp[i][3] = (dp[i - 1][1]);
	}
	if (m == 1 && n == 1) { cout << 2 << endl; return; }
	ll x = 0,y=0,ans=0;
	for (int i = 0; i < 4; i++) x = (x + dp[n][i]) % mod,y=(y+dp[m][i])%mod;
	
	if (m == 1 || n == 1) ans = (x + y) % mod;
	else ans = (x + (y + mod - 2) % mod) % mod;
	cout << ans<<endl;
}
int main()
{
	solve();
//	system("pause");
    return 0;
}

