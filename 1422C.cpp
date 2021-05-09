#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;
ll p10[100010],mod=ll(1e9) +7,s[100010];

void solve() {
	string sr,s1=""; cin >> sr;
	int n = sr.length();
	ll ans =0;
	s[0] = 0;
	for (int i = 1; i < n; i++) {
		s[i] = (s[i - 1] + p10[i - 1] * ll(i)) % mod;
	}
	
	for (int i = n - 1; i >= 0; i--) s1 += sr[i];
	ll val = (ll(n - 1)*ll(n) / 2)%mod;
	ans =(ll(int(s1[0]) - 48)*val) % mod;
	for (int i = 1; i < n; i++) {
		int x = int(s1[i]) - 48;
		
		if (x == 0) continue;
		ll val = (((ll(n - i - 1)*ll(n - i) / 2)) % mod) % mod;
		
		ll gt = (((((s[i] * ll(x)) % mod)) % mod) + ((((ll(x) * p10[i]) % mod) * val) % mod)) % mod;
		ans = (ans + gt) % mod;
	
	}
	
	cout << ans << endl;
}
int main()
{
	p10[0] = 1;
	for (int i = 1; i <= 100001; i++) {
		p10[i] = (p10[i - 1] * 10) % mod;
	}
 	solve();
    return 0;
}

