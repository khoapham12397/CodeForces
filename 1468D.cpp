#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef vector<int> vi;
typedef long long ll;
void solve() {
	int n, m, a, b;
	cin >> n >> m >> a >> b;
	vi vt; 
	int dis = abs(a - b),d;

	for (int i = 0; i < m; i++) {
		int x; cin >> x;
		vt.push_back(x);
	}
	if (a == b) { cout << 0 << endl; return; }
	if (a < b) d = a - 1;
	else d = n - a;
	sort(vt.begin(), vt.end());
	int ans = 0,l=0,r= min(m,dis-1);
	while (l <= r) {
		int mid = (l + r) >> 1;
		int t = 1, gtmax =0 ;
		for (int i = mid - 1; i >= 0; i--) gtmax = max(gtmax , t+ vt[i]), t++;
		if (gtmax <= d + dis) {
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
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

