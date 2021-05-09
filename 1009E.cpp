#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
ll mod = 998244353,ans=0;
int n,a[1000001];
ll f[1000001];

void solve() {
	cin >> n;
	f[0] = 1;
	for (int i = 1; i <= n; i++) {
		f[i] = (f[i - 1] * 2) % mod;
	}
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i < n; i++) {
		ans = (ans + (((((f[n-i-1]*(n - i)) % mod) + f[ n - i]) % mod)*a[i])%mod) % mod;
	}
	ans = (ans+a[n])%mod;
	cout << ans << endl;
}
int main(){
	solve();
	//system("pause");
	return 0;
}

