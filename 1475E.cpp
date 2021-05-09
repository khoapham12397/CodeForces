#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> ii;
typedef long long ll;
int n,k,a[1010];
ll fact[1010], mod = ll(1e9) + 7;
ll modPow(ll x, ll y) {
	ll ans = 1, z = x;
	while (y > 0) {
		if (y % 2 == 1) ans = (ans *z) % mod;
		z = (z*z) % mod;
		y >>= 1;
	}
	return ans%mod;
}
ll inv(ll x) {
	return modPow(x, mod - 2)%mod;
}
void solve() {
	cin >> n >> k;
	ll ans = 0;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	vector<ii> vtk; int t = 1;
	
	for (int i = n - 2; i >= 0; i--) {
		if (a[i] == a[i + 1]) t++;
		else {
			vtk.push_back(ii(a[i+1], t));
			t = 1;
		}
	}
	vtk.push_back(ii(a[0], t));
	t = 0;
	for (int i = 0; i < vtk.size(); i++) {
		if (t + vtk[i].second < k) t += vtk[i].second;
		else {
			int x = k - t; 
			if (x == vtk[i].second) { ans = 1; break; }
			else { ans = (fact[vtk[i].second] * ((inv(fact[vtk[i].second - x]) * inv(fact[x])) % mod)) % mod;  break; }
		}
	}
	cout << ans << endl;
}

int main()
{
	fact[0] = fact[1] = 1; 
	for (int i = 2; i <= 1000; i++) fact[i] = (fact[i - 1] * ll(i)) % mod;
	int T; cin >> T;
	for (int i = 0; i < T; i++) solve();
//	system("pause");
    return 0;
}

