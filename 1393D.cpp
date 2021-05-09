#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;
ll ans = 0;
int n,m;
int U[2001][2001], D[2001][2001];
int FLU[2001][2001], FRU[2001][2001], FLD[2001][2001], FRD[2001][2001];
char a[2001][2001];
void solve() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> a[i][j];
	for (int col = 0; col < m; col++) {
		U[0][col] = 1;
		for (int r = 1; r < n; r++) {
			if (a[r][col] == a[r - 1][col]) U[r][col] = U[r - 1][col] + 1;
			else U[r][col] = 1;
		}
	}
	for (int col = 0; col < m; col++) {
		D[n - 1][col] = 1;
		for (int r = n - 2; r >= 0; r--) {
			if (a[r][col] == a[r + 1][col]) D[r][col] = D[r + 1][col] + 1;
			else D[r][col] = 1;
		}
	}
	
	
	for (int i = 0; i < n; i++) {
		FLU[i][0] = 1; FLD[i][0] = 1;
		for (int j = 1; j < m; j++) {
			if (a[i][j] == a[i][j - 1]) {
				FLU[i][j] = min(U[i][j], FLU[i][j - 1] + 1);
				FLD[i][j] = min(D[i][j], FLD[i][j - 1] + 1);
			}
			else FLU[i][j] = FLD[i][j]=1;
		}
	}

	for (int i = 0; i < n; i++) {
		FRU[i][m - 1] = 1; FRD[i][m - 1] = 1;
		for (int j = m - 2; j >= 0; j--) {
			if (a[i][j] == a[i][j + 1]) {
				FRU[i][j] = min(U[i][j], FRU[i][j + 1] + 1);
				FRD[i][j] = min(D[i][j], FRD[i][j + 1] + 1);
			}
			else FRU[i][j] = FRD[i][j]=1;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int x = min(FLU[i][j], FRU[i][j]), y = min(FLD[i][j], FRD[i][j]);
			ans += ll(min(x, y));
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

