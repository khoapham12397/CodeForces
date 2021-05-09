#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
int M,D,W;
int gcd(int a, int b) {
	if(b==0) return a;
	return gcd(b, a%b);
}
void solve() {
	
	int d1,ct=min(M,D);
	if (D - 1 > W) d1 = gcd(D - 1, W);
	else d1 = gcd(W, D - 1);

	int t = W / d1;
	int x = ct / t, r=ct%t;
	ll ans = 0; // 
	ans =  ll(x)*ll(x - 1) / 2 * ll(t - r) + ll(r)*ll(x + 1)*ll(x) / 2;
	cout << ans << endl;
}
int main()
{
	int T; cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> M >> D >> W;
		solve();
	}
//	system("pause");
    return 0;
}

