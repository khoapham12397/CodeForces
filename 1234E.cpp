#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
int n,m;
int a[200010];
ll f[200010];
vector<int> vtl,vtr;
vector<ii> vl, vr;
int BSearchL(int val ,int l,int r) {
	if (l == r) {
		if (vl[l].first <val) return vl[l].second + 1;
		if (l == 0) return 0;
		return vl[l - 1].second + 1;
	}
	int mid = (l + r) >> 1;
	
	if (val == vl[mid].first) {
		if (mid > 0) return vl[mid - 1].second + 1;
		else return 0;
	}
	if (vl[mid].first > val) {
		if (mid > l) return BSearchL(val, l, mid - 1);
		if (l > 0) return vl[l - 1].second + 1;
		return 0;
	}
	return BSearchL(val, mid + 1, r);
}

int BSearchR(int val, int l, int r) {
	if (l == r) {
		if (vr[l].first<=val) return vr[l].second + 1;
		if (l == 0) return 0;
		return vr[l - 1].second + 1;
	}
	int mid = (l + r) >> 1;

	if (val == vr[mid].first) return vr[mid].second + 1;
	if (vr[mid].first > val) {
		if (mid > l) return BSearchR(val, l, mid - 1);
		if (l > 0) return vr[l - 1].second + 1;
		return 0;
	}
	
	return BSearchR(val, mid + 1, r);
}
void solve() {
	cin >> n >> m;
	ll val = 0;
	for (int i = 1; i <= m; i++) {
		cin >> a[i];
	}
	for (int i = 2; i <= m; i++) val += abs(a[i] - a[i - 1]);
	for (int i = 1; i <= n; i++) f[i] = val;
	
	int x = a[1],l,r;
	
	for (int i = 2; i <= m; i++) {
		int y = a[i];
		if (x < y) l = x, r = y;
		else l = y, r = x;
		if (r != l) {
			f[l] += l - 1, f[r] = f[r] - (r - l) + l;
			vtl.push_back(l);
			vtr.push_back(r);
		}
		x = y;
	}
	sort(vtl.begin(), vtl.end());
	sort(vtr.begin(), vtr.end());
	
		
	for (int i = 1; i < vtl.size(); i++) {
		if (vtl[i] != vtl[i - 1]) {
			vl.push_back(ii(vtl[i - 1], i-1));
		}
		
	}
	
	vl.push_back(ii(vtl[vtl.size() - 1], vtl.size() - 1));
	for (int i = 1; i < vtr.size(); i++) {
		if (vtr[i] != vtr[i - 1]) {
			vr.push_back(ii(vtr[i - 1], i - 1));
		}
	}
	vr.push_back(ii(vtr[vtr.size() - 1], vtr.size() - 1));
	for (int i = 2; i < n; i++) {
		int sl = BSearchL(i, 0, vl.size() - 1);
		int sr = BSearchR(i, 0, vr.size() - 1);
		int s = sl - sr;
		f[i] -= s;
	}
	for (int i = 1; i <= n; i++) cout << f[i] << " ";
	cout << endl;
}

int main()
{
	solve();
//	system("pause");
    return 0;
}

