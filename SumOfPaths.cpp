
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef unsigned long long ull;
int n, k, q;
ull a[5001];
ull f[5001][5001],mod= 1000000000+7;
ull fr[5001];
void solve() {
	cin >> n >> k >> q;
	for (int i = 1; i <= n; i++) cin >> a[i],f[i][0]=1,fr[i]=0;
	
	for (int j = 1; j <= k; j++) {
		f[1][j] = f[2][j - 1]; f[n][j] = f[n - 1][j - 1];
		for (int i = 2; i < n; i++) {
			f[i][j] = (f[i - 1][j - 1] + f[i + 1][j - 1])%mod ;
		}
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k+1; j++) {
			fr[i]= (fr[i]+ ((f[i][j - 1] * f[i][k+1-j]) )%mod ) %mod;
		}
	}
	ull val = 0;

	for (int i = 1; i <= n; i++) {
		val = (val + (fr[i] * a[i])%mod)%mod;
	}
	for (int i = 0; i < q; i++) {
		int ind;
		ull x; cin >> ind >> x;
		val =(mod+ val- ((fr[ind] * a[ind]))%mod + ((fr[ind] * x)%mod  ))%mod;
		a[ind] = x;
		cout << val << endl;
	}
}
int main()
{
	solve();
//	system("pause");
    return 0;
}

