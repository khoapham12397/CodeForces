#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
ll mod = ll(1e9) + 7;
int n,m,pr[2001][2001],pc[2001][2001],sdr[2001][2001],sdc[2001][2001];
int a[2001][2001];
ll dp[2001][2001][2],Sr[2001][2001],Sc[2001][2001];
int BSearchRow(int val, int x, int l,int r) {
	if (l == r) {
		if (sdr[x][l] >= val) return l;
		return l + 1;
	}
	int mid = (l + r) / 2;
	if (sdr[x][mid] == val) {
		int t = mid; while(t>=1 &&sdr[x][t] == val) t--;
		return t+1;
	}

	if (sdr[x][mid] > val) {
		if (mid > l) return BSearchRow(val,x,l,mid-1);
		return l;
	}
	return BSearchRow(val, x, mid + 1, r);
}
int BSearchCol(int val,int x,int l,int r ) {
	if (l == r) {
		if (sdc[x][l] >= val) return l;
		return l + 1;
	}
	int mid = (l + r) / 2;
	if (sdc[x][mid] == val) {
		int t = mid; while (t >= 1 && sdc[x][t] == val) t--;
		return t+1;
	}
	if (sdc[x][mid] > val) {
		if (mid > l) return BSearchCol(val, x, l, mid - 1);
		return l;
	}
	return BSearchCol(val, x, mid + 1, r);
}
void solve() {
	cin >> n>>m;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			char x; cin >> x;
			if (x == '.') a[i][j] = 0;
			else a[i][j] = 1;
		}
	}
	if (m == 1 && n == 1) { cout << 1 << endl; return; }
	for (int i = 1; i <= n; i++) {
		sdr[i][1] = a[i][1];
		for (int j = 2; j <= m; j++) {
			sdr[i][j] = sdr[i][j - 1] + a[i][j];
		}
	}
	for (int i = 1; i <= m; i++) {
		sdc[i][1] = a[1][i];
		for (int j = 2; j <= n; j++) sdc[i][j] = sdc[i][j - 1] + a[j][i];
	}
	
	for (int i = 2; i <= m; i++) {
		dp[1][i][0] = 0;
		if (m - i >= sdr[1][m]) dp[1][i][1] = 1;
		else dp[1][i][1] = 0;
		Sc[i][1] = dp[1][i][1];
	}
	for (int i = 2; i <= n; i++) {
		dp[i][1][1] = 0;
		if (n - i >= sdc[1][n]) dp[i][1][0] = 1;
		else dp[i][1][0] = 0;
		Sr[i][1] = dp[i][1][0];
	
	}
	for (int i = 2; i <= n; i++) {
		pr[i][1] = 1;
		for (int j = 2; j <= m; j++) {
			
			int ind = BSearchRow(sdr[i][m] - m + j, i, 1, j-1);
			if (ind >= j) pr[i][j] = -1;
			else pr[i][j] = ind;
		}
	}

	for (int i = 2; i <= m; i++) {
		pc[i][1] = 1;
		for (int j = 2; j <= n; j++) {
			int ind = BSearchCol(sdc[i][n] - n + j, i, 1, j-1);
			if (ind >= j) pc[i][j] = -1;
			else pc[i][j] = ind;
		}
	}
	for (int r = 2; r <= n; r++) {
		for (int c = 2; c <= m; c++) {
			int ght=pr[r][c],up = pc[c][r];
			if(ght!=-1)
				dp[r][c][1] = (Sr[r][c - 1] + (mod - Sr[r][ght - 1]) % mod) % mod;
			else dp[r][c][1] = 0;
			if(up!=-1)
				dp[r][c][0] = (Sc[c][r - 1] + (mod - Sc[c][up - 1]) % mod) % mod;
			else dp[r][c][0] = 0;
			Sr[r][c] = (Sr[r][c - 1] + dp[r][c][0])%mod;
			Sc[c][r] = (Sc[c][r - 1] + dp[r][c][1]) % mod;
		}
	}
	cout << (dp[n][m][0] + dp[n][m][1]) % mod << endl;
	
}

int main()
{
	solve();
//	system("pause");
    return 0;
}

