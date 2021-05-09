#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> i3;
int n, m,freq[1000010];
i3 f[1000010];
void solve() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) freq[i] = 0;
	for (int i = 0; i < n; i++) {
		int x; cin >> x; freq[x]++;
	}
	f[1].first = 0; f[1].second.first = freq[1]; f[1].second.second = 0;
	f[2].first = 0; f[2].second.first = freq[2]; f[2].second.second = freq[1];
	
	for (int i = 3; i <= m; i++) {
		int rc = 0,rp=0,val1=0,val2=0,val3=0, rc1, rp1, rc2, rp2, rc3, rp3;
		
			int r1 = f[i - 1].second.first, r2 = f[i - 1].second.second;
			int gtmin1 = min(freq[i], min(r1,r2));
			val1 = f[i - 1].first + gtmin1 + int((r2-gtmin1)/3);
			rc1 = freq[i] - gtmin1; rp1 = r1 - gtmin1;
			r1 = f[i - 2].second.first; r2 = f[i - 2].second.second;
			int gtmin2= min(r1, min(freq[i-1],freq[i]));
			val2 = f[i - 2].first + gtmin2 + int((r1 - gtmin2) / 3) + int(r2/3);
			rc2 = freq[i] - gtmin2; rp2 = freq[i - 1] - gtmin2;
			if (i == 3) {
				val3 = val2; rc3 = rc2; rp3 = rp2;
			}
			else {
			int gtmin3 = min(freq[i], min(freq[i - 1], freq[i - 2]));
			val3 = f[i - 3].first + gtmin3 + int(((freq[i - 2]-gtmin3) / 3)) + int(f[i - 3].second.first / 3) + int(f[i - 3].second.second / 3);
			rc3 = freq[i] - gtmin3; rp3 = freq[i - 1] - gtmin3;
			}
			int valMax = max(val1, max(val2, val3));
			i3 x1 = i3(val1, ii(rc1, rp1)), x2 = i3(val2, ii(rc2, rp2)), x3 = i3(val3, ii(rc3, rp3));
			f[i] = max(x1, max(x2, x3));
	}
	cout << f[m].first << endl;
}
int main()
{
	solve();
//	system("pause");
    return 0;
}

