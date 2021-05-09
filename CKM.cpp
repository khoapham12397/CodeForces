
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const long long inf = 1e18;
int n, a[1005]; 
long long F[1005][1005];
void readInput() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) for (int j = 0; j <= n+1; j++) F[i][j] = inf;
}
void solve() {
	if (a[1] > 100) {
		F[1][1] = a[1];
	}
	else F[1][0] = a[1];

	for (int i = 2; i <= n; i++) {
		
		F[i][0] = min(F[i - 1][1], F[i - 1][0] + a[i]);
		
		for (int j = 1; j <= i; j++) {
			if (a[i] > 100) {
				F[i][j] = min(F[i - 1][j+1], F[i - 1][j - 1] + a[i]);
			}
			else F[i][j] = min(F[i - 1][j] + a[i], F[i - 1][j + 1]);
		}
	
	}
	long long ans = inf;
	for (int i = 0; i <= n; i++) ans=min(ans,F[n][i]);
	cout << ans << endl;
}
int main()
{
	readInput();
	solve();
//	system("pause");
	return 0;
}

