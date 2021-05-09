#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
ll n,k,M,D;
void solve() {
	cin >> n >> k >> M >> D;
	
	ll ans = M;
	
	for (ll t = 2; t <= D; t++) {
		ll x = ll(n / (k*(t - 1))) - 1;
		if (x > 0 && ll(n/x) <= (k*t) && x<=M) {
			ans = max(ans, t*x);
		}
		else
			if (ll(ll(n / M) / k) == t) ans = max(ans, t*M);
	}
	cout << ans << endl;
}
int main()
{
	solve();
//	system("pause");
    return 0;
}

