#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
int n;
void solve() {
	int n;
	cin >> n;
	vector<ll> a;
	for (int i = 0; i < 2 * n; i++) { ll x; cin >> x; a.push_back(x); }
	sort(a.begin(), a.end());
	for (int i = 0; i < 2 * n; i++) if (a[i] % 2 == 1) { cout << "NO" << endl; return; }
	vector<ll> d;
	for (int i = 0; i < 2 * n; i += 2) {
		if (a[i] != a[i + 1]) {
			cout << "NO" << endl; return;
		}
		d.push_back(a[i]);
	}
	ll t = 0,s=0;
	for (int i = 1; i < n; i++) {
		ll x = d[i] - d[i-1];
		if ((x % (2 * i)) != 0 || x==0) {
			cout << "NO" << endl; return; 
		}
		t += x / (2 * i);
		s += t;
	}
	ll val = d[0] - 2 * s;
	if(val>0 && val%(2*n)==0) cout << "YES" << endl;
	else cout << "NO" << endl;
}

int main()
{
	int t; cin >> t;
	while(t--) solve();
//	system("pause");
    return 0;
}

