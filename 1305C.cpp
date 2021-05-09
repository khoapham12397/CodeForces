#include <iostream>
#include <algorithm>
using namespace std;
int n,m,a[200001],f[1000];

void solve() {
	cin >> n >> m;
	int ans = 1;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < m; i++) f[i] = 0;
	for (int i = 0; i < n; i++) f[a[i] % m]++;
	for (int i = 0; i < m; i++) if (f[i] > 1) {
		cout << 0 << endl; return;
	}
	for (int i = 0; i < n-1; i++) {
		for (int j = i + 1; j < n; j++) {
			int x = abs(a[i] - a[j])%m;
			ans = (ans*x) % m;
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

