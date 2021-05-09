#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> ii;
typedef pair<ii, int> i3;
int n,a[10010];
void solve() {
	cin >> n;
	int s = 0;
	for (int i = 1; i <= n; i++) cin >> a[i],s+=a[i];
	if (s%n != 0) {
		cout << -1 << endl;
		return;
	}
	int tar = s / n;
	vector<i3> ops;
	

	for (int i = 2; i <= n; i++) {
		if (a[i] > tar) {
			int x = a[i] / i;
			int r = a[i] - x*i;
			
			if (x > 0) ops.push_back(i3(ii(i, 1), x));
			a[i] = r; a[1] += x*i;
			
		}
	}
	// dieu nay dung chua neu a[i]<tar thi pass roi dung vay:
	
	for (int i = 2; i <= n; i++) {
		if (a[i]>tar){
			int x = i - a[i];
			if (a[1] < x) {
				bool ok = false;
				for (int j = 2; j < i; j++) {
					if (a[j] >= j) {
						int x1 = a[j] / j;
						ops.push_back(i3(ii(j, 1), x1));
						a[j] -= x1*j; a[1] += x1*j;
						if (a[1] >= x) { ok = true; break; }
					}else {
						int x1 = j - a[j];
						if (a[1] >= x1) {
							ops.push_back(i3(ii(1, j), x1));
							ops.push_back(i3(ii(j, 1), 1));
							a[1] += a[j]; a[j] = 0;
						}
						if (a[1] >= x) { ok = true; break; }
					}
				}
				if (!ok) { cout << -1 << endl; return; }
			}
			ops.push_back(i3(ii(1, i), x));
			ops.push_back(i3(ii(i, 1), 1));
			a[1] += a[i]; a[i] = 0;
		}
	}


	for (int i = 2; i <= n; i++) {
		if (a[i] < tar) {
			ops.push_back(i3(ii(1, i), tar - a[i]));
			a[1] -= tar - a[i];
			a[i] = tar;
		}
	
	}
	cout << ops.size() << endl;
	for (int i = 0; i < ops.size(); i++) cout << ops[i].first.first << " " << ops[i].first.second << " " << ops[i].second << endl;
}
int main()
{
	int t; cin >> t;
	while (t--) solve();
//	system("pause");
    return 0;
}

