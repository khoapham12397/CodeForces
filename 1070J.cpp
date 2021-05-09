#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int n,m,k,a[26];
bool dp[26][30010][26];

void solve() {
	for (int i = 0; i < 26; i++) a[i] = 0;
	cin >> n >> m >> k;
	string s; cin >> s;
	for (int i = 0; i < k; i++) {
		a[int(s[i])-65]++;
	}
	int ans = int(1e9);	
	
	for (int j = 0; j < 26; j++) {
		if (a[j] == 0) continue;
		if (j == 0) {
			dp[0][0][0] = 1;
			for (int s = 1; s <= m; s++) dp[0][s][0] = 0;
		}
		else {
			dp[0][0][j] = 1;
			for (int s = 1; s <= m; s++) dp[0][s][j] = 0;
			dp[0][a[0]][j] = 1;
		}
		for (int i = 1; i < 25; i++) {
			if (i == j) { for (int s = 0; s <= m; s++) dp[i][s][j] = dp[i - 1][s][j]; continue; }
			for (int s = 0; s <= m; s++) {
				if (s >= a[i]) dp[i][s][j] = dp[i - 1][s - a[i]][j] | dp[i - 1][s][j];
				else dp[i][s][j] = dp[i - 1][s][j];
			}
		}
	

		int gtmax = 0;
		if (j == 25) {
			for (int s = 0; s <= m; s++) {
				dp[25][s][j] = dp[24][s][j];
				if (dp[25][s][j]) {
					int x = m - s, r = k - s - a[j];
					if (x > a[j]) continue;
					if (n <= r || x == a[j]) { cout << 0 << endl; return; }
					int d = n - r;
					ans = min(ans, x*d);
				}
			}
		}
		else {
			for (int s = 0; s <= m; s++) {
				if (s >= a[25]) dp[25][s][j] = (dp[24][s][j] | dp[24][s - a[25]][j]);
				else dp[25][s][j] = dp[24][s][j];
				
				if (dp[25][s][j]) {
					int x = m - s, r = k - s - a[j];
					if (x > a[j]) continue;
					if (n <= r || x == a[j]) { cout << 0 << endl; return; }
					int d = n - r;
					ans = min(ans, x*d);
				}
			}
		}
		
	}
	cout << ans << endl;
}

int main()
{
	int t; cin >> t;
	while (t--) solve();
//	system("pause");
    return 0;
}

