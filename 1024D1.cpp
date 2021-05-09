#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int n,f[2010],cnt1[2010];
string s;
void solve() {
	cin >> s;
	string ans = "";
	int n = s.length(),ind=n;
	f[n] = 0; cnt1[n] = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (s[i] == '0') f[i] = f[i + 1] + 1,ind = i,cnt1[i]=cnt1[i+1];
		else {
			cnt1[i] = cnt1[i + 1] + 1;
			f[i] = max(f[ind], cnt1[i]);
		}
	}
	

	for (int i = n - 1; i >= 0; i--) {
		if (s[i] == '0') ans += '0';
		else {
			if (f[i] == f[i + 1]) ans += '1';
			else ans += '0';
		}
	}
	string ra = "";  for (int i = n - 1; i >= 0; i--) ra += ans[i];
	cout << ra << endl;
}
int main()
{
	solve();
//	system("pause");
    return 0;
}

