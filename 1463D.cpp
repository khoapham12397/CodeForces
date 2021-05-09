#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n,a[400001];
void solve() {
	for (int i = 1; i <= 2*n; i++) a[i] = 0;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		a[x] = 1;
	}
	int sl0 = 0, sl1 = 0,r0=0,t=0;
	for (int i = 1; i <= n; i++) {
		if (a[i] == 0) {
			if (sl1 > 0) {
				sl1--; t++;
			}
			else r0++;
		}
		else sl1++;
	}
	int s1 = 0, r01 = 0;
	for (int i = n + 1; i <= 2 * n; i++) {
		if (a[i] == 0) {
			if (s1 > 0) s1--,t++;
			else r01++;
		}
		else s1++;
	}
	t += min(sl1, r01);
	int gtmax = t;
	t = 0; sl1 = 0, r0 = 0, s1 = 0, r01 = 0;
	for (int i = n; i >= 1; i--) {
		if (a[i] == 0) {
			if (sl1 > 0) sl1--,t++;
			else r0++;
		}
		else sl1++;
	}
	for (int i = 2 * n; i >= n + 1; i--) {
		if (a[i] == 0) {
			if (s1 > 0) s1--, t++;
			else r01++;
		}
		else s1++;
	}
	t += min(s1, r0);
	int gtmin = n-t;
	cout << gtmax - gtmin + 1 << endl;

	
}
int main()
{
	int T; cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n;
		solve();
	}
//	system("pause");
    return 0;
}

