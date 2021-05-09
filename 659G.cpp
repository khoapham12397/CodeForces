#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
int n,a[1000010];
ll mod = ll(1e9) + 7, f[1000010], fr[1000010],s[1000010];
void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	f[0] = a[0] - 1;
	if (a[0] <= a[1]) {
		fr[0] = f[0];
	}
	else fr[0] = a[1] - 1;
	
	s[0] = f[0];
	for (int i = 1; i < n; i++) {
		
		if (a[i] > a[i - 1]) {
			f[i] = (ll(a[i] - 1) + ((fr[i-1] * ll(a[i - 1] - 1)) % mod)) % mod;
		}
		else {
			f[i] = (ll(a[i] - 1)*(1 + fr[i - 1])) % mod;
		}
		s[i] = (s[i - 1] + f[i]) % mod;
		if (i< n-1) {
			if (a[i] < a[i + 1]) {
				if (a[i] > a[i - 1]) {
					fr[i] = (ll(a[i] - 1) + ((ll(a[i - 1] - 1) * fr[i - 1]) % mod)) % mod;
				}
				else {
					// a[i]<=a[i-1] && a[i]<a[i+1]:
					fr[i] = (ll(a[i] - 1)*(1 + fr[i - 1])) % mod;
				}
			}
			else {
				// a[i] >=a[i+1]:
				if (a[i] > a[i - 1]) {
					fr[i] = (ll(a[i + 1] - 1) + ((ll(min(a[i - 1], a[i + 1]) - 1)*fr[i - 1]) % mod)) % mod;
				}
				else fr[i] = (ll(a[i + 1] - 1)*(1 + fr[i - 1])) % mod;
			}
		}
	}
	cout << s[n - 1] << endl;
}
int main()
{
	solve();
//	system("pause");
    return 0;
}

