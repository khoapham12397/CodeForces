#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
using namespace std;
bitset<10010> bs;
typedef  long long ll;
ll f[10000010], a[10000010], n = 10000000, unt[10000010];

void sieve(ll up) {
	bs.set();
	bs[0] = bs[1] = 0;
	for (ll i = 2; i <= up; i++) {
		if (bs[i]) {
			for (ll j = i*i; j <= n; j += i) {
				if(j<3164) bs[j] = 0;
				unt[j] = i;
			}
		}
	}
}
void init() {
	sieve(3163);
	f[1] = 1; f[2] = 3; f[3] = 4;
	a[1] = 1; a[3] = 2; a[4] = 3;
	for (ll i = 4; i <= n; i++) {
		if (unt[i]==0) {
			f[i] = ll(i) + 1;
			if(a[i+1]==0) a[i + 1] = ll(i);
			
		}
		else {
			int p = unt[i], x = i;
			ll y = ll(p);
			while (x%p == 0) {
				x /= p; y = y*ll(p);
			}
			ll val = (y - 1) / (ll(p) - 1);
		
		
			f[i] = val * f[x];
		
			if (f[i] <= ll(n)) {
				if (a[f[i]] == 0) a[f[i]] = i;
			}
		}
	}
}
int main() {
	init();
	int t; cin >> t;
	
	while (t--) {
		int x; cin >> x;
		if (a[x] != 0) cout << a[x] << endl;
		else cout << -1 << endl;
	}
//	system("pause");
	return 0;
}
