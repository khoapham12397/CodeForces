#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> ii;
int n,a,m,up[2010],s[2010],f[2010],pos[2010];
int inf = int(1e9);
bool d[2010];
vector<ii> us;
void solve() {
	cin >> a >> n >> m;
	for (int i = 0; i <= a; i++) d[i] = 0, up[i] = 0;
	for (int i = 0; i < n; i++) {
		int l, r; cin >> l >> r;
		for (int j = l; j < r; j++) d[j] = 1;
	}
	for (int i = 0; i < m; i++) {
		int x, p; cin >> x >> p;
		us.push_back(ii(x, p));
	}
	sort(us.begin(), us.end());
	int t = 0;
	for (int i = 0; i < m; i++) {
		int x = us[i].first;
		if (up[x] == 0) t++, up[x] = us[i].second, pos[t] =x;
	}
	s[0] = int(up[0] > 0);
	for (int i = 1; i <= a; i++) {
		s[i] = s[i - 1] + int(up[i] > 0);
	}
	f[0] = 0;
	for (int i = 1; i <= a; i++) {
		if (!d[i - 1]) f[i] = f[i - 1];
		else f[i] = inf;
		for (int j = 1; j <= s[i - 1]; j++) {
			int x = pos[j];
			f[i] = min(f[x] + up[x] * (i - x), f[i]);
		}
	}
	if (f[a] == inf) cout << -1 << endl;
	else cout << f[a] << endl;
}
int main()
{
	solve();
//	system("pause");
    return 0;
}

