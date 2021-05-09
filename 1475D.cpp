#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<ll> vll;
int n,b[200010],inf= int(1e9)+7;
ll a[200010],m;
vll a1,a2,s1,s2;
int BSearch(int val,int l,int r) {
	if (l == r) {
		if (s2[l] >= val) return l;
		return l + 1;
	}
	int mid = (l + r) >> 1;
	if (s2[mid] == val) return mid;
	if (s2[mid] > val) {
		if (mid > l) return BSearch(val, l, mid - 1);
		return l;
	}
	return BSearch(val, mid + 1, r);
}
void solve() {
	a1.clear(); a2.clear(); s1.clear(); s2.clear();
	cin >> n >> m;
	int ans = inf;
	for (int i = 0; i < n; i++) cin >> a[i];
	
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		if (b[i] == 1) a1.push_back(a[i]);
		else a2.push_back(a[i]);
	}

	sort(a1.begin(), a1.end()); sort(a2.begin(), a2.end());
	s1.push_back(0);
	ll x = 0;
	for (int i = a1.size() - 1; i >= 0; i--) {
		x += a1[i]; s1.push_back(x);
	}
	x = 0; s2.push_back(0);
	for (int i = a2.size() - 1; i >= 0; i--) x += a2[i], s2.push_back(x);
	for (int i = 0; i < s1.size(); i++) {
		ll r = m - s1[i]; 
		if (r <= 0) ans = min(ans, i);
		else {
			if (s2[s2.size() - 1] >= r) {
				int ind = BSearch(r, 0, s2.size() - 1);
				ans = min(ans, i + 2 * ind);
			}
		}
	}
	if (ans != inf) cout <<ans << endl;
	else cout << -1 << endl;
}
int main()
{
	int T; cin >> T;
	while (T--) solve();
//	system("pause");
    return 0;
}

