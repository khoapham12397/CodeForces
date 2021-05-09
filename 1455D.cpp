#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n,a[510],x0;
bool sp[510];
void solve() {
	cin >> n >> x0;
	vector<int> sps;
	for (int i = 1; i <= n; i++) cin >> a[i], sp[i] = false;
	for (int i = 2; i <= n; i++) {
		
		int t = 0;
		for (int j = 1; j < i; j++) if (a[j] > a[i])t++;
		if (t > 1) { cout << -1 << endl; return; }
	}
	int res = 0;
	for (int i = 1; i < n; i++) {
		if (a[i] > a[i + 1]) sp[i] = true,res++, sps.push_back(i);
	}
	int x = x0;
	if (res == 0) { cout << 0 << endl; return; }
	

	if (x > a[sps[0] + 1]) {
		cout << -1 << endl; return;
	}
	int st = 1;
	for (int i = 0; i < sps.size(); i++) {
		
		for (int j = st; j < sps[i]; j++) {
			if (a[j] > x) {
				int temp = a[j];
				a[j] = x; x = temp;
				res++;
			}
		}
		int temp = a[sps[i]];
		a[sps[i]] = x; x = temp;
		st = sps[i] + 1;
	}
	
	cout << res << endl;
}
int main()
{
	int t; cin >> t;
	while (t--) solve();
//	system("pause");
    return 0;
}

