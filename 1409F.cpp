#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int n,K,dp[201][201][201],Fa[201],Fad[201];
string S,T;
void solve() {
	cin >> n>>K;
	cin >> S >> T;
	char a = T[0], d = T[1];
	if (a == d) {
		int sl = 0,x,y;
		for (int i = 0; i < n; i++) { if (S[i] != a && S[i] != d) sl++; }
		x = min(sl, K); y = n - sl + x;
		cout << y*(y - 1) / 2 << endl;
		return;
	}
	for (int i = 0; i < n; i++) for (int t = 0; t <= K; t++) for (int j = 0; j <= n; j++) dp[i][t][j] = -1;
	if (S[0] == a) {
		dp[0][0][1] = 0;
		Fa[0] = 1; Fad[0] = 0;
	}
	else {
		dp[0][1][1] = 0;
		dp[0][0][0] = 0;
	}
	for (int i = 1; i < n; i++) {
		Fa[i]=Fa[i-1];Fad[i]=Fad[i-1];
		if (S[i] == a) Fa[i]++;
		if (S[i] == d) Fad[i]+=Fa[i-1];
	}
	if (K == 0) { cout << Fad[n - 1] << endl; return; }
	for (int i = 1; i < n; i++) {
		dp[i][0][Fa[i]] = Fad[i];
		char x = S[i];
		for (int t = 1; t <= K; t++) {
			if (x == a) {
				dp[i][t][0] = dp[i][t - 1][0];
			}
			else dp[i][t][0] = dp[i][t][0];
			for (int j = 1; j <= n; j++) {
				if (x == a) {
					int u = dp[i - 1][t - 1][j],v=dp[i-1][t][j-1],val;
					val =dp[i - 1][t][j - 1];
					if (u >= 0) val = max(dp[i - 1][t - 1][j] + j,val);
					dp[i][t][j] = val;
				}
				if (x == d) {
					int u = dp[i - 1][t][j],v=dp[i-1][t-1][j-1],val;
					val = v;
					if (u >= 0) val =max(val, u + j);
					dp[i][t][j] = val;
				}
				if (x != d && x != a) {
					int u = dp[i - 1][t][j],v=dp[i-1][t-1][j-1],val, v1= dp[i-1][t-1][j];
					val = u;
					if (v >= 0) val = max(val, v);
					if (v1 >= 0) val = max(val, v1 + j);
					dp[i][t][j] = val;
				}
			}
		}
	}
	int ans = -1;
	for (int i = 0; i <= K; i++) {
		for (int j = 0; j <= n; j++) ans = max(dp[n - 1][i][j],ans);
	}
	cout << ans << endl;
}
int main()
{
	solve();
//	system("pause");
    return 0;
}

