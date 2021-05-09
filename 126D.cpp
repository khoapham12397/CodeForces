#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
ll a[101], dp[101][2],n;

void solve() {
	cin >> n;
	int ind = 87;
	ll x = n;
	vector<int> vt;
	while (x > 0) {
		while (a[ind] > x) ind--;
		vt.push_back(ind);
		x -= a[ind];
	}
	sort(vt.begin(), vt.end());
	if (vt[0] == 1 || vt[0] == 2) dp[0][1] = 0,dp[0][0]=1;
	else {
		dp[0][0] = 1;
		if (vt[0] % 2 == 1) dp[0][1] = (vt[0] - 1) >> 1;
		else dp[0][1] = (vt[0] >> 1) - 1;
	}
	for (int i = 1; i < vt.size(); i++) {
		dp[i][0] = dp[i - 1][1] + dp[i - 1][0];
		if (vt[i] % 2 != vt[i - 1] % 2) {
			dp[i][1] = ll((vt[i] - vt[i - 1] - 1) >> 1)*(dp[i - 1][0] + dp[i - 1][1]);
		}
		else {
			int val = (vt[i] - vt[i - 1]) >> 1;
			dp[i][1] = ll(val - 1)*(dp[i - 1][0] + dp[i - 1][1]) + dp[i - 1][1];
		}
	}
	cout << dp[vt.size() - 1][0] + dp[vt.size() - 1][1] << endl;
}
int main()
{
	a[1] = 1; a[2] = 2; 
	for (int i = 3; i <= 87; i++) a[i] = a[i - 1] + a[i - 2];
	int t; cin>>t;
	while(t--) solve();
//	system("pause");
    return 0;
}

