#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int n,s1[200010],s2[200010];
ii a[200010];
vii L,R;
int BSearchS(int val,int l,int r) {
	if (l == r) {
		if (R[l].first <= val) return s1[l];
		if (l > 0) return s1[l - 1];
		return 0;
	}

	int mid = (l + r) >> 1;
	if (R[mid].first == val) return s1[mid];
	if (R[mid].first > val) {
		if (l < mid) return BSearchS(val, l, mid - 1);
		if (l > 0) return s1[l - 1];
		return 0;
	}
	return BSearchS(val, mid + 1, r);
}
int BSearchB(int val, int l, int r) {
	if (l == r) {
		if (L[l].first >= val) return s2[l];
		if (l < L.size() - 1) return s2[l + 1];
		return 0;
	}
	int mid = (l + r) >> 1;
	if (L[mid].first == val) return s2[mid];
	if (L[mid].first > val) {
		if (mid > l) return BSearchB(val, l, mid - 1);
		return s2[l];
	}
	return BSearchB(val, mid + 1, r);
}
void solve() {
	cin >> n;
	L.clear(); R.clear();
	vi vl, vr; vl.assign(n, 0); vr.assign(n, 0);
	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		a[i].first  = vl[i] = x; 
		a[i].second = vr[i] = y;
	}
	sort(vl.begin(), vl.end()); sort(vr.begin(), vr.end());

	int t = 1,t1=1;
	for (int i = 1; i < n; i++) {
		if (vl[i] == vl[i - 1]) t++;
		else {
			L.push_back(ii(vl[i - 1], t));
			t = 1;
		}
		if (vr[i] == vr[i - 1]) t1++;
		else {
			R.push_back(ii(vr[i - 1], t1));
			t1 = 1;
		}
	}
	L.push_back(ii(vl[n - 1], t)); 
	R.push_back(ii(vr[n - 1], t1));
	
	s1[0] = R[0].second; 
	s2[L.size()-1] = L[L.size()-1].second;
	for (int i = 1; i < R.size(); i++) {
		s1[i] = s1[i - 1] + R[i].second;
	}
	for (int i = L.size()-2; i >=0 ; i--) s2[i] = s2[i+1] + L[i].second;
	int ans = int(1e9) + 7;
	for (int i = 0; i < n; i++) {
		int l = a[i].first, r = a[i].second;
		
		int x1 = BSearchS(l - 1, 0, R.size() - 1) ,x2= BSearchB(r + 1, 0,L.size() - 1);
	
		ans = min(ans,x1+x2);
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

