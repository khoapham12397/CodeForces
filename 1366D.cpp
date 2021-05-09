#include <iostream>
#include<algorithm>
#include <vector>
#include <bitset>
using namespace std;
typedef vector<int> vi;
bitset<10000010> bs;
int n, a[500010], d[500010][2], us[10000010],m;

void sieve(int n) {
	bs.set(); bs[0] = bs[1] = 0;
	for (int i = 2; i <= n; i++) {
		if (bs[i]) {
			for (int j = i*i; j <= 10000000; j+=i) {
				bs[j] = 0;
				us[j] = i;
			}
		}
	}
}
void solve() {
	sieve(3162);
	cin >> n;
	
	for (int i = 0; i < n; i++) cin >> a[i];
	
	for (int i = 0; i < n; i++) {
		int x = a[i];
		if (!bs[x]) {
			int p = us[x];
			while (x%p == 0) x /= p;
			if (x == 1) {
				d[i][0] = d[i][1] = -1;
			}
			else d[i][0] = p, d[i][1] = x;
		}
		else  d[i][0] = d[i][1] = -1;
	}
	
	for (int j = 0; j < 2; j++) {
		for (int i = 0; i < n; i++) cout << d[i][j] << " ";
		cout << endl;
	}
}
int main()
{
	solve();
//	system("pause");
    return 0;
}

