#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n,a[510],fr[510],fl[510],dp[510][510],sr[510],sl[510];
int gl[510][510], gr[510][510];
void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) {
		int ind = i + 1;
		int x = a[i];
		while (ind < n) {
			if (a[ind] == x) {
				x++; ind++;
			}
			else break;
		}
		sr[i] = x;
		fr[i] = ind - 1;
	}
	for (int i = n - 1; i >= 0; i--) {
		int ind = i - 1, x=a[i];
		while (ind >= 0) {
			if (a[ind] == x) {
				x++; ind--;
			}
			else break;
		}
		sl[i] = x;
		fl[i] = ind+1;
	}
	
	for (int i = 0; i < n; i++) dp[i][i] = 1, gr[i][i] = gl[i][i] = a[i];
	for (int d = 1; d < n; d++) {
		for (int i = 0; i < n-d; i++) {
			int j = i + d,vl,vr;
			
			int val = int(1e9);
			if (fr[i] >= j) {
				dp[i][j] = 1; 
				gl[i][j] = gr[i][j] = a[i] + j - i;
				continue;
			}
			if (fl[j] <= i) {
				dp[i][j] = 1; gr[i][j] = gl[i][j] = sl[j];
				gl[i][j] = gr[i][j] = a[j] + j - i;
				continue;
			}
			
			for (int k = i; k < j; k++) {
				int x = gr[i][k], y = gl[k + 1][j];
				int u = dp[i][k] + dp[k + 1][j];
				if (x == y) u--;
				if (u < val) {
					if (dp[i][k] == 1 && x==y) vl = x + 1;
					else vl = gl[i][k];
					if (dp[k + 1][j] == 1 && x==y) vr = y + 1;
					else vr = gr[k+1][j];
					val = u;
				}
			}
			dp[i][j] = val;  gl[i][j] =vl; gr[i][j]=vr;
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

