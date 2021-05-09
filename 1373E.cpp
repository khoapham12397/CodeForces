#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;

const string init = "999999999999999999";
int n,k;
bool cmp(string s,string p) {
	if (s.length() < p.length()) return 1;
	if (s.length() > p.length()) return 0;
	return (s < p);
}
string cal(int x) {
	if (x == 0) return "";
	string ans = "";
	if (x < 8) {
		ans += char(x + 48);
		return ans;
	}
	string ra = "";
	ra += char(56); x -= 8;
	while (x >= 9) {
		ra += char(57);
		x -= 9;
	}
	if (x > 0) ra += char(x + 48);
	int len = ra.length();
	for (int i = len - 1; i >= 0; i--) ans += ra[i];
	return ans;
}
void solve() {
	cin >> n >> k;
	string ans = "999999999999999999";
	for (int i = 0; i < 10; i++) {
		if (i + k > 9) {
			int r = (i + k) % 10;
			int d = r*(r + 1) / 2 + 45- i*(i-1)/2;
			
			int a = 11 + r - i, b = (10 - i), c= n-d-r-1;
			
			if (c < 0) continue; 
			int ght = c / (9*b);
			for (int t = ght; t >= 0; t--) {
				int val = c - 9*b*t;
				if (val %a == 0) {
					string x = cal(val / a);
					for (int j = 0; j < t; j++) x += '9';
					x += char(i + 48);
					if (cmp(x, ans)) ans = x;
				}
			}
		}
		else {
			int r = i + k;
			int d = 0; 
			if (i > 0) d = r*(r + 1) / 2 - i*(i - 1) / 2;
			else d = r*(r + 1) / 2;
			if(n<d) continue;
			if ((n - d) % (k + 1) == 0) {
				int val = (n - d) / (k + 1);
				int ght = val / 9;
				for (int t = ght; t >= 0; t--) {
					
					string x = cal(val-9*t);
					for (int j = 0; j < t; j++) x += '9';
					x += char(i + 48);
					if (cmp(x, ans)) ans = x;
				}
			}
		}
	}
	if (ans == init) cout << -1 << endl;
	else cout << ans << endl;
}
int main()
{
	int t; cin >> t;
	while (t--) solve();
//	system("pause");
    return 0;
}

