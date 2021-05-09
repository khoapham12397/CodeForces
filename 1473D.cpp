#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
typedef pair<int, int> ii;
int n,a[200010],m;
ii s1[200010], s2[200010];
void solve() {
	a[0] = 0;
	cin >> n >> m;
	string st; cin >> st;
	s1[0] = ii(0, 0);

	for (int i = 0; i < st.length(); i++) {
		a[i+1] = a[i]; 
		if (st[i] == '+') a[i + 1]++;
		else a[i + 1]--;
		s1[i + 1].first = max(s1[i].first, a[i + 1]);
		s1[i + 1].second = min(s1[i].second, a[i + 1]);
	}
	s2[n+1] = ii(0, 0);
	int x = 0;
	for (int i = n-1; i >= 0; i--) {
		if (st[i] == '+') {
			s2[i + 1].first = max(0,s2[i + 2].first) + 1;
			s2[i + 1].second = min(0,s2[i + 2].second) + 1;
		}
		else {
			s2[i + 1].first = max(0,s2[i + 2].first) - 1;
			s2[i + 1].second = min(0,s2[i + 2].second) - 1;
		}
	}

	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		int u = s1[x - 1].first, v = s1[x - 1].second;
		
		int c = a[x - 1] + s2[y + 1].first, d = a[x - 1] + s2[y + 1].second;
		cout << max(u, c) - min(v, d) + 1 << endl;
	}
}
int main()
{
	int t; cin >> t;
	while (t--) solve();
//	system("pause");
    return 0;
}

