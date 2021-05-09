#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
int n,a[500010],dp[500010],f[500010],c,dpr[500010];
int s[500010];
ii b[500010];
map<int, ii> rs;
int BSearch(int val, int l, int r) {
	if (l == r) return l;
	int mid = (l + r) >> 1;
	if (b[mid].second == val) return mid;
	if (b[mid].second > val) return BSearch(val, l, mid - 1);
	return BSearch(val, mid + 1, r);
}
void solve() {
	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b[i] = ii(a[i], i);
	}
	sort(b, b + n);
	int l = 0;
	for (int i = 1; i < n; i++) {
		if (b[i].first != b[i - 1].first) {
			rs[b[i-1].first] = ii(l, i - 1);
			l = i;
		}
	}
	rs[b[n - 1].first] = ii(l, n - 1);
	dp[0] = (a[0] == c);
	f[0] = 1;
	for (int i = 1; i < n; i++) {
		dp[i] = dp[i - 1] + (a[i] == c);
		int x = a[i];
		int l = rs[x].first;
		int ind = BSearch(i,l, rs[x].second);
		if (ind == l) {
			f[i] = 1;
		}
		else f[i] = f[b[ind-1].second] + 1;
	}
	dpr[n] = 0;
	for (int i = n - 1; i >= 0; i--) dpr[i] = dpr[i + 1] + (a[i] == c);
	int ans = 0;
	map<int, ii>::iterator it;
	for (it = rs.begin(); it != rs.end(); it++) {

		int x = it->first, l = it->second.first, r = it->second.second;
		if (x == c) {
			ans = max(ans, dp[n - 1]);
			continue;
		}
		vi s(r - l + 1, 0);
		int ind = b[l].second;
		s[0] = dp[ind] - (f[ind]-1);
		ans = max(ans, s[0] + f[ind] + dpr[ind]);
		for (int i = l + 1; i <= r; i++) {
			ind = b[i].second;
			int val = dp[ind] - f[ind] + 1;
			if (val> s[i - 1-l]) {
				s[i-l] = val;
			}
			else s[i-l] = s[i-l - 1];
			ans = max(ans, s[i-l] + f[ind] + dpr[ind]);
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

