#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
ll k, n, M, D;
void solve() {
	cin >> n >> k >> M >> D;
	ll ghd = n / M;
	if(ghd==1) {
		cout<<M<<endl; return;
	}
	if (ll(n/ghd) > M) ghd++;
	if(n==M || n==k) {
		cout<<M<<endl; return;
	}

	ll ans=M;
	

	for (int u = 1; u <= D; u++) {
		ll  l = max(1 + ll(u - 1)*k, ghd);
		if(n< l) break;
		ll r = ll(u)*k;
		if (l > r) continue;
		
		ll t = l;
		if (ans >= ll(u)* ll(n / t)) continue;

		while (t < r && ll(n / t) <= ll(n%t))t++;
		ll x = n / t;
		ans = max(ans, x*ll(u));
	}
	cout << ans << endl;
}
int main()
{
	solve();
//	system("pause");
    return 0;
}

