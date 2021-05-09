#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> ii;
typedef pair<ii, int> i3;
int n,res[200001];
i3 a[200001];
void solve() {
	sort(a + 1, a + n+1);
	
	int x = a[1].first.first,ind=2;
	int gtmin = a[1].first.second, pm=a[1].second;
	while (ind <= n && a[ind].first.first == x) {
		if (gtmin > a[ind].first.second) {
			gtmin = a[ind].first.second;
			pm = a[ind].second;
		}
		ind++;				
	}
	
	int gtmin1=gtmin,pm1=pm;
	
	for (int i = 1; i < ind; i++) res[a[i].second] = -1;
	for (int i = ind; i <= n; i++) {
		if (a[i].first.first == a[i - 1].first.first) {
			if (a[i].first.second > gtmin) res[a[i].second] = pm;
			else res[a[i].second] = -1;
			if (gtmin1 > a[i].first.second) {
				gtmin1 = a[i].first.second;
				pm1 = a[i].second;
			}
		}
		else {
			gtmin = gtmin1;
			pm = pm1;
			if (a[i].first.second > gtmin) res[a[i].second] = pm;
			else res[a[i].second] = -1;
			if (gtmin1 > a[i].first.second) {
				gtmin1 = a[i].first.second; pm1 = a[i].second;
			}
		}
	}
	for (int i = 1; i <= n; i++) cout << res[i] << " ";
	cout << endl;
}
int main()
{
	int T; cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			int x, y; cin >> x >> y;
			if (x < y) a[i].first=ii(x,y);
			else a[i].first=ii(y,x);
			a[i].second = i;
		}
		solve();
	}
//	system("pause");
    return 0;
}

