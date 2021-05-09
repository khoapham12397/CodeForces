#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
int n;
ll b[100010],a[100010],val=0;
void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n - 1; i++) {
		b[i] = a[i + 1] - a[i];
		if (b[i] > 0) val += b[i];
	}
	ll u = a[0] + val;
	ll c = u/ 2, u0 = a[0];
	if (u % 2 == 1 && u>0) c++;
	cout<<c<<endl;
	int q; cin >> q;
	for (int i = 0; i < q; i++) {
		int x, y, d; cin >> x >> y >> d;
		x--; y--;
		if (x == 0) u0 += d;
		if (x > 0) {
			if (b[x - 1] > 0) {
				if (b[x - 1] + d > 0) val += d;
				else val -= b[x - 1];
				b[x - 1] += d;
			}
			else {
				if(b[x-1] + d> 0) {
					b[x - 1] += d; val += b[x - 1];
				}
				else b[x - 1] += d;
			}
		}
		if (y < n - 1) {
			if (b[y] > 0) {
				if (d > 0) {
					if (b[y] > d) {
						val -= d;
						b[y] -= d;
					}
					else {
						val -= b[y];
						b[y] -= d;
					}
				}
				else {
					val -= d;
					b[y]-= d;
				}
			}
			else {
				if (d > 0) {
					b[y] -= d;
				}
				else {
					if (b[y] - d > 0) {
						val += b[y] - d;
						b[y] -= d;
					}
					else b[y] -= d;
				}
			}
		}
		ll u = val + u0; 
		ll c = (u) / 2; if (u % 2 == 1 && u>0) c++;
		cout << c << endl;
	}
}
int main()
{
	solve();
	//	system("pause");
    return 0;
}

