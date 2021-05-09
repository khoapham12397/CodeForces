#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
int n,m,N,M;
int dp[1000010][8];
int a[10][1000010];
int ans = ll(1e9);
void solve() {
	cin >> n >> m;
	if (n >= 4 && m >= 4) { cout << -1 << endl;  return; }
	//N = min(n, m); M = max(n, m);
	if (n >= m) {
		for (int i = 1; i <= n; i++) {
			string s; cin >> s;
			for (int j = 0; j < m; j++) a[j + 1][i] = int(s[j]) - 48;
		}
		N=m; M=n;
	}else {
		for (int i = 1; i <= n; i++) {
			string s; cin >> s;
			for (int j = 0; j < m; j++) a[i][j + 1] = int(s[j]) - 48;
		}M=m; N=n;
	}
	if (N == 1) ans=0;
	if (N == 2) {
		int x = a[1][1] + 2 * a[2][1];
		for (int st = 0; st < 4; st++) {
			int u = (st^x),t=0;
			for(int j=0;j<2;j++){
				if ((u >> j) % 2 == 1) t++;
			}
			dp[1][st] = t;
		}
		for (int i = 2; i <= M; i++) {
			int x = a[1][i] + 2*a[2][i];
			for (int st = 0; st < 4; st++) {
				int u = st^x,t=0;
				for (int j = 0; j < 2; j++) if ((u >> j) % 2 == 1) t++;
				if (st == 0 || st == 3) dp[i][st] = min(dp[i - 1][1] , dp[i - 1][2])+ t;
				if (st == 1 || st == 2) dp[i][st] = min(dp[i - 1][0] , dp[i - 1][3])+ t;
			}
		}
		for (int st = 0; st < 4; st++) ans = min(ans, dp[M][st]);
	}
	if (N == 3) {
		int x = a[1][1] + 2 * a[2][1] + 4 * a[3][1];
		for (int st = 0; st < 8; st++) {
			int u = (st^x), t = 0;
			for (int j = 0; j < 3; j++) if ((u >> j) % 2 == 1) t++;
			dp[1][st] = t;
		}
		for (int i = 2; i <= M; i++) {
			int x = a[1][i] + 2 * a[2][i] + 4 * a[3][i];
			for (int st = 0; st < 8; st++) {
				int u = st^x,t=0;
				for (int j = 0; j < 3; j++) if ((u >> j) % 2 == 1) t++;
				if (st == 0) dp[i][st] = min(dp[i - 1][2], dp[i - 1][5]) + t;
				if (st == 1) dp[i][st] = min(dp[i - 1][3], dp[i - 1][4]) + t;
				if (st == 2) dp[i][st] = min(dp[i - 1][0], dp[i - 1][7]) + t;
				if (st == 3) dp[i][st] = min(dp[i - 1][1], dp[i - 1][6]) + t;
				if (st == 4) dp[i][st] = min(dp[i - 1][1], dp[i - 1][6]) + t;
				if (st == 5) dp[i][st] = min(dp[i - 1][0], dp[i - 1][7]) + t;
				if (st == 6) dp[i][st] = min(dp[i - 1][3], dp[i - 1][4]) + t;
				if (st == 7) dp[i][st] = min(dp[i - 1][2], dp[i - 1][5]) + t;
			}
		}
		for (int st = 0; st < 8; st++) {
			ans = min(ans,dp[M][st]);
		}
		
	}
	cout<<ans<<endl;
}
int main()
{
	solve();
//	system("pause");
    return 0;
}

