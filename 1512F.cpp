#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
ll n,c,a[200010],b[200010], dp[200010],f[200010];
void solve() {
	cin >> n >> c;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i < n; i++) cin >> b[i];
	ll ind = 1, m = 0,t=1;
	dp[1] = 1; f[1] = 0;

	while (ind < n) {
	
		ll x = b[ind];
		if (m >= x) {
			m -= x; t++; dp[ind + 1] = t; f[ind + 1] = m;
		}
		else {
	
			ll del = x - m;
			ll sd = ll(del / a[ind]);
			if (del % a[ind] != 0) sd++;
			dp[ind + 1] = t + sd + 1; 
			f[ind + 1] = m + a[ind]*sd - x; 
			t = t + sd + 1; 
			m = f[ind + 1];
		}
		ind++; 

	}
	ll ans = int(1e15);
	
	for (int i = 1; i <= n; i++) {
		ll del = c - f[i];
		ll sd = del / a[i];
		if (del%a[i] != 0) sd++;
		ans = min(ans, dp[i] + sd-1);
	}
	cout << ans << endl;
}
int main()
{
	int t; cin >> t;
	while (t--) solve();
//	system("pause");
    return 0;
}

