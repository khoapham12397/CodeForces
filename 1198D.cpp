#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int n,s[51][51],f[51][51][51][51],a[51][51] , b[51][51][51][51];

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		string s1; cin >> s1;
		for (int j = 1; j <= n; j++) {
			if (s1[j - 1] == '.') a[i][j] = 0;
			else a[i][j] = 1;
		}
	}
	s[1][1] = a[1][1];
	for (int i = 2; i <= n; i++) {
		s[1][i] = s[1][i - 1] + a[1][i];
		s[i][1] = s[i - 1][1] + a[i][1];
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= n; j++) {
			s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
		}
	}
	
	for (int x = 1; x <= n; x++) 
		for(int y=1;y<=n;y++) 
			for(int u=x;u<=n;u++) 
				for(int v=y;v<=n;v++) b[x][y][u][v] = s[u][v] - s[u][y-1] - s[x-1][v] + s[x - 1][y - 1];
	for (int d1 = 0; d1 < n; d1++) {
		for (int d2 = 0; d2 < n; d2++) {
			for (int x = 1; x <= n; x++) {
				for (int y = 1; y <= n; y++) {
					int u = x + d1,v=y+d2;
					if (u > n || v > n) continue;
					if (b[x][y][u][v] == 0) { f[x][y][u][v] = 0; continue; }
					int val = max(d1, d2)+1;
					for (int t = x; t < u; t++) val = min(val, f[x][y][t][v] + f[t + 1][y][u][v]);
					for (int t = y; t < v; t++) val = min(val, f[x][y][u][t] + f[x][t + 1][u][v]);
					f[x][y][u][v] = val;
				}
			}
		}
	}
	
	cout << f[1][1][n][n] << endl;
}
int main()
{
	solve();
	//system("pause");
    return 0;
}

