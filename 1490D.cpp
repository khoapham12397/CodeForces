#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int n, a[110],h[110];
int gtmax[110][110];
void cal(int l,int r, int t) {
	int ind = gtmax[l][r];
	h[ind] = t;
	if (l < ind) cal(l, ind - 1, t + 1);
	if (ind < r) cal(ind + 1, r, t + 1);
}
void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++)cin >> a[i];
	for (int i = 1; i <= n; i++) gtmax[i][i] = i;
	for (int d = 1; d <= n; d++) {
		for (int l = 1; l <= n - d; l++) {
			int ind = gtmax[l + 1][l + d];
			if (a[ind] > a[l]) {
				gtmax[l][l + d] = ind;
			}
			else gtmax[l][l + d] = l;
		}
	}
	cal(1, n, 0);
	for (int i = 1; i <= n; i++) cout << h[i] << " ";
	cout << endl;
}
int main()
{
	int t; cin >> t;
	while (t--)solve();
//	system("pause");
    return 0;
}

