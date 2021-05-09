#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
int n,m;
vii vt;
void solve() {
	sort(vt.begin(), vt.end());
	bool ans = 1;
	vii vt1;	
	int ind = 0;
	while (ind < vt.size()-1) {
		if (vt[ind].first == vt[ind + 1].first) {
			vt1.push_back(ii(vt[ind].first, 3));
			ind += 2;
		}
		else {
			vt1.push_back(ii(vt[ind].first, vt[ind].second));
			ind++;
		}
	}
	if (ind == vt.size()-1) {
		vt1.push_back(ii(vt[ind].first, vt[ind].second));
	}
	ind = 0;
	int c = vt1[0].first, r = vt1[0].second;
	while (r == 3 && ind < vt1.size()-1) {
		ind++;
		c = vt1[ind].first; r = vt1[ind].second;
	}
	if (ind == vt1.size() - 1 && r == 3) { cout << "YES" << endl; return; }
	if (ind == vt1.size() - 1 && r != 3) { cout << "NO" << endl; return; }
	while (1) {
		int c1 = vt1[ind + 1].first, r1 = vt1[ind + 1].second;
		if (r1 == 3) { ans = 0; break; }
		if (r1 == r && (c1 - c) % 2 == 0) { ans = 0; break; }
		if (r1 != r && (c1 - c) % 2 == 1) { ans = 0; break; }
		
		if (ind + 1 == vt1.size() - 1) {
			ans = 1; break;
		}
		ind += 2;
		
		while (ind < vt1.size() && vt1[ind].second == 3) ind++;
		if (ind == vt1.size()) { ans = 1; break; }
		
		if (ind == vt1.size() - 1) { ans = 0; break; }
		c = vt1[ind].first; r = vt1[ind].second;
	}
	if (ans == 0) cout << "NO" << endl;
	else cout << "YES" << endl;
}
int main()
{
	int T; cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n >> m;
		for (int j = 0; j < m; j++) {
			int x, y; cin >> x >> y;
			vt.push_back(ii(y,x));
		}
		solve();
		vt.clear();
	}
//	system("pause");
    return 0;
}

