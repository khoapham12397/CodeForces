#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef vector<int> vi;
int n,a[300010] , ord[300010],tt[300010],dp[300010];
vi pos[300010];
void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) pos[i].clear();
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		pos[a[i]].push_back(i);
	}
	int t=1;
	for (int i = 1; i <= n; i++) {
		if (pos[i].size() > 0) ord[i] = t,tt[t] =i, t++;
 	}
	int gtmax = 1;
	for (int i = 0; i < n; i++) {
		int x = a[i];
		int ind = ord[x];
		if (pos[x][pos[x].size() - 1] == i) {
			int st = pos[x][0];
			if (ind > 1) {
				int y = tt[ind - 1];
				if (pos[y][pos[y].size() - 1] < st) dp[ind] = dp[ind - 1] + 1,gtmax= max(gtmax, dp[ind]);
				else dp[ind] = 1;
			}
			else dp[ind] = 1;
		}
	}
	cout <<t - 1 - gtmax << endl;

}
int main()
{
	int t; cin >> t;
	while (t--) solve();
//	system("pause");
	return 0;
}

