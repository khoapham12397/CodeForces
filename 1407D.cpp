#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n,a[300001];
int La[300001], Li[300001];
int dp[300001];
void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	La[0] = 0; Li[0] = 0;
	for (int i = 1; i < n; i++) {
		if (a[i] <= a[i - 1]) La[i] = i;
		else {
			int j = La[i - 1];
			while (j > 0 && a[j - 1] < a[i]) j = La[j - 1];
			La[i] = j;
		}
	}

	for (int i = 1; i < n; i++) {
		if (a[i] >= a[i - 1]) Li[i] = i;
		else {
			int j = Li[i - 1];
			while (j > 0 && a[j - 1] > a[i]) j = Li[j - 1];
			Li[i] = j;
		}
	}
	
	dp[0] = 0; dp[1] = 1;
	for (int i = 2; i < n; i++) {
		int val = int(1e9 + 7);
		if (a[i] > a[i - 1]) {
			int j = i - 1,ght= La[i]-1,ok=1;

			while (j >= max(ght, 0)) {
				
				if (val > dp[j] + 1 && ok) {
					val = dp[j] + 1;
				}
				int x = La[j] - 1;
				if (x >= 0 && a[x] == a[j]) ok = 0;
				else ok = 1;
				j = x;
			}
		}
		else {
			if (a[i] < a[i - 1]) {
				int j = i - 1, ght = Li[i] - 1,ok=1;
				while (j >= max(0, ght)) {
					if (val > dp[j] + 1 && ok) {
						val = dp[j] + 1;
					}
					int x = Li[j]-1;
					if (x >= 0 && a[x] == a[j]) ok = 0;
					else ok = 1;
					j = x;
				}
			}
			else {
				val= dp[i - 1] + 1;
			}
		}
		dp[i] = val;
	}
	cout << dp[n - 1] << endl;
}
int main()
{
	solve();
//	system("pause");
    return 0;
}

