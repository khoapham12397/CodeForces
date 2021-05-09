#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> i3;
int n, m;


void solve() {
	cin >> n >> m;
	vector<i3> vt;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
		int x; cin >> x; vt.push_back(i3(x,ii(i,j)));
	}
	
	sort(vt.begin(), vt.end());

	int ans = 0;
	if (n < 4) {
		for (int i = int(vt.size()) - 1; i >= int(vt.size()) - n; i--) ans += vt[i].first;
		cout << ans << endl;
		return;
	}
	int len = n*m;
	i3 x[4];
	for (int i = 0; i < 4; i++)  x[i] = vt[len - 1 - i], ans+=x[i].first ;
	bool spc = false;
	for (int i = 0; i < 3; i++) {
		for (int j = i + 1; j < 4; j++) {
			if (x[i].second.second == x[j].second.second) {
				int d = abs(x[i].second.first - x[j].second.first);
				int i1,j1;
				for (int y = 0; y < 4; y++) {
					if (y != i && y != j) { i1 = y; break; }
				}
				for (int y = 0; y < 4; y++) if (y != i && y != j && y != i1) { j1 = y; break; }
				if (x[i1].second.second == x[j1].second.second && x[i1].second.second != x[i].second.second) {
					int d1 = abs(x[i1].second.first - x[j1].second.first);
					if (d % 2 != d1 % 2) {
						spc = true; break;
					}
				}
 			}
		}
		if (spc) break;
	}

	if (spc) {
		int val = ans - x[3].first + vt[len-5].first;
		cout << val << endl;
	}
	else cout << ans << endl;
}
int main()
{
	int t; cin >> t;
	while (t--) solve();
//	system("pause");
    return 0;
}

