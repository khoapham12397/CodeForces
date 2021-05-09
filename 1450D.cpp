#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef vector<int> vi;
int n,a[300010],res[300010],gtm[300010];
vi  L,R,rm;
void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	L.assign(n,0); R.assign(n,0);
	rm.assign(n + 1, 0);
	L[0] = 0; 
	for (int i = 1; i < n; i++) {
		if (a[i] > a[i - 1]) L[i] = i;
		else {
			int j = L[i - 1];
			while (j > 0 && a[j - 1] >= a[i]) j = L[j - 1];
			L[i] = j;
		}
	}
	R[n - 1] = n - 1;
	for (int i = n - 2; i >= 0; i--) {
		if (a[i] > a[i + 1]) R[i] = i;
		else {
			int j = R[i + 1];
			while (j < n - 1 && a[j + 1] >= a[i]) j = R[j + 1];
			R[i] = j;
		}
	}
	for (int i = 0; i < n; i++) {
		int x = R[i] - L[i] + 1;
		rm[a[i]] = max(rm[a[i]], x);
	}
	
	gtm[1] = rm[1];
	for (int i = 2; i <= n; i++) {
		gtm[i] = min(gtm[i - 1], rm[i]);
	}

	for (int i = n; i >= 1; i--) {
		int k = n - i + 1;
		res[k] = (gtm[i] >= k);
	}
	for (int i = 1; i <= n; i++) cout << res[i];
	cout << endl;
}
int main()
{
	int t; cin >> t;
	while(t--) solve();
//	system("pause");
    return 0;
}

