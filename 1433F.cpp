#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> ii;
int n, m, k,a[71][71];
int dp[71][71][71][71];
int b[71][71],f[71][71];
void solve() {
	
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) for (int t = 0; t <= (m / 2); t++) for (int r = 0; r < k; r++) dp[j][t][r][i] = -1;
	if (m == 1) { cout << 0 << endl; return; }
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> a[i][j];
	for (int i = 0; i < n; i++) {
		dp[0][0][0][i]= 0; 

		dp[0][1][a[i][0] % k][i] = a[i][0];
		for (int j = 1; j < m; j++) {
			dp[j][0][0][i] = 0;
			for (int t = 1; t <= int(m / 2); t++) {
				for (int r = 0; r < k; r++) {
					int val,x= dp[j - 1][t - 1][(r + k - (a[i][j]%k) ) % k][i], y = dp[j - 1][t][r][i];
					if (x >= 0) val = max(x + a[i][j], y);
					else val = y;
					dp[j][t][r][i] = val;
				}
			}
		}
	}
	
	for (int i = 0; i < n; i++) {
		
		for (int r = 0; r < k; r++) {
			b[i][r] = -1; if (r == 0) b[i][r] = max(0, b[i][r]);
			for (int t = 1; t <= (m / 2); t++) {
				b[i][r] = max(b[i][r], dp[m - 1][t][r][i]);
			}
		}
	}
	
	for (int r = 0; r < k; r++) {
		f[0][r] = b[0][r];
	}
	for (int i = 1; i < n; i++) {
		for (int r = 0; r < k; r++) {
			f[i][r] = f[i - 1][r];
			for (int r1 = 0; r1 < k; r1++) {
				int x = b[i][r1],y= f[i - 1][(r + k - r1) % k];
				if (x >= 0 && y>=0) {
					f[i][r] = max(y+x,f[i][r]);
				}
			}
		}
	}
	
	cout << f[n - 1][0] << endl;
}
int main()
{
	solve();
//	system("pause");
    return 0;
}

