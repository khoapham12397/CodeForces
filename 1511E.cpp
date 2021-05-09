#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
int n,m;
ll p2[300010],mod = 998244353,f[300010],ans =0;
vector<char> row[300010],col[300010];
void init() {
	p2[0] = 1; f[0] = f[1] = 0; f[2] = 1;
	for (int i = 1; i <= 300000; i++) p2[i] = (2 * p2[i - 1]) % mod;
	for (int i = 3; i <= 300000; i++) {
		f[i] = (p2[i - 2] + ((((2 * f[i - 2]) % mod) + f[i - 1]) % mod)) % mod;
	}
}
void solve() {
	cin >> n >> m;
	int sl = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char x; cin >> x; row[i].push_back(x);
			sl += (x == 'o');
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			char x = row[j][i]; 
			col[i].push_back(x);
		}
	}
	
	for (int i = 0; i < n; i++) {
	
		int ind = 0;
		while (ind < m) {
			while (ind < m  && row[i][ind] == '*') ind++;
			int x = ind;
			if (ind == m) break;
			while (ind < m && row[i][ind] == 'o') ind++;
			ans = (ans + ((f[ind - x] * p2[sl - ind + x]) % mod)) % mod;
		}
	}
	for (int i = 0; i < m; i++) {
		int ind = 0;
		while (ind < n) {
			while (ind < n && col[i][ind] == '*') ind++;
			if (ind == n) break;
			int x = ind;
			while (ind < n && col[i][ind] == 'o') ind++;
			ans = (ans + ((f[ind - x] * p2[sl - ind + x]) % mod)) % mod;
		}
	}
	cout << ans << endl;
}
int main()
{	
	init();
	solve();
//	system("pause");
    return 0;
}

