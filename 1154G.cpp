#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> ii;
typedef long long ll;
int n;
const int gh= int(1e7);

ii a[1000010];
int gcd(int x, int y) {
	if (y == 0) return x;
	return gcd(y, x%y);
}
void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i].first; a[i].second = i+1;
	}

	sort(a, a + n);
	ll gtmin = ll(a[0].first)*ll(a[1].first) / ll(gcd(a[1].first, a[0].first));
	int u=a[0].second, v = a[1].second;
	
	for (int i = 1; i < n; i++) {
		ll val = ll(a[i].first)*ll(a[i-1].first/gcd(a[i].first, a[i-1].first)); 
		if (val < gtmin) {
			gtmin = val;
			u = a[i].second, v = a[i - 1].second;
		}
	}	
	int t=0;
	for (int i = 2; i < n; i++) {
		ll x = ll(a[i].first);
		if (x >= gtmin) {
			cout << min(u, v) << " " << max(u, v) << endl;
			return;
		}
		for (int j = 0; j < i; j++) {
			t++; if(t>=gh) break;
			if (x % a[j].first==0) {
				cout << min(a[i].second, a[j].second) << " " << max(a[i].second, a[j].second) << endl; 
				return;
			}
			int d = gcd(x, a[j].first);
			if(d==1) continue;
			ll val = x*ll(a[j].first/d);	
			if (val < gtmin) {
				gtmin = val;
				u = a[i].second, v = a[j].second;
			}
		}
		if(t>=gh) break;
	}
	cout << min(u, v) << " " << max(u, v) << endl;
}
int main()
{
	solve();
//	system("pause");
    return 0;
}

