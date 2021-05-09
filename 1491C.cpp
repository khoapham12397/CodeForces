#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
int n,a[5010];
void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	ll t = 0;
	int i = 1;
	
	while(i<=n) {
		if (i<n && a[i] > n - i) {
			t += ll(a[i] - n + i);
			a[i] = n - i;
		}
		if (i == n && a[i] > 1) {
			t += a[n] - 1;
			break;
		}
		int del =a[i]-1;
		t+= ll(del);
		while (del--) {
			int ind = i;
			
			while (ind <= n) {
				int x = a[ind];
				a[ind] = max(x - 1, 1);
				ind += x;
			}
		}
		i++;
	}
	cout << t << endl;
}
int main()
{
	int t; cin >> t;
	while(t--) solve();
//	system("pause");
    return 0;
}

