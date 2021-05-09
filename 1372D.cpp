#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
int n,a[200001];
ll sc[200001],sl[200001],sc1[200001],sl1[200001];
ll ans = 0;
void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	if (n == 1) {cout << a[0] << endl; return;}
	sc[0] = a[0];
	int i = 2;
	while(i<n){
		sc[i] = sc[i - 2] + a[i];
		i += 2;
	}
	i = 3; sl[1] = a[1];
	while (i < n - 1) {
		sl[i] = sl[i - 2] + a[i]; i += 2;
	}
	i = n - 3; sc1[n - 1] = a[n - 1];
	while(i>=0){
		sc1[i] = sc1[i + 2] + a[i]; i -= 2;
	}
	sl1[n - 2] = a[n - 2]; i = n - 4;
	while (i >= 1) {
		sl1[i] = sl1[i + 2] + a[i]; i -= 2;
	}
	ans = max(ans, sc1[0]);
	i = 2;
	while (i < n) {
		ans = max(ans, sc1[i] + sl[i - 1]);
		i += 2;
	}
	i = 1;
	while (i < n - 1) {
		ans = max(ans, sl1[i] + sc[i - 1]);
		i += 2;
	}
	cout << ans << endl;
}
int main()
{
	solve();
//	system("pause");
    return 0;
}

