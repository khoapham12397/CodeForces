#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int n,k,f[100010][26];
string s;
void solve() {
	cin >> n >> k;
	cin >> s;
	
	if (n%k != 0) {
		cout << -1 << endl;
		return;
	}
	for (int i = 0; i < 26; i++) f[0][i] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 26; j++) f[i][j] = f[i - 1][j];
		f[i][int(s[i-1]) - 97]++;
	}
	bool ok = true;
	for (int i = 0; i < 26; i++) {
		if (f[n][i] % k != 0) {
			ok = false; break;
		}
	}
	if (ok) { cout << s << endl; return; }
	string res = "";
	for (int i = n; i >= 1; i--) {
		int p = int(s[i-1]) - 97;
		if (p == 25) continue;
		int ad[26],val=0;
		
		for (int j = 0; j < 26; j++) {
			ad[j] = 0;
			if (f[i - 1][j] != 0 && f[i-1][j]%k!=0) {
				int r = k - f[i - 1][j] % k;
				ad[j] += r; val += r;
			}
		}
		
		if (val > n - i + 1) continue;
		int r1 = n - i + 1 - val;
		if (ad[p + 1] > 0) {
			ad[0] += r1;

			for (int j = 1; j < i; j++) res += s[j - 1];
			res += char(p+1 + 97);
			ad[p + 1]--;
			for (int t = 0; t < 26; t++) {
				for (int j = 0; j < ad[t]; j++) res += char(t + 97);
			}
			cout << res << endl;
			return;
		}
		else {
			if (r1 > 0) {
				ad[p + 1] = k;
				ad[0] += r1 - k;
				for (int j = 1; j < i; j++) res += s[j - 1];
				res += char(p + 1 + 97);
				ad[p + 1]--;
				for (int t = 0; t < 26; t++) {
					for (int j = 0; j < ad[t]; j++) res += char(t + 97);
				}
				cout << res << endl; return;
			}
			else {
				int ind = -1;
				for (int j = p + 1; j < 26; j++) if (ad[j] > 0) {
					ind = j; break;
				}
				if (ind != -1) {
					for (int j = 1; j < i; j++) res += s[j - 1];
					res += char(ind + 97);
					ad[ind]--;
					for (int t = 0; t < 26; t++) {
						for (int j = 0; j < ad[t]; j++) res += char(t + 97);
					}
					cout << res << endl; return;
				}
			}
		}
		
	}
	cout << -1 << endl;
}
int main()
{
	int t; cin >> t;
	while (t--) solve();
//	system("pause");
    return 0;
}

