#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
typedef long long ll;
int n;
ll a[5001];
int F[5001][5001],S[5001][5001];
int g[5001];
int res[5001];

void solve() {
	cin >> n;
	
	for (int i = 0; i < n; i++) cin >> a[i];
	
	if (a[0] != 0) g[0] = 1;
	
	for (int i = 1; i < n; i++) {
		g[i] = g[i - 1];
		if (a[i] != 0) g[i]++;
	}
	
	for (int i = 1; i < n; i++) {
		if (a[i] == 0) continue;
		
		ll x = a[i - 1] * a[i];
		if (x > 0) {
			ll  t = ll(sqrt(x));
			if (t*t == x) S[i][i - 1]=1;
			else S[i][i - 1] = 0;
		}
		for (int j = i - 2; j >= 0; j--) {
			ll x = a[j]*a[i];
			S[i][j] = S[i][j + 1];
			if (x > 0) {
				ll t = ll(sqrt(x));
				if (t*t == x) S[i][j]++;
			}
		}
	}
	
	for (int i = 0; i < n; i++)  F[i][i] = 1;
	res[1] = n;

	for (int d = 1; d < n; d++) {
		for (int l = 0; l < n - d; l++) {
			int r = l + d;
			if (a[r] == 0) {
				F[l][r] = F[l][r - 1];
			}
			else {
				if (S[r][l] > 0) {
					F[l][r] = F[l][r - 1];
				}
				else {
					int t;
					if (l == 0) t = g[r - 1];
					else t = g[r - 1] - g[l - 1];
					if (t > 0)
						F[l][r] = F[l][r - 1] + 1;
					else F[l][r] = F[l][r - 1];
				}
			}
			res[F[l][r]]++;
		}
	}
	
	for (int i = 1; i <= n; i++) cout << res[i] << " ";
	cout << endl;
}

int main()
{
	solve();
//	system("pause");
    return 0;
}

