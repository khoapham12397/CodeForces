#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int a,b,k;
void solve() {
	cin >> a >> b >> k;
	
	string x, y;
	if (b == 1) {
		if (k > 0) { cout << "No" << endl; return; }
		cout << "Yes" << endl;
		for (int i = 0; i < 2; i++) {
			cout << 1;
			for (int i = 0; i < a; i++) cout << 0;
			cout << endl;
		}
		return;
	}

	if (b == 2) {
		if (k > a) { cout << "No" << endl; return; }
		cout << "Yes" << endl;
		y += '1';
		for (int i = 0; i < k; i++) x += '0', y += '0';
		x += '1';
		for (int i = 0; i < a - k; i++) x += '0', y += '0';
		for (int i = 0; i < b - 1; i++) x += '1', y += '1';

		for (int i = a + b - 1; i >= 0; i--) cout << x[i]; cout << endl;
		for (int i = a + b - 1; i >= 0; i--) cout << y[i]; cout << endl;
		return;
	}
	if (k > a + b - 2) { cout << "No" << endl; return; }
	if (a == 0) {
		if (k > 0) { cout << "No" << endl; return; }
		cout<<"Yes"<<endl;
		for (int i = 0; i < a+b; i++) x += '1',y+='1';
		for (int i = a + b - 1; i >= 0; i--) cout << x[i]; cout << endl;
		for (int i = a + b - 1; i >= 0; i--) cout << y[i]; cout << endl;
		return;
	}
	cout << "Yes" << endl;
	if (k == 0) {
		
		for (int i = 0; i < a; i++) x += '0', y += '0';
		for (int i = 0; i < b; i++) x += '1', y += '1';
		for (int i = a + b - 1; i >= 0; i--) cout << x[i]; cout << endl;
		for (int i = a + b - 1; i >= 0; i--) cout << y[i]; cout << endl;
		return;
	}
	x += '0'; y += '1';
	int sl0 = a - 1, sl1= b-2;
	for (int i = 0; i < k - 1; i++) {
		if (sl0 > 0) x += '0', y += '0', sl0--;
		else x += '1', y += '1',sl1--;
	}
	x += '1'; y += '0';
	for (int i = 0; i < sl0; i++) x += '0', y += '0';
	for (int i = 0; i <= sl1; i++) x += '1', y += '1';
	for (int i = a + b - 1; i >= 0; i--) cout << x[i]; cout << endl;
	for (int i = a + b - 1; i >= 0; i--) cout << y[i]; cout << endl;
}
int main()
{
	solve();
//	system("pause");
    return 0;
}

