#include <iostream>
#include <algorithm>
#include <vector>
using namespace std; 
typedef unsigned long long ll;
typedef pair<int, int> ii;
int n, a[200001];
int freq[1000010];
vector<ii> tk;
ll mod = 1000000007;
ll ans = 0;
ll f[1000001];
ll powMod(ll x, ll y) {
	ll ans = 1, z = x;
	while (y > 0) {
		if (y % 2 == 1) ans = (ans*z) % mod;
		z = (z*z) % mod;
		y >>= 1;
	}
	return ans;
}
int BSearch(int val,int l,int r) {
	if (l == r) {
		if (tk[l].first == val) return tk[l].second;
		return 0;
	}
	int mid = (l + r) / 2;
	if (tk[mid].first == val) return tk[mid].second;
	if (tk[mid].first > val) {
		if (mid > l) return BSearch(val, l, mid - 1);
		return 0;
	}
	return BSearch(val, mid + 1, r);
}
void solve() {
	cin >> n;
	int maxA = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i]; 
		maxA = max(a[i], maxA);
	}
	sort(a, a + n);
	int sl = 1;
	for (int i = 1; i < n; i++) {
		if (a[i] != a[i - 1]) {
			tk.push_back(ii(a[i - 1], sl));
			sl = 1;
		}
		else sl++;
	}
	tk.push_back(ii(a[n - 1], sl));
	
	for (int i=2; i <= maxA; i++) {
		int j = 1;
		while (i*j <= maxA) {
			freq[i] += BSearch(i*j, 0, tk.size() - 1);
			j++;
		}
	}
	
	f[maxA] = (powMod(2, freq[maxA] - 1)*freq[maxA]) % mod;

	ans = f[maxA] * maxA;
	for (int i = maxA-1; i >= 2; i--) {
		int j = 2;
		ll val = (powMod(2, freq[i]-1)*freq[i])%mod;

		while (i*j <= maxA) {
			int x = i*j;
			val = (val + (mod - f[x]) % mod) % mod;
			j++;
		}
		f[i] = val;
		ans = (ans + (val*i) % mod) % mod;
	}
	cout << ans << endl;
	
}
int main() {
	solve();
//	system("pause");
	return 0;
}