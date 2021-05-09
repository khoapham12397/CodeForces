#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n,m,a[20][10010];
int f[20][20], b[20];
bool used[20] = { 0 };

bool duyet(int t,int gh) {
	
	for (int i = 0; i < n; i++) {
		if (!used[i]) {
			if (f[i][b[t - 1]] >=gh) {
				if (t == n - 2) {
					if (f[i][b[n - 1]] >= gh) return true;
				}
				else {
					used[i] = true; b[t] = i;
					if (duyet(t + 1, gh)) return true;
					used[i] = false;
				}
			}
 		}
	}
	return false;
}
void solve() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> a[i][j];
		if (n == 1) {
		int ans = int(1e9);
		for (int i = 0; i < m - 1; i++) {
			ans = min(ans, abs(a[0][i + 1] - a[0][i]));
		}
		cout << ans << endl;  return;
	}
	for (int i = 0; i < n-1; i++) {
		for (int j = i + 1; j < n; j++) {
			int gtmin = int(1e9) + 7;
			for (int k = 0; k < m; k++) {
				gtmin=min(gtmin, abs(a[i][k] - a[j][k]));
			}
			f[i][j] = f[j][i] = gtmin;
		}
	}
	int l=0, r = int(1e9),ans = 0;
	while (l <= r) {
		int mid = (l + r) >> 1;
		bool ok = false;
		for (int rf = 0; rf < n; rf++) {
			
			for (int rt = 0; rt < n; rt++) {

				if (rt == rf) continue;

				bool imp = false;
				for (int i = 0; i < m-1; i++) {
					if (abs(a[rt][i] - a[rf][i + 1]) < mid) {
						imp = true; break;
					}
				}
				if (!imp) {
					if (n > 2) {
						b[0] = rf; b[n - 1] = rt;
						for (int i = 0; i < n; i++) used[i] = 0;
						used[rf] = used[rt] = 1;
						if (duyet(1, mid)) {
						ok = true; 
						break;
						}
					used[rf] = used[rt] = 0;
					} else {
						if(f[rf][rt]>=mid) {ok=true; break;}
					}
				}
			}
			if (ok) break;
		}
		if (ok) l = mid + 1, ans= mid;
		else r = mid - 1;
	}
	cout << ans << endl;
}
int main()
{
	solve();
//	system("pause");
    return 0;
}

