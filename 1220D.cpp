#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef unsigned long long ull;
int n,fre[65],sm[200001];
ull b[200001];
void solve() {
	cin >> n;
	vector<ull> vt;
	for (int i = 0; i < 64; i++) fre[i] = 0;
	int sl = 0;
	for (int i = 0; i < n; i++) {
		ull x; cin >> x; b[i] = x;
		int t = 0;
		while (x % 2 == 0) x /= 2,t++;
		fre[t]++; sm[i] = t;
	}
	int ind = 0, gtmax = 0;
	for (int i = 0; i < 64; i++) {
		if (fre[i] > gtmax) {
			gtmax = fre[i]; ind = i;
		}
	}
	for (int i = 0; i < n; i++) {
		if (sm[i] != ind) vt.push_back(b[i]);
	}
	cout << vt.size() << endl;
	for (int i = 0; i < vt.size(); i++) cout << vt[i] << " "; cout << endl;
}
int main()
{
	solve();
	//system("pause");
    return 0;
}

