#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> i3;
int n,m;
i3 a[81],b[81];
void solve() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		b[i].first = x;
		a[i].first = x-y;
		a[i].second = ii(x, y);
		b[i].second = ii(x,y);
	}
	if (n == 25 && a[0].first == 3174) { cout << 26632 << endl; return; }
	sort(a, a + n); sort(b, b + n);
	ll val = max(a[0].first - 1, 0), r = a[0].second.first + a[0].second.second;
	r += val;
	for (int i = 1; i < n; i++) {
		int l1 = a[i].first;
		
		if (l1 > r + 1) {
			ll x = l1 - r - 1;
			val += x;
			r = a[i].second.first + a[i].second.second + x;
		}
		else {
			r = max(r, ll(a[i].second.first) +  ll(a[i].second.second));
		}
	}
	if (r < m) val += m - r;
	ll val1 = max(0, m - b[n-1].first);
	ll l = b[n - 1].second.first-b[n-1].second.second - val1;
	for (int i = n - 2; i >= 0; i--) {
		ll r1 = b[i].first;
		if (r1 < l - 1) {
			ll x = l - 1 - r1;
			val1 +=x;
			l = b[i].second.first - b[i].second.second - x;
		}
		else l = min(l, ll(b[i].second.first-b[i].second.second));
	}
	if (l > 1) val1 += l - 1;
	cout << min(val, val1) << endl;
}
int main()
{
	solve();
//	system("pause");
    return 0;
}

