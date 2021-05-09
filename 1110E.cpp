#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
ll n,a[100010],b[100010],d1[100010],d2[100010];
void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	if (a[0] != b[0] || a[n - 1] != b[n - 1]) { cout << "No" << endl; return; }
	for (int i = 0; i < n - 1; i++) d1[i] = a[i + 1] - a[i];
	for (int i = 0; i < n - 1; i++) d2[i] = b[i + 1] - b[i];
	sort(d1, d1 + n - 1); sort(d2, d2 + n - 1);
	for (int i = 0; i < n - 1; i++) {
		if (d1[i] != d2[i]) { cout << "No" << endl; return; }
	}
	cout << "Yes" << endl;
}
int main()
{
	solve();
//	system("pause");
    return 0;
}

