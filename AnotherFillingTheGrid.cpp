#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
ll mod = 1000000007;

ll C[251][251], a[251];
int n,k;

ll modPow(int x,int y) {
	ll ans = 1,z=x;
	while (y > 0) {
		if (y % 2 == 1) ans = (ans*z)%mod;
		z= (z*z)%mod;
		y = y >> 1;
	}
	return ans;
}

int inv(ll x) {
	return modPow(x, mod - 2);
}
void solve() {
	
	
	cin >> n >> k;
	for (int i = 0; i <= n; i++) C[0][i] = C[i][i] = 1;
	for (int i = 2; i <= n; i++) {
		C[1][i] = i%mod;
		for (int j = 2; j < i; j++) C[j][i] = (C[j][i - 1] + C[j - 1][i - 1]) % mod;
	}
	ll r = 0,om= modPow((modPow(k,n)+ (mod- modPow(k-1,n))%mod)%mod,n);
	for (int i = 1; i < n; i++) {
		ll y = modPow((modPow(k,n-i) + (mod-modPow(k-1,n-i))%mod)%mod,n);
		ll z = modPow(k - 1, n*i);
		
		ll x =(y*z) % mod;
		
		x = (x* C[i][n]) % mod;
		if (i % 2 == 1) r = (r + x) % mod;
		else r = (r + (mod - x) % mod) % mod;
	}
	cout<<(om + (mod - r) % mod) % mod<<endl;
	
}
int main()
{
	solve();
//	system("pause");
    return 0;
}

