#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> ii;
int n, a[2010];

void solve() {
	cin >> n;
	int len = 2 * n;
	for (int i = 0; i < len; i++) cin >> a[i];
	sort(a, a + len);
	vector<ii> ans;
	int val = 0;
	for (int i = 0; i <= len - 2; i++) {
		vector<bool> used; used.assign(len, false);
		vector<ii> res; res.push_back(ii(a[len - 1], a[i]));
		used[i] = true;
		int j = len - 1;
		bool ok = true;
		while (j > 0) {
			int t = j - 1;
			while (t >= 0 && used[t]) t--;
			if (t > 0) {
				int x = a[j] - a[t];
				int t1 = t - 1;
				while (t1 >= 0 && (a[t1] != x ||  used[t1])) t1--;
				if (t1 < 0) {
					ok = false;
					break;
				}
				else {
					res.push_back(ii(a[t], a[t1]));
					used[t1] = true; 
					used[j] = true;
					j = t;
				}
			}
			else break;
		}
		if (ok) { ans = res; val = a[len - 1] + a[i]; break; }
	}
	if (ans.size() > 0) {
		cout << "YES" << endl;
		cout << val << endl;
		for (int i = 0; i < ans.size(); i++) cout << ans[i].first << " " << ans[i].second << endl;
	}
	else cout << "NO" << endl;
}
int main()
{
	int t; cin >> t;
	while(t--) solve();
//	system("pause");
    return 0;
}

