#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n,T,a[200001],L[200010],R[200010];
void solve() {
	L[0] = 0;
	int x = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] >= x) x = a[i] - x;
		else { break; }
	}
	if (x == 0) { cout << "YES" << endl; return; }

	for (int i = 1; i <= n; i++) {
		if (a[i] >= L[i - 1]) L[i] = a[i] - L[i - 1];
		else {
			L[i] = -1;
			for (int j = i + 1; j <= n; j++) L[j] = -1;
			break;
		}
	}
	R[n + 1] = 0;
	for (int i = n; i >= 1; i--) {
		if (a[i] >= R[i + 1]) R[i] = a[i] - R[i + 1];
		else {
			R[i] = -1;
			for (int j = i - 1; j >= 1; j--) R[j] = -1;
			break;
		}
	}
	
	for (int i = 1; i < n; i++) {
		int u = L[i - 1],v=R[i+2],x=a[i+1],y=a[i];
		if (u < 0 || v < 0) continue;
		if (x - u >= 0 && (y- v) == (x - u)) {
			cout << "YES" << endl;
			return;
		}
	}
	cout << "NO" << endl;
}
int main()
{
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n;
		int s = 0;
		for (int j = 1; j <= n; j++) cin >> a[j],s=(s+a[j]%2)%2;
		if (s % 2 == 1) cout << "NO" << endl;
		else solve();
	}
//	system("pause");
    return 0;
}

