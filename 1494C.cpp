#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
int n, m, trung[2][200010], pos[2][200010], sp[2][200010];

ii BSearch(int val, int l, int r, int type) {
	if (l == r) {
		if (val == pos[type][l]) return ii(l, l);
		if (val > pos[type][l]) return ii(l, l + 1);
		return ii(l - 1, l);
	}
	int mid = (l + r) >> 1;

	if (pos[type][mid] == val) return ii(mid, mid);
	if (pos[type][mid] > val) {
		if (mid > l) return BSearch(val, l, mid - 1, type);
		return ii(l - 1, l);
	}
	return BSearch(val, mid + 1, r, type);
}
ii BSearchSp(int val, int l, int r, int type) {
	if (l == r) {
		if (val == sp[type][l]) return ii(l, l);
		if (val > sp[type][l]) return ii(l, l + 1);
		return ii(l - 1, l);
	}
	int mid = (l + r) >> 1;
	if (sp[type][mid] == val) return ii(mid, mid);
	if (sp[type][mid] > val) {
		if (mid > l) return BSearchSp(val, l, mid - 1, type);
		return ii(l - 1, l);
	}
	return BSearchSp(val, mid + 1, r, type);
}
void solve() {
	cin >> n >> m;
	int i = 0, lens[2], lenp[2], ls0 = 0, ls1 = 0, lp0 = 0, lp1 = 0;
	lens[0] = lens[1] = lenp[0] = lenp[1] = 0;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		if (x < 0) pos[0][lp0] = -x, lp0++;
		else pos[1][lp1] = x, lp1++;
	}
	for (int i = 0; i < m; i++) {
		int x; cin >> x;
		if (x < 0) sp[0][ls0] = -x, ls0++;
		else sp[1][ls1] = x, ls1++;
		trung[0][i] = 0; trung[1][i] = 0;
	}
	trung[0][m] = trung[1][m] = 0;
	lens[0] = ls0, lens[1] = ls1, lenp[0] = lp0, lenp[1] = lp1;
	for (int i = 0; i < lp0 / 2; i++) {
		int x = pos[0][i]; pos[0][i] = pos[0][lp0 -1- i];
		pos[0][lp0 - 1 - i] = x;
	}
	for (int i = 0; i < ls0 / 2; i++) {
		int x = sp[0][i]; sp[0][i] = sp[0][ls0 - 1 - i];
		sp[0][ls0 - 1 - i] = x;
	}
	int ans[2]; ans[0] = ans[1] = 0;
	for (int type = 0; type < 2; type++) {
		if(lenp[type] == 0 || lens[type]==0) continue;
		for (int i = lens[type]-1; i >=0; i--) {
			int x = sp[type][i];
			ii ind = BSearch(x, 0, lenp[type] - 1, type);
			trung[type][i] = trung[type][i + 1] + (ind.first == ind.second);
			int k = ind.first + 1;
			int y = x - k + 1;
			ii id = BSearchSp(y, 0, lens[type] - 1, type);
			int temp;
			
			if (id.first == id.second) {
				temp = i - id.first + 1;
			}
			else temp = i - id.first;
			temp += trung[type][i + 1];
			
			ans[type] = max(ans[type], temp);
		}
	}
	
	cout <<  ans[0] + ans[1] << endl;
}
int main()
{
	int t; cin >> t;
	while (t--) solve();

//	system("pause");
	return 0;
}

