#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
ll k, ops=0;
int n, a[100010];
void solve() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	int i = 0, j=n-1;
	while (i < n && a[i] == a[0]) i++;
	while (j >= 0 && a[j] == a[n - 1]) j--;
	int x = i, y= n-j-1;
	int gtmin = a[0] , gtmax= a[n-1];
	if (gtmax == gtmin) { cout << 0 << endl; return; }
	
	while (1) {
		if (x < y) {
			ll del = ll(a[i] - gtmin)*ll(x);
			if (k >= del) {
				gtmin = a[i];
				if (gtmin == gtmax) { cout << 0 << endl; return; }
				int ind = i + 1;
				while (ind <= j && a[ind] == a[i]) ind++;
				x = ind;
				i = ind;
				k -= del;
			}
			else { 
				ll t = k / ll(x);
				if (t == 0) break;
				k -= t*x;
				gtmin += t;
				if (k < y) break;
			}
		}
		else {
			ll del = ll(gtmax - a[j])*ll(y);
			if (k >= del) {
				k -= del;
				gtmax = a[j];
				if (gtmax == gtmin) { cout << 0 << endl; return; }
				int ind = j - 1;
				while (ind >= i && a[ind] == gtmax) ind--;
				j = ind;
				y = n - 1 - j;
			}
			else {
				ll t = k / ll(y);
				if (t == 0) break;
				k -= t*ll(y);
				gtmax -= t;  if (k < x) break;
			}
		}
	}
	cout << gtmax - gtmin << endl;

}

int main()
{
	solve();
//	system("pause");
    return 0;
}

