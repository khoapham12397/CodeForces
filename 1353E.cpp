#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int n,K,s0[1000001],s1[1000001],dp[1000001];
string S;
void solve() {
	if (S[0] == '0') s0[0] = 1, s1[0] = 0;
	else s0[0] = 0, s1[0] = 1;
	for (int i = 1; i < n; i++) {
		s1[i] = s1[i - 1]; s0[i] = s0[i - 1];
		if (S[i] == '0') s0[i]++;
		else s1[i]++;
	}
	dp[0] = s0[0];
	
	int ans = min(s1[n - 1], dp[0] + s1[n - 1] - s1[0]);
	for (int i = 1; i < n; i++) {
		int t;
		if (S[i] == '0') t = 1;
		else t = 0;
		int j = i - K + 1;
		if (j > 0) {
			int sl = s1[i - 1] - s1[i - K];
			dp[i] = min( sl + dp[i - K], s1[i-1])+t;
		}
		else {
			dp[i] = t+ s1[i - 1];
		}
		ans = min(ans, dp[i] + s1[n - 1] - s1[i]);
	}
	cout << ans << endl;

}
int main()
{
	int T; cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n >> K; cin >> S;
		solve();
	}
//	system("pause");
    return 0;
}

