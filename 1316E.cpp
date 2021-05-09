#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
int n, p, k,s[100010][7],tt[100010];
ii a[1000010];
ll dp[100010][128];
int bs[128];
vi vs[128];
int cmp(ii x, ii y) {
	if (x.first > y.first) return 1;
	return 0;
}
void solve() {
	cin >> n >> p >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a, a + n,cmp);
	for (int msk = 0; msk < (1 << p); msk++) {
		for (int j = 0; j < p; j++) {
			if ((msk >> j)%2 == 1) vs[msk].push_back(j);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < p; j++) cin >> s[i][j];
	}
	dp[0][0] = a[0].first;
	for (int msk = 1; msk < (1 << p); msk++) dp[0][msk] = -1;
	for (int i = 0; i < p; i++) {
		int id = a[0].second;
		int msk = (1 << i);
		dp[0][msk] = s[id][i];
	}
	for (int i = 1; i < n; i++) {
		int id = a[i].second;
		if (i + 1 <= k) dp[i][0] = dp[i - 1][0] + a[i].first;
		else dp[i][0] = dp[i - 1][0];
 		for (int msk = 1; msk < (1 << p); msk++) {
			int sl = vs[msk].size();
			if (sl > i + 1) { dp[i][msk] = -1; continue; }
			ll val = dp[i - 1][msk];
			
			if (i + 1 <= sl + k && sl<=i ) val += a[i].first;
			for (int j = 0; j < vs[msk].size(); j++) {
				int pos = vs[msk][j];
				int msk1 = msk - (1 << pos);
				val = max(val, dp[i - 1][msk1] + s[id][pos]);
			}
			dp[i][msk] = val;
		}
	}
	cout << dp[n - 1][(1 << p) - 1] << endl;

}
int main()
{
	solve();
//	system("pause");
    return 0;
}

