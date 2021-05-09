#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> i3;
typedef long long ll;
int n,m;
int dp[81][100010];
ii a[81];
void solve() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
	}
	sort(a, a + n);

	dp[0][0] = 0;

	int x = a[0].first - a[0].second,r=a[0].first+a[0].second;
	if (x > 1) {
		for (int i = 1; i <= min(m,r+x-1); i++) dp[0][i] = x-1;
		for (int i = r + x ; i <= m; i++) dp[0][i] = i-r;
	}
	else {
		for (int i = 1; i <= min(r,m); i++) dp[0][i] = 0;
		for (int i = r + 1; i <= m; i++) dp[0][i] = i-r;
	}
	for (int i = 1; i < n; i++) {
		dp[i][0] = 0;
		int l = a[i].first - a[i].second, r = a[i].first + a[i].second;
		int d = max(l - 1, m - r); d = max(d, 0);
		
		for (int x = max(l,1); x <= min(r,m); x++) {
			dp[i][x] = dp[i-1][max(l,1) - 1];
			if (l > 1) dp[i][x] = min(dp[i][x], l - 1);
		}
		for (int x = l - 1; x >= 1; x--) {
			dp[i][x] = min(dp[i - 1][x], dp[i - 1][x-1]+l-x);
			if(l>1) dp[i][x] = min(dp[i][x], l-1);
		}
		
		for (int x = r + 1; x <= m; x++) {
			int l1 = max(1, l - x + r);
			dp[i][x] = min(dp[i - 1][x], dp[i - 1][l1-1]+x-r);
			if(l>1) dp[i][x] = min(dp[i][x], max(l - 1, x-r));
		}
		if (m - r < l - 1 && r<m) {
			for (int t = m - r + 1; t <= d; t++) {

				dp[i][m] = min(dp[i][m], dp[i - 1][max(0, l - t - 1)] + t);
			}
		}
		
	}
 
	cout << dp[n - 1][m] << endl;
	
}


int main()
{
	solve();
//	system("pause");
    return 0;
}

