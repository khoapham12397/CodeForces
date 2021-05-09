#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int n, k,a[5010],f[510], h[20];
int dp[5010][510],sl[5010],cnt[5010];
map<int, int> tt;

void solve() {
	cin >> n >> k;
	int len = n*k;
	for (int i = 1; i <= len; i++) {
		cin >> a[i];
	}
	for(int i=1;i<=n;i++) cin>>f[i];
	h[0] = 0;
	for (int i = 1; i <= k; i++) cin >> h[i];

	sort(a + 1, a + len+1);
	int t = 1, u = 1;
	
	for (int i = 2; i <= len; i++) {
		if (a[i] != a[i-1]) {
			tt[a[i - 1]] = u; sl[u] = t;
			u++; t = 1;
		}
		else t++;
	}
	tt[a[len]] = u; // dieu nay la dung do ma :
	sl[u] =t;
	for (int i = 1; i <= n; i++) {
		int x = f[i];
		int ind = tt[x];
		if (ind != 0) {
			cnt[ind]++;
		}
	}
	
	
	for (int i = 1; i <= n*k; i++) {
		dp[i][1] = h[min(i, k)];
		for (int j = 2; j <= n; j++) {
			int val = 0 ,ct = min(i,k);
			for (int x = 0; x <=ct; x++) {
				val = max(val, dp[i - x][j - 1] + h[x]);
			}
			dp[i][j] = val;
		}
	}
	int ans = 0;
	for (int i = 1; i <= u; i++) {
		if (cnt[i] > 0 && sl[i]>0) {
			ans += dp[sl[i]][cnt[i]];
		}
	}
	cout << ans << endl;

}
int main()
{
	solve();
//	system("pause");
    return 0;
}

