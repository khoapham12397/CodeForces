#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
typedef vector<int> vi;
int n,a[200010];
bool dp[200010][26];
string s;
vi pos[26];
int BSearch(int val,int l,int r,int p) {
	if (l == r) {
		if (pos[p][l] > val) return pos[p][l];
		if (l < pos[p].size() - 1) return pos[p][l + 1];
		return -1;
	}
	int mid = (l + r) >> 1;
	if (pos[p][mid] == val) {
		if (mid < pos[p].size() - 1) return pos[p][mid + 1];
		return -1;
	}
	if (pos[p][mid] > val) {
		if (mid > l) return BSearch(val, l, mid - 1, p);
		return pos[p][mid];
	}
	return BSearch(val, mid + 1, r, p);
}
void solve() {
	cin >> s;
	n = int(s.length());
	for (int j = 0; j < 26; j++) dp[n + 1][j] = 0,pos[j].clear();
	vi vt;
	for (int i = n; i >=1; i--) {
		a[i] = int(s[i - 1]) - 97;
		for (int j = 0; j < 26; j++) dp[i][j] = dp[i + 1][j];
		int p = int(s[i - 1]) - 97;
		dp[i][p] = 1;
	}
	for (int i = 1; i <= n; i++) {
		int p = int(s[i - 1]) - 97;
		pos[p].push_back(i);
	}
	for (int i = 0; i < 26; i++) if (dp[1][i]) vt.push_back(i);
	string ans = "";
	int l = 0;
	while (vt.size() > 0) {
		for (int j = vt.size() - 1; j >= 0; j--) {
			int p = vt[j];
			int ind = BSearch(l, 0, pos[p].size() - 1, p);
			if (ind != -1) {
				bool ok = true;
				for (int id = 0; id < vt.size() - 1; id++) {
					if (!dp[ind][vt[id]]) { ok = false; break; }
				}
				if (ok) {
					ans += char(p + 97);
					vt.erase(vt.begin() + j);
					l = ind;
					break;
				}
			}
		}
	}
	cout << ans << endl;
}
int main()
{
	int t; cin >> t;
	while(t--) solve();
//	system("pause");
    return 0;
}

