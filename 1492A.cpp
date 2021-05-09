#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
int main()
{
	int t; cin >> t;
	while (t--) {
		ll a, b, c, p; cin >>p>> a >> b >> c;
		ll x =min( (a - (p%a))%a, (b-(p%b))%b);
		x = min(x, (c - (p%c))%c );
		cout << x << endl;
	}
    return 0;
}