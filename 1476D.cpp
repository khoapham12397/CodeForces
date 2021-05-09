#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int n,fr[300010],fl[300010],ans[300010];
bool a[300010];
void solve() {
	string s;
	cin >> n; cin >> s;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'L') a[i + 1] = 0;
		else a[i + 1] = 1;
	}
	fr[n] = 1;
	for (int i = n - 1; i >= 1; i--) {
		if (a[i] ) {
			if (a[i + 1]) fr[i] = 1;
			else fr[i] = fr[i + 1] + 1;
		}
		else {
			if (a[i + 1]) fr[i] = fr[i + 1] + 1;
			else fr[i] = 1;
		}
	}
	fl[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (a[i]) {
			if (a[i - 1]) fl[i] = 1;
			else fl[i] = fl[i - 1] + 1;
		}
		else {
			if (a[i - 1]) fl[i] = fl[i - 1] + 1;
			else fl[i] = 1;
		}
	}
	if (!a[1]) ans[1] = 1;
	else ans[1] = fr[1] + 1;

	for (int i = 2; i <= n ; i++) {
		ans[i] = 1;
		if (a[i]) { ans[i] += fr[i]; }
		if (!a[i - 1]) ans[i] += fl[i-1];
	}
	if (!a[n]) ans[n + 1] = fl[n] + 1;
	else ans[n+1] = 1;
	for (int i = 1; i < n + 2; i++) cout << ans[i] << " ";
	cout << endl;
}
int main()
{
	int t; cin >> t;
	while (t--) solve();
	//system("pause");
    return 0;
}

