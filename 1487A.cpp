#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n,a[101];
void solve() {
	cin >> n; 
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	int ind = 1;
	while (ind < n) {
		if (a[ind] != a[ind - 1]) break;
		ind++;
	}
	cout << n - ind << endl;
}
int main()
{
	int t; cin >> t;
	while (t--) solve();
//	system("pause");
    return 0;
}

