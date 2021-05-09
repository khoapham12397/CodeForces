#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef unsigned long long ll;
ll n,m,L,R;
ll mod = ll(998244353); 
ll modPow(ll x,ll y) {
	ll z = x,ans=1;
	while (y > 0) {
		if (y % 2 == 1) ans = (ans*z) % mod;
		z = (z*z) % mod;
		y >>= 1;
	}
	return ans%mod;
}
void solve() {
	cin >> n >> m >> L >> R;
	if (n % 2 == 1 && m % 2 == 1) {
		
		cout << modPow(R - L + 1, m*n)<<endl;
	}
	else {
		int a, b;
		int r = R % 2,l=L%2;
		ll ans;
		if (r!=l) a = b = ((R - L + 1) / 2);
		if (r==1 && l==1) a = ((R - L) / 2)+1, b = a -1;
		if (r==0 && l==0) a = ((R - L) / 2), b = a + 1;
		
		if(b==a) ans= (modPow(ll(2),ll(m*n)-ll(1))*modPow(a,ll(m*n)))%mod;
		if(b>a) ans=(((modPow(ll(a+b),ll(m*n))+modPow(ll(b-a),ll(m*n)))%mod)*modPow(ll(2),mod-2))%mod;
		if(b<a) ans= (((modPow(ll(a+b),ll(m*n))+ modPow(ll(a-b),ll(m*n)))%mod )*modPow(ll(2),mod-2))%mod;
		cout<<ans<<endl;
	}
}
int main()
{
	solve();
//	system("pause");
    return 0;
}

