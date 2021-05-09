#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> ii;
int n,k,a[200010];
ii dp[200010];
void solve() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> a[i];
	dp[0].first =dp[0].second = a[0] + k;
	for (int i = 1; i < n - 1; i++) {
		if (a[i] + 2 * k - 1 <= dp[i - 1].second - k || a[i] >= dp[i - 1].first) { cout << "NO" << endl; return; }
		dp[i].first = min(a[i] + k - 1, dp[i - 1].first - 1) + k;
		dp[i].second = max(a[i] + k, dp[i - 1].second - k + 1);
	}
	if (dp[n - 2].first <= a[n - 1] || dp[n - 2].second - k >= a[n - 1] + k) cout << "NO" << endl;
	else cout << "YES" << endl;

}
int main()
{
	int t; cin >> t;
	while(t--) solve(); 
//	system("pause");
    return 0;
}

