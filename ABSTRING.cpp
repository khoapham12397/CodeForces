#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;
typedef pair<int, int>ii;
typedef pair<int, ii> i3;
typedef vector<i3> vi3;
vi3 vt;
int n;
string s;
ll ans = 0;
void solve() {
	cin >> n; cin >> s;
	int x = int(s[0]) - 65,l=0,r=0;
	for (int i = 1; i < n; i++) {
		if (s[i] != s[i - 1]) {
			vt.push_back(i3(r-l+1, ii(l, r)));
			x = int(s[i]) - 65; l = r = i;
		}
		else r = i;
	}
	vt.push_back(i3(r-l+1, ii(l, r)));
	int d = vt[0].second.second - vt[0].second.first;
	ans += ll(d+1)*ll(d)/ll(2);
	for (int i = 1; i < vt.size(); i++) {
		int sl= vt[i].first ,l = vt[i].second.first, r=vt[i].second.second;
		ans += ll(sl)*ll(sl - 1) / 2;
		if (vt[i - 1].first > 1) {
			ans += (vt[i - 1].second.second)*(ll(sl) - ll(1));
			if (i > 1) ans += ll(vt[i - 2].second.second) + ll(1);
		}
		else {
			if (i > 1) ans += ll(sl)*(ll(vt[i - 2].second.second) + ll(1));
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

