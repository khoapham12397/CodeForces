#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> ii;
typedef long long ll;
typedef pair<ll, int> li;
typedef vector<li> vii;
typedef unsigned long long ull;
int n, m, a[200010];
ll s[200010], inf = int(1e9) + 7, ck = 0, gtmax = -inf;
vii vtm;

ll BSearch(ll val,int l,int r) {
	if (l == r) {
		if (ll(val) <= ll(l)*ll(ck) + ll(gtmax)) return l;
		return l + 1;
	}
	int mid = (l + r) /2;
	ull gt = ull(mid)*ull(ck) + ull(gtmax);
	
	if (val == gt) return mid;
	if (val < gt) {
		if (mid > l) return BSearch(val, l, mid - 1);
		return l;
	}
	return BSearch(val, mid + 1, r);
}
int BSearch2(ll val,int l,int r) {
	if (l == r) {
		if (val <= vtm[l].first) return vtm[l].second;
		return vtm[l + 1].second;
	}
	int mid = (l + r) >> 1;
	if (val == vtm[mid].first) return vtm[mid].second;
	if (val < vtm[mid].first) {
		if (mid > l) return BSearch2(val, l, mid-1);
		return vtm[l].second;
	}
	return BSearch2(val, mid + 1, r);
}

ll cal(int x) {
	if (ck <= 0 && gtmax < x) {
		return -1;
	}
	ll t = 0;
	if (ck > 0){
		t = BSearch(x, 0,inf);
	}
	
	ll val = ll(x)- ll(t)*ll(ck);
	int id= BSearch2(val, 0, vtm.size() - 1);
	return ll(t)*ll(n) + ll(id) - ll(1);
}
void solve() {
	vtm.clear();
	cin >> n >> m; s[0] = 0; 
	ck = 0; gtmax = -inf;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = s[i - 1] + a[i]; gtmax = max(gtmax, s[i]);
	
	}
	ll u = s[1]; vtm.push_back(li(u, 1));
	for (int i = 2; i <= n; i++) {
		if (u < s[i]) {
			u = s[i]; vtm.push_back(li(u,i));
		}
	}
	ck = s[n];
	for (int i = 0; i < m; i++) {
		int x; cin >> x;
		cout<<cal(x)<<" ";
	}
	cout << endl;
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

