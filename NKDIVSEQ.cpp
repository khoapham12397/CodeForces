
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int a[8000001],n;
void solve() {
	for (int i = 1; i <=8000000; i++) a[i] = 0;
	int t = 1;
	while (t*(t + 1) / 2 < n) t++;
	t -= 1;
	
	for (int i = 1; i <= t; i++) {
		int dem = 0,x=i;
		while (dem < i) {
			if (!a[x]) {
				dem++;
				a[x] = 1;
			}
			x += i;
		}
	}
	int r = n - t*(t + 1) / 2;
	
	int dem = 0, x = t + 1,ans=0;
	while (dem < r) {
		if (!a[x]) {
			dem++;
			if (dem == r) {
				ans = x;
				break;
			}
			a[x] = 1;
		}
		x += (t + 1);
	}
	cout << ans << endl;

}
int main()
{
	cin >> n;
	solve();
//	system("pause");
	return 0;
}

