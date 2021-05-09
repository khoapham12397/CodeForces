#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;
int n,s0[100010],s1[100010],s0r[100010],s1r[100010];
ll c01, c10;
string S;
void solve() {
	cin >> S; n = S.length();
	cin >> c01 >> c10;
	ll res = 0;
	ll x0 = 0,x1=0;
	for (int i = 0; i < n; i++) {
		if (S[i] == '0') x0++;
		if (S[i] == '1') x1++;
		s0[i] = x0; s1[i] = x1;
	}
	x0 = x1 = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (S[i] == '0') x0++;
		if (S[i] == '1') x1++;
		s0r[i] = x0; s1r[i] = x1;
	}
	for (int i = 1; i < n; i++) {
		if (S[i] == '0') res += ll(s1[i - 1])*c10;
		if (S[i] == '1') res += ll(s0[i - 1])*c01;
	}
	x0 = x1 = 0;
	for (int i = 0; i < n; i++) {
		if (S[i] == '0') x0++;
		if (S[i] == '1') x1++;
		if (S[i] == '?') {
			ll val0 = 0, val1 = 0;
			val0 += x1*c10 + ll(s1r[i + 1]) *c01;
			val1 += x0*c01 + ll(s0r[i + 1]) *c10;
			if (val0 < val1) x0++, res+= val0;
			else x1++, res += val1;
		}
	}
	cout << res << endl;
}

int main()
{
	solve();
	//system("pause");
    return 0;
}

