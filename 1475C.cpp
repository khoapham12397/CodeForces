#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
int a,b,k;
vi cnta, cntb;
void solve() {
	cin >> a >> b >> k;
	cnta.assign(a + 1, 0); cntb.assign(b + 1, 0);
	
	vector<ii> ps; ps.assign(k + 1, ii(0,0));
	for (int i = 0; i < k; i++) {
		int x; cin >> x; ps[i].first = x;
		cnta[x]++;
	}
	for (int i = 0; i < k; i++) {
		int x; cin >> x; ps[i].second = x;
		cntb[x]++;
	}
	ll ans = 0;
	for (int i = 0; i < k; i++) {
		ans += ll(k) - ll(cnta[ps[i].first]) - ll(cntb[ps[i].second]) + 1;
	}
	cout << ans/2 << endl;
}
int main()
{
	int t; cin >> t;
	while(t--) solve();
//	system("pause");
    return 0;
}

