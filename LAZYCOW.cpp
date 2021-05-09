#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
int n,k,b,inf=int(1e9)+7;
int dp[1010][1010][5],f[1010][1010];
vector<ii> pos,sb;

void solve() {
	pos.clear(); sb.clear();
	cin >> n >> k >> b;
	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		pos.push_back(ii(y, x));
	}
	sort(pos.begin(), pos.end());
	bool check = true;
	for (int i = 1; i < n; i++) {
		if (pos[i].first == pos[i - 1].first) {
			sb.push_back(ii(pos[i].first,3));
			check = false;
		}
		else {
			if (check) { sb.push_back(ii(pos[i - 1].first, pos[i - 1].second));}
			else check = true;
		}
	}
	if (check) sb.push_back(ii(pos[n - 1].first, pos[n - 1].second));
	int len = sb.size();
	for (int i = 0; i < n; i++) {
		for (int t = 0; t <= k; t++) {
			f[i][t] = inf;
			for (int msk = 0; msk < 5; msk++) dp[i][t][msk] = inf;
		}
	}
	if (sb[0].second == 1) dp[0][1][1] = 0, dp[0][1][3] = dp[0][2][4] = f[0][2] = 1 ,f[0][1] = 0;
	if (sb[0].second == 2) dp[0][1][2] = 0, dp[0][1][3] = dp[0][2][4] = f[0][2] = 1 ,f[0][1] =0 ;
	if (sb[0].second == 3) dp[0][1][3] = dp[0][2][4] = f[0][1]= f[0][2] =0 ;
	for (int i = 1; i < len; i++) {
		switch (sb[i].second) {
		case 1:
			for (int t = 1; t <= k; t++) {
				
				dp[i][t][1] = min(min(dp[i - 1][t][1],dp[i-1][t][4]) + sb[i].first - sb[i - 1].first - 1, f[i - 1][t - 1]);
				dp[i][t][3] = min(dp[i - 1][t][3] + 2 * (sb[i].first - sb[i - 1].first - 1) + 1, f[i - 1][t - 1] +1);
				dp[i][t][4] = min(dp[i - 1][t - 1][1] + sb[i].first - sb[i - 1].first , dp[i - 1][t - 1][2] + sb[i].first -sb[i-1].first ) ;
				dp[i][t][4] = min(dp[i][t][4], dp[i - 1][t][4] + 2 * (sb[i].first - sb[i - 1].first - 1) + 1);
				if (t > 2) {
					dp[i][t][4] = min(dp[i][t][4], f[i - 1][t - 2] + 1);
				}
				f[i][t] = min(dp[i][t][1], dp[i][t][3]);
				f[i][t] = min(f[i][t], dp[i][t][4]);
			}
			break;
		case 2:
			for (int t = 1; t <= k; t++) {
				dp[i][t][2] = min(min(dp[i - 1][t][2],dp[i-1][t][4]) + sb[i].first - sb[i-1].first -1, f[i - 1][t - 1]);
				dp[i][t][3] = min(dp[i - 1][t][3] + 2*(sb[i].first - sb[i-1].first -1)+1,  f[i - 1][t - 1] + 1 );
				dp[i][t][4] = min(dp[i - 1][t - 1][1] + sb[i].first - sb[i - 1].first, dp[i - 1][t - 1][2] + dp[i - 1][t - 1][2] + sb[i].first - sb[i - 1].first );
				dp[i][t][4] = min(dp[i - 1][t][4] + 2 * (sb[i].first - sb[i - 1].first - 1) + 1,dp[i][t][4]);
				if (t > 2) dp[i][t][4] = min(dp[i][t][4], f[i - 1][t - 2] + 1);
				f[i][t] = min(dp[i][t][2], dp[i][t][3]);
				f[i][t] = min(f[i][t], dp[i][t][4]);
				
			}
			break;
		case 3:
			for (int t = 1; t <= k; t++) {
				dp[i][t][3] = min(dp[i - 1][t][3] + 2 * (sb[i].first - sb[i - 1].first - 1), f[i - 1][t - 1]);
				dp[i][t][4] = min(dp[i - 1][t - 1][1], dp[i - 1][t - 1][2]) + sb[i].first - sb[i - 1].first-1;
				dp[i][t][4] = min(dp[i][t][4], dp[i - 1][t][4] + 2 * (sb[i].first - sb[i - 1].first - 1));

				if (t > 2) dp[i][t][4] = min(dp[i][t][4], f[i - 1][t - 2]);
				f[i][t] = min(dp[i][t][3], dp[i][t][4]);
			}
			break;
		}
	}
	cout << f[len - 1][k]+n << endl;
}
int main()
{
	int t; cin >> t;
	while(t--) solve();
//	system("pause");
    return 0;
}

