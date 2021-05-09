#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<ll, int> li;
ll dp[200010], f[200010], mod = ll(1e9) + 7;
ll a[200010];
li s[200010];
int n,pos[200010];
void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		pos[i] = -1;
	}
	s[n].first = a[n],s[n].second= n;
	for (int i = n - 1; i >= 1; i--) {
		s[i].first = s[i + 1].first + a[i];
		s[i].second = i;
	}
	sort(s + 1, s + n+1);
	for (int i = n; i > 1; i--) {
		if (s[i].first == s[i-1].first) {
			pos[s[i].second] = s[i - 1].second;
		}
	}
	f[1]=dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		dp[i] = f[i-1];
		f[i] = (2 * f[i - 1])%mod;
		if (pos[i] != -1) f[i] = (f[i]+ (mod- dp[pos[i]])%mod)%mod;
	}
	cout << f[n] << endl;
}
int main()
{
	int T; cin >> T;
	for (int i = 0; i < T; i++) {
		solve();
	}
//	system("pause");
    return 0;
}

