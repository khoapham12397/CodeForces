#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
int n,a[300000],p2[19];
ll dp[300000][20];
void solve() {
	cin >> n;
	int t = 0,ind=1;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 0; i <= 18; i++) if (n == p2[i]) {
		t = i; break;
	}
	
	for (int i = 1; i <= n; i++) if (a[i] == -1) ind = i;
	for (int i = ind; i <= n; i++) {
		for (int x = 0; x <= t; x++) dp[i][x] = ll(1e17);
	}
	for (int x = 0; p2[x] <= ind; x++) {
		dp[ind][x] = 0;
	}
	for (int i = ind + 1; i <= n; i++) {
		dp[i][0] = 0;
		for (int x = 1; p2[x] <= i; x++) {
			dp[i][x] = min(dp[i - 1][x], dp[i - 1][x - 1] + a[i]);
		}
	}
	cout << dp[n][t] << endl;
}
int main()
{
	p2[0] = 1; for (int i = 1; i <= 18; i++) p2[i] = 2 * p2[i - 1];
	solve();
//	system("pause");
    return 0;
}

