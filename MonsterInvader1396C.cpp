
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
ll gtMAX= 10e17;
ll n,a[1000001],r1,r2,r3,D;
//tong time la b
ll F[1000001];
void solve() {
	cin >> n >> r1 >> r2 >> r3 >> D;
	for (int i = 0; i < n; i++) cin >> a[i];
	if (n == 1) { cout << a[0] * r1 + r3 << endl; return; }
	F[0] = a[0] * r1 + r3;
	F[1] = min(a[0] * r1 + r3 + D + a[1] * r1 + r3, 3*D + 2*r2+2*r1);
	for (int i = 2; i < n; i++) {
		ll x = F[i-1] + min(D + a[i] * r1 + r3, 3 * D + r2 + r1);
		ll y = F[i - 2] + D * 4 + 2 * (r1 + r2);
		F[i] = min(x, y);
	}
	
	ll u = min(2 * D + a[n - 1] * r1 + r3, 4 * D + r2 + r1);
	ll ans = (r2+r1)*(n-1)+2*D*(n-2)+min(2 * D + a[n - 1] * r1 + r3, 4 * D + r2 + r1);
	for (int i = 1; i <= n - 2; i++) {
		ll val = F[i - 1] + (r2 + r1)*(n - 1 - i) + 2*D*(n - 2 - i) + u + D;
		ans = min(ans, val);
	}
	ans = min(ans, F[n - 1]);
	cout << ans << endl;
}
int main()
{
	solve();
//	system("pause");
    return 0;
}

