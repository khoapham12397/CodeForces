#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;
ll gts[50000];
int n;
int BSearch(ll val ,int l,int r) {
	if (l == r) {
		if (gts[l] < val) return l;
		return l - 1;
	}
	int mid = (l + r) >> 1;
	if (gts[mid] == val) return mid-1;
	if (gts[mid] > val) {
		if (mid > l) return BSearch(val, l, mid - 1);
		return l - 1;
	}
	return BSearch(val, mid + 1, r);
}
void solve() {
	cin >> n;
	int a = BSearch(ll(n), 0, 49999);
	if (gts[a] == n) a--;
	int b = n - ll(a)*ll(a + 3) / 2 - 1;
	string s="133";
	for (int i = 0; i < b; i++) s += '7';
	for (int i = 0; i < a; i++) s += '3';
	s += '7';
	cout << s << endl;
}
int main()
{
	for (int i = 0; i < 50000; i++) {
		gts[i] = ll(i)*ll(i + 3)/2;
	}
	int t; cin >> t;
	while (t--) solve();
//	system("pause");
    return 0;
}

