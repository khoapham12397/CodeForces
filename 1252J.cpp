#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
int n, k, g1,g2, g3;
ii f[51][2];
ll dp[51][2], inf = ll(1e15);
string s;
vi pos;
void solve() {
	cin >> n >> k >> g1 >> g2 >> g3;
	cin >> s;
	int st = 0,len=0,cr=0;
	while (st < n && s[st] == '#') st++,cr++;
	for (int i = st; i < n; i++) if (s[i] == '#') pos.push_back(i),cr++;
	ll val = 0;
	int sl2, sl3;
	len = pos.size();
	if (len > 0) {


		dp[0][0] = ll(g2)*ll((pos[0] - st) / 2);
		f[0][0] = ii(int((pos[0] - st) / 2), 0);
		if (pos[0] + 1 < n && s[pos[0] - 1] == '.' && s[pos[0] + 1] == '.') {
			dp[0][1] = ll(g3) + ll((pos[0] - 1 - st) / 2)*ll(g2);
			f[0][1] = ii(int((pos[0] - 1 - st) / 2), 1);
		}
		else {
			dp[0][1] = 0;
			f[0][1] = ii(-1, -1);
		}
		for (int i = 1; i < len; i++) {
			int d1 = (pos[i] - pos[i - 1] - 1) >> 1, d2 = (pos[i] - pos[i - 1] - 2) >> 1;
			ll x = dp[i - 1][0] + ll(g2)*ll(d1);
			ll y = dp[i - 1][1] + ll(g2) *ll(d2);
			if (x > y || f[i - 1][1].first == -1) {
				f[i][0] = ii(f[i - 1][0].first + d1, f[i - 1][0].second);
				dp[i][0] = x;
			}
			else {
				f[i][0] = ii(f[i - 1][1].first + d2, f[i - 1][1].second);
				dp[i][0] = y;
			}
			if (pos[i] + 1 < n && s[pos[i] - 1] == '.' && s[pos[i] + 1] == '.') {
				int d1 = (pos[i] - 2 - pos[i - 1]) / 2, d2 = (pos[i] - 3 - pos[i - 1]) / 2;
				x = dp[i - 1][0] + ll(g3) + ll(g2)*ll(d1);
				y = dp[i - 1][1] + ll(g2)*ll(d2) + ll(g3);
				if (x > y || f[i - 1][1].first == -1) {
					f[i][1] = ii(f[i - 1][0].first + d1, f[i - 1][0].second + 1);
					dp[i][1] = x;
				}
				else {
					f[i][1] = ii(f[i - 1][1].first + d2, f[i - 1][1].second + 1);
					dp[i][1] = y;
				}
			}
			else {
				dp[i][1] = 0; f[i][1] = ii(-1, -1);
			}

		}

		if (pos[len - 1] + 1 < n) {
			ll x = dp[len - 1][0] + ll((n - 1 - pos[len - 1]) / 2)*ll(g2);
			ll y = dp[len - 1][1] + ll(g2) * ll((n - 2 - pos[len - 1]) / 2);
			if (x > y || f[len - 1][1].first == -1) {
				val = x; sl2 = f[len - 1][0].first + int((n - 1 - pos[len - 1]) / 2);
				sl3 = f[len - 1][0].second;
			}
			else {
				val = y; sl3 = f[len - 1][1].second;
				sl2 = f[len - 1][1].first + int((n - 2 - pos[len - 1]) / 2);
			}
		}
		else {
			ll x = dp[len - 1][0];
			val = x;
			sl2 = f[len - 1][0].first, sl3 = f[len - 1][0].second;
		}
	}else{
		sl2 = (n - st) / 2,sl3=0;
		val = ll(sl2)*ll(g2);
	}
	int r = n - sl2 * 2 - sl3 * 3 -(cr-sl3);
	if (r >= k) {
		val += ll(g1) * k;
		cout << val << endl; return;
	}
	int d = k - r; val += ll(g1)*ll(r);
	
	int gt[4], sed, trd, sl[4]; gt[2] = g2; gt[3] = g3;
	sl[2] = sl2; sl[3] = sl3;
	if (g3 < g2) sed = 2, trd = 3;
	else sed = 3, trd = 2;

	if (sl[trd] > 0 && 2*g1 > gt[trd] ) {
		if (d <= sl[trd] * 2) {
			int x = d / 2;
			val += ll(x * 2)*ll(g1) - ll(x)*gt[trd];
			if (d % 2 == 1 && g1 > gt[trd]) {
				val += ll(g1 - gt[trd]);
			}
		}
		else {
			d -= sl[trd] * 2; val += ll(g1)*(2 * ll(sl[trd])) - ll(sl[trd])*ll(gt[trd]);
			if (sl[sed] > 0 && 2 * g1 > gt[sed]) {
				if (d <= sl[sed] * 2) {
					int x = d / 2;
					val += ll(x * 2) * ll(g1) - ll(x)*gt[sed];
					if (d % 2 == 1 && g1 > gt[sed]) val += ll(g1 - gt[sed]);
				}
				else  val += ll(g1)*(ll(sl[sed]) * 2) - ll(gt[sed])*ll(sl[sed]);					
			}
		}
	}
	cout << val << endl;
}
int main()
{
	solve();
//	system("pause");
    return 0;
}

