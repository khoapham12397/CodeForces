#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
typedef vector<int> vi;
int n,m,f[200010],fr[200010];
string s, t;
vi pos[26];
int BSearchB(int val, int l,int r,int p) {
	if (l == r) {
		if (pos[p][l] > val) return pos[p][l];
		if (l < pos[p].size() - 1) return pos[p][l + 1];
		return -1;
	}
	int mid = (l + r) >> 1;
	if (pos[p][mid] == val) {
		return pos[p][mid + 1];
	}
	if (pos[p][mid] > val) {
		if (mid > l) return BSearchB(val, l, mid - 1, p);
		return pos[p][mid];
	}
	return BSearchB(val, mid + 1, r, p);
}

int BSearchS(int val,int l,int r,int p) {
	if (l == r) {
		if (pos[p][l] < val) return pos[p][l];
		if (l > 0) return pos[p][l - 1];
		return -1;
	}
	int mid = (l + r) >> 1;
	if (pos[p][mid] == val) {
		if (mid > 0) return pos[p][mid - 1];
		return -1;
	}

	if (pos[p][mid] > val) {
		if (mid > l) return BSearchS(val, l, mid - 1, p);
		if (mid > 0) return pos[p][l - 1];
	}
	return BSearchS(val, mid + 1, r, p);
}
void solve() {
	cin >> n >> m;
	cin >> s >> t;
	for (int i = 0; i < n; i++) {
		char x = s[i];
		pos[int(x) - 97].push_back(i);
	}
	f[0] = pos[int(t[0]) - 97][0];
	
	for (int i = 1; i < m; i++) {
		int x = f[i - 1];
		int p = int(t[i]) - 97;
		f[i] = BSearchB(f[i - 1], 0, pos[p].size() - 1, p);
	}
	int ind = int(t[m - 1]) - 97;
	int len = pos[ind].size();
	fr[m - 1] = pos[ind][len - 1];

	for (int i = m - 2; i >= 0; i--) {
		int p = int(t[i]) - 97;
		fr[i] = BSearchS(fr[i + 1], 0, pos[p].size() - 1, p);
	}
	int ans = 0;
	for (int i = 0; i < m - 1; i++) {
		int x = f[i] , y=fr[i+1]; 
		ans = max(ans, y - x);
	}
	cout << ans << endl;
}
int main()
{
	solve();
//	system("pause");
    return 0;
}

