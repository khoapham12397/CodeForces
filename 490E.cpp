#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int n,a[100010],p10[9];
string s[100010];
void solve() {
	cin >> n; p10[0] = 1;
	for (int i = 0; i < n; i++) cin >> s[i];
	for (int i = 1; i < 10; i++) p10[i] = 10 * p10[i - 1];
	if (s[0][0] == '?') s[0][0] = '1';
	
	for (int i = 1; i < s[0].length(); i++) {
		if (s[0][i] == '?') s[0][i] = '0';
	}
	for (int i = 1; i < n; i++) {
		if (s[i].length() < s[i - 1].length()) {
			cout << "NO" << endl; return;
		}
		if (s[i].length() > s[i - 1].length()) {
			if (s[i][0] == '?') s[i][0] = '1';
			for (int j = 1; j < s[i].length(); j++)  if(s[i][j]=='?') s[i][j] = '0';
			continue;
		}
		if (s[i][0] != '?') {
			if (int(s[i][0]) < int(s[i - 1][0])) { cout << "NO" << endl; return; }
		}
		int ib=-1,is=-1;
		for (int j = 0; j < s[i].length(); j++) {
			if (s[i][j] != '?' && int(s[i][j]) > int(s[i - 1][j])) {
				ib = j; break;
			}
			if (s[i][j] != '?' && int(s[i][j]) < int(s[i - 1][j])) {
				is = j; break;
			}
		}
		if (ib != -1 ) {

			for (int j = 0; j < ib; j++) {
				if (s[i][j] == '?') s[i][j] = s[i - 1][j];
			}
			for (int j = ib + 1; j < s[i].length(); j++) {
				if (s[i][j] == '?') s[i][j] = '0';
			}
		}
		if (is != -1) {
			int idf= -1;
			for (int j = is - 1; j >= 0; j--) {
				if (s[i][j] == '?' && int(s[i - 1][j]) - 48 < 9) {
					s[i][j] = char(int(s[i - 1][j]) + 1);
					idf = j; break;
				}
			}
			if (idf != -1) {
				for (int j = 0; j < idf; j++) s[i][j] = s[i - 1][j];
				for (int j = idf + 1; j < s[i].length(); j++) if (s[i][j] == '?') s[i][j] = '0';
			}
			else {
				cout << "NO" << endl; return;
			}
		}
		if (is == -1 && ib == -1) {
			int idf = -1;
			for (int j = s[i].length() - 1; j >= 0; j--) {
				if (s[i][j] == '?' && int(s[i-1][j]) - 48 < 9) {
					s[i][j] = char(int(s[i - 1][j]) + 1);
					idf = j; break;
				}
			}
			if (idf != -1) {
				for (int j = idf - 1; j >= 0; j--) s[i][j] = s[i - 1][j];
				for(int j=idf+1;j<s[i].length();j++) if (s[i][j] == '?') s[i][j] = '0';
			}
			else {
				cout << "NO" << endl;
				return;
			}
			
		}
	}
	cout << "YES" << endl;
	for (int i = 0; i < n; i++)cout << s[i] << endl;
}
int main()
{
	solve();
//	system("pause");
    return 0;
}

