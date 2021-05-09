#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
int n,m;
int a[1001][1001];
vector<int> in0[1001], out0[1001],in1[1001],out1[1001];
void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		in0[i].clear(); out0[i].clear(); in1[i].clear(); out1[i].clear();
	}
	for (int i = 1; i <= n; i++) {
		string s; cin >> s;
		for (int j = 0; j < n; j++) {
			if (s[j] == 'a') {
				a[i][j + 1] = 0; in0[j + 1].push_back(i), out0[i].push_back(j+1);
			}
			if (s[j] == 'b') a[i][j + 1] = 1, in1[j + 1].push_back(i), out1[i].push_back(j + 1);
		}
	}
	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (a[i][j] == a[j][i]) {
				cout << "YES" << endl;
				for (int k = 0;k <= m; k++) {
					if (k % 2 == 0) cout << i << " ";
					else cout << j << " ";
				}
				cout << endl;
				return;
			}
		}
	}
	if (m == 1) {
		cout << "YES" << endl; 
		cout << 1<<" "<<2 << endl; return;
	}
	if (n == 2 && m%2==0) { cout << "NO" << endl; return; }
	
	cout << "YES" << endl;

	if (m % 2 == 1) {
		for (int i = 0; i <= m; i++) {
			if (i % 2 == 0) cout << 1 << " ";
			else cout << 2 << " ";
		}
		cout << endl;
		return;
	}
	
	if (m % 4 == 2) {
		for (int i = 1; i <= n; i++) {
			if (in0[i].size() > 0 && out0[i].size() > 0) {
				int u = in0[i][0], v = out0[i][0];
				int t = m / 2; t = (t - 1) / 2;
				for (int j = 0; j <= t; j++) cout << u << " " << i << " ";
				cout << v << " ";
				for (int j = 0; j < t; j++) cout << i << " " << v << " "; cout << endl;
				return;
			}
			if (in1[i].size() > 0 && out1[i].size() > 0) {
				int u = in1[i][0], v = out1[i][0];
				int t = m / 2; t = (t - 1) / 2;
				for (int j = 0; j <= t; j++) cout << u << " " << i << " ";
				cout << v << " ";
				for (int j = 0; j< t; j++) cout << i << " " << v << " "; cout << endl;
				return;
			}
		}
	}
	if (m % 4 == 0) {
		for (int i = 1; i <= n; i++) {
			if (out0[i].size() > 0 && out1[i].size() > 0) {
				int u = out0[i][0],v=out1[i][0];
				int t = m / 4;
				for (int j = 0; j < t; j++) cout << i << " " << u << " ";
				cout << i<<" ";
				for (int j = 0; j < t; j++) cout << v << " " << i << " ";
				cout << endl; return;
			}
		}
	}
}
int main()
{
	int T; cin >> T;
	for (int i = 0; i < T; i++) {
		solve();
	}
//	system("pause");
    return 0;
}

