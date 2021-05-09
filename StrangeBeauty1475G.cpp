#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> ii;
int n,a[200001],dp[200001];
vector<ii> tk;
void solve() {
	tk.clear();
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	int sl = 1;
	for (int i = 1; i < n; i++) {
		if (a[i] != a[i - 1]) {
			tk.push_back(ii(a[i - 1], sl));
			sl = 1;
		}
		else sl++;
	}
	tk.push_back(ii(a[n - 1], sl));
	int len = tk.size();
	int gtmax = tk[len - 1].first;
	for(int i=0;i<=gtmax;i++) dp[i]=0;
	int ans;
	dp[gtmax] = tk[len - 1].second;
	ans = dp[gtmax];
	for (int i = len - 2; i >= 0; i--) {
		int x = tk[i].first;
		int j = 2,val= 0;
		while (j*x <= gtmax) {
			val = max(val, dp[j*x]);
			j++;
		}
		dp[x] = tk[i].second + val;
		ans = max(ans, dp[x]);
	}
	cout<<n - ans<<endl;
	
}
int main()
{
	int  T; cin >> T;
	for (int i = 0; i < T; i++) {
		solve();
	}
//	system("pause");
    return 0;
}

