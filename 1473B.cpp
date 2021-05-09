#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int gcd(int x,int y) {
	if (y == 0) return x;
	return gcd(y, x%y);
}
void solve() {
	string s1, s2,sb,sm;
	cin >> s1 >> s2;
	int m, n,d;
	if (s1.length() == s2.length()) {
		for (int i = 0; i < s1.length(); i++) {
			if (s1[i] != s2[i]) { cout << -1 << endl; return; }
		}
		cout<<s1<<endl;
		return;
	}
	else if (s1.length() > s2.length()) { sb = s1; sm = s2; }
	else sb = s2, sm = s1;
	m = sb.length(), n = sm.length();
	d = gcd(m, n);
	for (int i = 0; i < m; i++) {
		if (sm[(i%n)] != sb[i]) { cout << -1 << endl; return; }
	}
	for (int i = d; i < n; i++) {
		if (sm[i] != sm[i%d]) { cout << -1 << endl; return; }
	}
	int l = m/d;
	for (int i = 0; i < l; i++) cout << sm;
	cout << endl;
}
int main()
{
	int t; cin >> t;
	while (t--) solve();
//	system("pause");
    return 0;
}

