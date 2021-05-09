#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
int n,a[200010],b[200010],k,pos[200010];
ll mod = 998244353;
void solve() {
	cin >> n >> k;

	for (int i = 1; i <= n; i++) cin >> a[i],pos[i]=0;
	for (int i = 1; i <= k; i++) cin >> b[i],pos[b[i]] = i;
	
	if (pos[a[1]] != 0 && pos[a[2]]!=0 && pos[a[1]] < pos[a[2]]) {
		cout << 0 << endl; return;
	}
	if (pos[a[n]] != 0 && pos[a[n - 1]] != 0 && pos[a[n]] < pos[a[n - 1]]) {
		cout << 0 << endl; return;
	}

	for (int i = 1; i <= n - 2; i++) {
		if (pos[a[i]] != 0 && pos[a[i + 1]] != 0 && pos[a[i + 2]] != 0 ) {
			if (pos[a[i + 1]] < pos[a[i]] && pos[a[i + 1]] < pos[a[i + 2]]) { cout << 0 << endl; return; }
		}
	}
	int t = k;
	if (pos[a[1]] != 0) t--;
	if (pos[a[n]] != 0) t--;
	for (int i = 1; i < n; i++) {
		if (pos[a[i]] != 0 && pos[a[i + 1]] != 0) t--;
	}
	ll ans = 1;
	for (int i = 0; i < t; i++) ans = (ans * 2) % mod;
	cout << ans << endl;
}
int main()
{
	int t; cin >> t;
	while (t--) solve();
//	system("pause");
    return 0;
}

