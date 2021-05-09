#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
map<int, ii> xh;
int n,a[200010],s[200010],X=0,Y=0,Z=0,sr[200010];
int ST[1000001],inf=int(1e9)+7;
vii vt;
void build(int id,int l,int r) {
	if (l == r) {
		ST[id] = a[l]; return;
	}
	int mid = (l + r) >> 1;
	build(2 * id, l, mid);
	build(2 * id + 1, mid + 1, r);
	ST[id] = min(ST[2 * id], ST[2 * id + 1]);
}
int BSearch(int val, int l, int r) {
	if (l == r) {
		if (vt[l].first == val) return vt[l].second;
		return -1;
	}
	int mid = (l + r) / 2;
	if (vt[mid].first == val) return vt[mid].second;
	if (vt[mid].first > val) {
		if (mid > l) return BSearch(val, l, mid - 1);
		return -1;
	}
	return BSearch(val, mid + 1, r);
}
int getMin(int id,int l,int r,int u,int v) {
	if (l > v || r < u) return inf;
	if (l >= u && r <= v) return ST[id];
	int mid = (l + r) / 2;
	return min(getMin(2 * id, l, mid, u, v), getMin(2 * id + 1, mid + 1, r, u, v));
}
void solve() {
	vt.clear(); xh.clear();
	cin >> n;
	X = 0, Y=0, Z = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	s[1] = a[1]; sr[n] = a[n];
	xh[a[1]] = ii(1, 0);
	for (int i = 2; i <= n; i++) {
		s[i] = max(s[i - 1], a[i]);
		ii u = xh[a[i]];
		if (u.first == 0) xh[a[i]] = ii(i, 0);
		else if (u.second == 0) xh[a[i]] = ii(i, 1);
	}
	int ind = n,gtmax= a[n];
	for (int i = n - 1; i >= 1; i--) {
		if (a[i] > gtmax) {
			vt.push_back(ii(gtmax,ind));
			gtmax = a[i]; ind = i;
		}
		else ind = i;
		sr[i] = gtmax;
	}
	

	vt.push_back(ii(gtmax, ind));
	
	build(1, 1, n);
	for (int i = 1; i <= n-2; i++) {
		int x = s[i];
		int ir = BSearch(x, 0, vt.size() - 1);
		if (ir != -1) {
			if (ir <= i) {
				int mid=xh[x].first;
				if (mid < n && sr[mid + 1] == x) {
					X = mid - 1, Y = 1, Z = n - mid;
					break;
				}
			}
			int r= ir-1;
			if (ir < n && a[ir] == x && sr[ir+1]==x) r++;
			if (i+1 <= r && getMin(1,1,n,i+1,r)==x) {
				X = i, Y = r - i, Z = n - r;
				break;
			}
		}
	}
	if (X != 0) {
		cout << "YES" << endl;
		cout << X << " " << Y << " " << Z << endl;
	}
	else cout << "NO" << endl;
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

