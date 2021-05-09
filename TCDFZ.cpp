
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;
int n;
int arr[4] = {6,8,4,2};

void solve1() {
	int sl = 0,x=n;
	vector<int> vt;
	while (x > 0) {
		vt.push_back(x % 10);
		x /= 10; sl++;
	}
	

	int sck = 0,r=1;
	x = vt[sl - 1];
	
	for (int i = sl - 2; i >= 0; i--) {
		 
		sck += x;
		
		for (int j = 1; j <= vt[i]; j++) r *= j;
		while (r % 10 == 0) r /= 10; r = r % 10;
		x = x * 10 + vt[i];
	}
	
	int y = 1;
	for (int i = 1; i <= vt[sl-1]; i++) y *= i;
	while (y % 10 == 0) y /= 10; y=y%10;
	r = r*y; while (r % 10 == 0) r /= 10; r = r % 10;
	int ans = arr[sck % 4];
	ans = (ans*r);
	while (ans % 10 == 0) ans /= 10;
	ans = ans % 10;
	cout << ans << endl;
}
int main()
{
	cin >> n;
	if (n == 0) cout << 1 << endl;
	else
	if (n < 10) {
		int x = 1;
		for (int i = 1; i <= n; i++) x *= i;
		while (x % 10 == 0) x /= 10; x = x % 10;
		cout << x << endl;
	}else solve1();
//	system("pause");
	return 0;
}

