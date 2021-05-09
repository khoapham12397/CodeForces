#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int n;
string S, T;
void solve() {
	cin >> n;
	cin >> S >> T;
	int cnts[26],cntt[26];
	for (int i = 0; i < 26; i++) cnts[i]=cntt[i] = 0;
	for (int i = 0; i < n; i++) {
		int x = int(S[i]) - 97, y= int(T[i])-97;
		cnts[x]++;  cntt[y]++;
	}
	bool ok = false;
	for (int i = 0; i < 26; i++) {
		if (cnts[i] != cntt[i]) { cout << "NO" << endl; return; }
		if (cnts[i] > 1) ok = true;
	}
	if (ok) {
		cout << "YES" << endl;
		return;
	}
	int a = 0, b = 0;

	for (int i = 1; i<n; i++) {
		for (int j = 0; j < i; j++) {
			if (int(S[j]) > int(S[i])) a++;
			if (int(T[j]) > int(T[i])) b++;
		}
	}
	if (a % 2 != b % 2) cout << "NO" << endl;
	else cout << "YES" << endl;
}
int main()
{
	int t; cin >> t;
	while (t--) solve();
//	system("pause");
    return 0;
}

