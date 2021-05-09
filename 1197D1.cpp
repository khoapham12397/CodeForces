#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l2;

ll n,m,k;
ll a[300001];
l2 c[300001];
ll gcd(ll x, ll y) {
	if (y == 0) return x;
	return gcd(y, x%y);
}
int cmp(l2 x, l2 y) {
	ll t = x.first - y.first;
	return t > 0;
}
l2 add(l2 x, l2 y) {
	ll ts = x.first + y.first;
	return l2(ts, x.second);
}
//minh can nhan xet dieu gi ???
//thu nhat la no luon la 
void solve() {
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		ll ts=a[i] * m - k;
		c[i].first = ts ;
		c[i].second = m ;
	}
	l2 u = l2(0, m),val=l2(0,m),gtmax=l2(0,m);
	int l = 0, r = 0,l1=0,r1=0;
	for (int i = 1; i <= n; i++) {
		l2 x = add(u, c[i]);
		if (x.first <0) {
			l = r = i + 1;
			u = l2(0, m);
		}
		else {
			if (cmp(x, gtmax)) {
				gtmax = x; u = x;
				r = i;
				l1 = l; r1 = r;
			}
			else r = i;
		}
	}
	ll v = 0;
	for (int i = l1; i <= r1; i++) {
		v += a[i];
	}
	ll len = r1 - l1 + 1,gt= len/m;
	if (len%m != 0) gt++;
	v -= gt*k; v = max(v, 0);
	cout << v << endl;
	
}
int main()
{
	solve();
//	system("pause");
    return 0;
}

