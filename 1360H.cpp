#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
typedef  long long ll;
typedef pair<ll, ll> l2;
ll n,m;
ll a[110];
ll p2[62];
void solve() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		a[i] = 0;
		for (int j = 0; j < m; j++) a[i] += (ll(s[j]) - ll(48))*p2[m - 1 - j];
	}
	sort(a, a + n);
	vector<l2> rs;
	ll x = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] != x) {
			rs.push_back(l2(x, a[i] - ll(1)));
		}
		x = a[i] + 1;
	}
	
	if (x <= (p2[m] - 1)) rs.push_back(l2(x, (p2[m] - 1)));
	ll k = p2[m] - n;
	ll t = ll((k+1) / 2);
	
	x = 0;
	for (int i = 0; i < rs.size(); i++) {
		ll sl = rs[i].second - rs[i].first + 1;
		if (x + sl >= t) {
			ll  val= rs[i].first + t - x - 1;
			string s = ""; int t = 0;
			for(int j=0;j<m;j++){
				if (val % 2 == 1) s += "1";
				else s += "0";
				val >>= 1;
			}
			for (int j = m - 1; j >= 0; j--) cout << s[j];
			cout << endl;
			return;
		}
		else x += sl;
	}
}
int main()
{
	p2[0] = 1; for (int i = 1; i < 61; i++) p2[i] = p2[i - 1] * 2;
	int t; cin >> t;
	while (t--) solve();
//	system("pause");
    return 0;
}

