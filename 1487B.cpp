#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n,k;
void solve() {
	cin >> n >> k;
	if (n % 2 == 1) {
		int x = (n - 1) / 2;
		int t = (k - 1) / x, r= (k-1)%x;
		cout << (t + x*t + r) % n + 1<<endl;
	}
	else cout << (k-1)%n+1 << endl;
}
int main()
{
	int T; cin >> T;
	for (int i = 0; i < T; i++)solve();
//	system("pause");
    return 0;
}

