#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
int n,m,a[200001],b[200001];
ll mod = 998244353;
ll ans = 1;
vector<int> vt;
int cal(int t) {
	int i = vt[t],x= b[m-1-t];
	int j = i - 1;
	while (a[j] >= x) j--;
	return i - j;
}
void solve() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < m; i++) cin >> b[i];
	int ind = m-1;
	int i = n - 1,j;
	while (a[i] != b[m - 1]) {
		if (a[i] < b[m - 1]) { cout << 0 << endl; return; }
		i--;
	}
	j = i - 1; ind--;
	vt.push_back(i);
	while (ind>=0) {
		while (a[j] != b[ind]) {
			if (a[j] < b[ind]) { 
				cout << 0 << endl; return; 
			} 
			j--; 
		}
		vt.push_back(j);
		i = j; j = i - 1;
		ind--;
	}
	for (int i = 0; i < vt[m - 1]; i++) {
		if (a[i] < b[0]) { cout << 0 << endl; return; }
	}
	for (int i = 0; i < m - 1; i++) ans =(ans* cal(i))%mod;
	cout << ans << endl;

}
int main()
{
	solve();
//	system("pause");
    return 0;
}

