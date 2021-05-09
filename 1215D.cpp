#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int n;
string s;
void solve() {
	cin >> n;
	cin >> s;
	int a = 0,t=0,b=0,c=0,d=0;
	for (int i = 0; i < n/2; i++) {
		if (s[i] == '?') a++,t++;
		else c += int(s[i]) - 48;
	}
	for (int i = n / 2; i < n; i++) {
		if (s[i] == '?') b++, t++;
		else d += int(s[i])-48;
	}
	if (t % 2 == 1) { cout << "Monocarp" << endl; return; }
	if (t == 0) {
		if (c == d) cout << "Bicarp" << endl;
		else cout << "Monocarp" << endl;
		return;
	}
	int ok = 1;
	if (a % 2 ==0) {
		int x = (a / 2) * 9 + c,y=d;
		int delta = abs(x - y);
		if (x > y) {
			if (delta > (b / 2) * 9) ok = 0;
		}
		else {
			if (delta > (a / 2) * 9) ok = 0;
		}

		int x1 = c, y1 = b / 2 * 9 + d;
		delta = abs(x1 - y1);
		if (x1 > y1) {
			if (delta > (b / 2) * 9) ok = 0;
		}
		else if (delta > (a / 2) * 9) ok = 0;
	}
	else {
		int x = (int(a / 2) + 1) * 9 + c,y=d;
		int delta = abs(x - y);
		if (x > y) {
			if (delta > (int(b / 2)+1) * 9) ok = 0;
		}
		else if (delta >int(a / 2) * 9) ok = 0;
		int x1 = c, y1 = d + (int(b / 2) ) * 9;
		delta = abs(x1 - y1);
		if (x1 > y1) {
			if (delta > (int(b /2)+1) * 9) ok = 0;
		}
		else if (delta > (int(a/ 2)) * 9) ok = 0;
	}
	if (ok) cout << "Bicarp" << endl;
	else cout << "Monocarp" << endl;
	
}
int main()
{
	solve();
//	system("pause");
    return 0;
}

