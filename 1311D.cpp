#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int a, b, c;
void solve() {
	cin >> a >> b >> c;
	int ans = int(1e9),a1=0,b1=0,c1=0;
	
	for (int x = 1; x <= 2*b; x++) {
		
		
		for (int t = 1; t*x <= 2*c; t++) {
			
			int u = t*x;
			int val = abs(x - a) + abs(b - u);
			if (val > ans) continue;
			
			int z = c / u ;
			if (z == 0) {
				val += u - c;
				if (ans > val) ans = val, a1 = x, b1 = u, c1 = u;
			}
			else {
				int v1 = c - u*z, v2 = (z + 1)*u - c, c2;
				if (v1 < v2) c2 = u*z, val += v1;
				else c2 = (z + 1)*u, val += v2;
				if (ans > val) a1 = x, b1 = u, c1 = c2, ans = val;
			}
		}
	}
	cout << ans << endl;
	cout << a1 << " " << b1 << " " << c1 << endl;
}

int main()
{
	int t; cin >> t;
	while (t--) solve();
//	system("pause");
    return 0;
}

