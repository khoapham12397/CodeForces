#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, k,a[101];
void solve() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> a[i];
	a[n] = 0;
	int ind = 1, t = k;

	while (ind < n) {
		while (ind< n && a[ind] <= a[ind - 1]) ind++;
		for (int i = ind - 1;i>= 0; i--) {
			int del = a[ind] - a[i];
			if (del > 0) {
				if (del < t) {
					t -= del;
					a[i] = a[ind];
				}
				else {
					cout << i + 1 << endl; return;
				}
			}
		}
		ind++;
	}
	cout << -1 << endl;
}
int main()
{
	
	int t; cin >> t;
	for(int i=0;i<t;i++) solve();
//	system("pause");
    return 0;
}

