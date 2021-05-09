#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll; 
int X, Y;
ll ghp = ll(1e9)+7,L;
int BSearch(ll t, ll l, ll r) {
	if (l == r) {
		if ((l - t)*(l + 1) <= X) return l;
		return l - 1;
	}
	ll mid = (l + r) / 2;
	ll val = (mid - t)*(mid + 1);
	if (val == X) return mid;
	if (val > X) {
		if (mid > l) return BSearch(t, l, mid - 1);
		return l - 1;
	}
	return BSearch(t, mid + 1, r);
}
int BSearch2(ll t,ll l,ll r) {
	if (l == r) {
		if ((l + 1)*t <= X) return l;
		return l - 1;
	}
	ll mid = (l + r) / 2;
	ll val = (mid+1)*t;
	if (val == X) return mid;
	if (val > X) {
		if (mid > l) return BSearch2(t, l, mid - 1);
		return l - 1;
	}
	return BSearch2(t, mid + 1, r);
}
void solve() {
	
	cin >> X >> Y;
	ll  t=1,ans=0,mid=0;
	mid = BSearch(t, 1,Y);
	ans += (mid - 1)*mid / 2;
	L = mid + 1;
	for (int i = mid -1; i >= 1; i--) {
		if (L > Y) break;
		ll ind = BSearch2(i, L, Y);
		ans += (ind - L + 1)*i;
		L = ind + 1;
	}
	cout << ans << endl;
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

