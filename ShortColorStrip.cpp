#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> ii;
typedef unsigned long long ll;
int n,m,a[510];
ll mod = 998244353, F[501][501];
ii gtmins[501][501];
void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];

	for (int i = 1; i <= n; i++) {
		gtmins[i][i].first = i,gtmins[i][i].second=a[i];
		int val = a[i],ind=i;

		for (int j = i + 1; j <= n; j++) {
			if (a[j] < val) {
				val = a[j]; ind = j;
			}
			gtmins[i][j].first = ind; gtmins[i][j].second = val;
		}
	}
	for (int i = 1; i <= n; i++) F[i][i] = 1;
	//dieu nay co nen cho voi cai nay ???
	
	for (int d = 1; d <= n - 1; d++) {
		for (int  l= 1; l <= n - d; l++) {
			int r = l + d;
			int ind = gtmins[l][r].first;
			ll val = 0;
			int m1 = ind - l,m2= r-ind;
			for (int d1 = 0; d1 <= m1; d1++) {
				for (int d2 = 0; d2 <= m2; d2++) {
					int x=ind-d1, y=ind+d2;
					ll u, v,p,q;
					if (x == l) u = 1; else u = F[l][x-1];
					if (y == r) v = 1; else v = F[y + 1][r];
					if (x == ind) p = 1; else p = F[x][ind-1];
					if (y == ind) q = 1; else q = F[ind + 1][y];
					val = (val + (((u*v)%mod)* ((p*q)%mod))%mod) % mod;
				}
			}
			F[l][r] = val%mod;
		}
	}
	cout << F[1][n]%mod << endl;
}
int main()
{
	solve();
//	system("pause");
	return 0;
}

