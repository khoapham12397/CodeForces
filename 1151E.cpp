#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
int n,a[100010];
void solve() {
	cin >> n; a[0] = 0;
	for (int i = 1; i <= n; i++) cin >> a[i];
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] < a[i + 1]) {
			//  a[i+1] =>l >= a[i] + 1
			// n>= r>= a[i+1]
			ans += ll(a[i + 1] - a[i]) * ll(n - a[i + 1] + 1);
		}
		if (a[i] > a[i + 1]) {
			// 1<=l<= a[i+1] , a[i+1] <= r <= a[i]-1
			ans += ll(a[i + 1])* ll(a[i] - a[i + 1]);
		}
	}
	cout << ans << endl;
}
int main()
{
	solve();
//	system("pause");
    return 0;
}

