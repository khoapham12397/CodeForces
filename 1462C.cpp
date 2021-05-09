#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n,ok=0;
int used[10],b[11],c[11],sl=100;
void cal(int t,int s) {
	for (int i = 9; i>=1; i--) {
		if (!used[i]) {
			b[t] = i;
			if (s + i == n) {
				sort(b, b + t+1);
				sl = t + 1; ok = 1;
				return;
			}
			else {
				if (s + b[t] < n) used[i]=1,cal(t + 1, s + b[t]);
			}
			used[i] = 0;
		}
		if (ok) return;
	}
}
void solve() {
	if (n == 0) { cout << 0 << endl; return; }
	ok = false;
	for (int i = 0; i < 10; i++) used[i] = 0;
	cal(0, 0);
	if (!ok) { cout << -1 << endl; return; }
	for (int i = 0; i <sl; i++) {
		cout << b[i];
	}cout << endl;
}
int main()
{
	int T; cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n;
		solve();
	}
//	system("pause");
    return 0;
}

