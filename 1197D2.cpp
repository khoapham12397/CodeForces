#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
int n, m, k, a[300001];
ll b[300001];
void solve() {
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		ll u = ll(i) / ll(m); if (i%m != 0) u++;
		b[i] = u*ll(k);
	}
	ll val = 0,gtmax=0;
	int j = 0;
	while (j < n && a[j] <= 0) j++;
	if (j < n) {
		gtmax = max(gtmax, ll(a[j]) - b[1]);
		int t = 1;
		val=ll(a[j]);
		for (int i = j + 1; i < n; i++) {
			ll x = val + ll(a[i]);
			if (x > 0) {
				t++;
				if (a[i] > 0) {
					gtmax = max(gtmax, x - b[t]);
				}
				val = x;
			}
			else {
				val = 0; t = 0;
			}
		}
	}
	cout << gtmax << endl;
	
}
int main()
{
	solve();
//	system("pause");
    return 0;
}

