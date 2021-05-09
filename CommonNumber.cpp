#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef unsigned long long ull;
ull n,k;

ull cal(ull x) {
	ull y = x,ans=0;
	int t = 0;
	if (x % 2 == 1) {
		while (y <= n) {
			ull a = (ull(1) << t) - 1;
			ull b = min(n - y,a);
			ans += b + 1;
			t++;
			y*=2;
		}
	}
	else {
		while (y <= n) {
			ull a = (ull(1) << (t + 1)) - 1;
			ull b = min(n - y, a);
			ans += b + 1;
			t++;
			y *= 2;
		}
	}
	return ans;
}
void solve() {
	
	cin >> n >> k;
	if (n == k) { cout << 1 << endl; return; }
	else if (k == 1) { cout << n << endl; return; }

	ull r = n,l=ull(1);
	ull res=1;

	while (r>=l) {
		ull mid = ull((l + r)/2);
		if (mid % 2 == 1 && mid<r) mid = mid + 1;
		ull t = cal(mid);
		if(t>=k){
			res = mid;
			l = mid + 1;
		}
		else r = mid - 1;
		
		
	}
	cout << res << endl;
	
}
int main()
{
	solve();
//	system("pause");
    return 0;
}

