#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int n,dp[510][510];
string s;
void solve() {
	cin >> n >> s;
	for (int i = 0; i < n; i++) dp[i][i] = 1;
	for (int i = 0; i < n - 1; i++) {
		if (s[i] == s[i + 1]) dp[i][i + 1] = 1;
		else dp[i][i + 1] = 2;
	}
	for (int d = 2; d < n; d++) {
		for (int i = 0; i < n - d; i++ ) {
			int j = i + d;
			int val = min(dp[i][j-1],dp[i+1][j]) + 1;
			for (int x = i + 1; x <= j; x++) {
				if (s[x] == s[i]) {
					if (x > i + 1) val = min(val, dp[i + 1][x-1] + dp[x][j]);
					else val = min(val,dp[x][j]);
				}
			}
			for (int x = j - 1; x >= i; x--) {
				if (s[x] == s[j]) {
					if (x < j - 1) val = min(val, dp[x + 1][j - 1] + dp[i][x]);
					else val = min(val, dp[i][x]);
				}
			}
			dp[i][j] = val;
		}
	}
	cout << dp[0][n - 1] << endl;
}
int main()
{
	solve();
//	system("pause");
    return 0;
}

