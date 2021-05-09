#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
int n,k,a[510],b[510];
vector<ii> cans[510];
void solve() {
	cin >> n >> k;
	ll s = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
		s += ll(a[i]) + ll(b[i]);
	}
	
	queue<ii> q; q.push(ii(a[0]%k,b[0]%k));
	int t = 1;
	for (int i = 1; i < k; i++) {
		int x = a[0] - i,y= b[0] -k+i;
		if (x >= 0 && y >= 0) q.push(ii(x%k,y%k)),t++;
	}
	for (int i = 1; i < n; i++) {
		cans[i].push_back(ii(a[i] % k, b[i] % k));
		for (int r = 0; r < k; r++) {
			int x = a[i] - r, y = b[i] - k + r;
			if (x >= 0 && y >= 0) cans[i].push_back(ii(x%k, y%k));
		}
	}
	
	for (int i = 1; i < n; i++) {
		bool temp[500][500] = {0};
		int sl = 0;
		for (int j = 0; j < t; j++) {
			ii front = q.front(); q.pop();
			int u = front.first, v = front.second;
			for (int j1 = 0; j1 < cans[i].size(); j1++) {
				int x = (u + cans[i][j1].first) % k, y = (v + cans[i][j1].second) % k;
				if (!temp[x][y]) {
					temp[x][y] = 1; q.push(ii(x, y)); sl++;
				}
			}
		}
		t = sl;
	}

	int ans = int(1e9) + 7;
	while (!q.empty()) {
		ii front = q.front(); q.pop();
		int x = (front.first %k) + (front.second %k);
		ans = min(ans, x);
	}
	cout << (s-ll(ans))/ll(k) << endl;
}
int main()
{
	solve();
//	system("pause");
    return 0;
}

