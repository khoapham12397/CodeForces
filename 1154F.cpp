#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
int n,m,k,a[200010],b[2010];
ll s[2010],dp[2010];
void solve() {
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];

	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		if(x<=k) b[x] = max(b[x], y);
	}
	sort(a + 1, a + n + 1);
	s[0] = 0; dp[0] = 0;
	for (int i = 1; i <= k; i++) s[i] = s[i - 1] + a[i]; 
	if (b[1] > 0) { dp[1] = 0; }
	else dp[1] = a[1];
	for (int i = 2; i <= k; i++) {
		ll val = ll(1e18);
		for (int j = 0; j < i; j++) {
			ll gt = dp[j] + s[i] - s[j + b[i - j]];
			if (val > gt) val = gt;
			
		}
		dp[i] = val;
	}
	cout << dp[k] << endl;
}
int main()
{
	solve();
//	system("pause");
    return 0;
}

