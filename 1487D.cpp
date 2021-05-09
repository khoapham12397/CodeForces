#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
int n,a[23000],m;
int BSearch(int val, int l,int r) {
	if (l == r) {
		if (a[l] <= val) return l + 1;
		return l;
	}
	int mid = (l + r) >> 1;
	if (a[mid] == val) return mid + 1;
	if (a[mid] > val) {
		if (mid > l) return BSearch(val, l, mid - 1);
		return l;
	}
	return BSearch(val, mid + 1, r);
}
void init() {
	int t = 0;
	for (int i = 3; i <= 44721; i += 2) {
		int x = (i*i + 1) / 2;
		a[t] = x; t++;
	}
	
	m = t-1;
}
void solve() {
	init();
	int t; cin >> t;
	while (t--) {
		cin >> n;
		cout << BSearch(n, 0, m) << endl;
	}
}
int main()
{
	solve();
//	system("pause");
    return 0;
}

