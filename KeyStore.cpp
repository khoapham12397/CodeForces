#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int>ii;
int T,freq[22];
int C[21][21];
ll K;
vector<ii> f;
vector<int> rs,vs;
void cal() {
	ll x = K,m=2;
	while (x > 0) {
		ll r = x%m;
		rs.push_back(r);
		x = ll (x / m);
		m++;
	}
}
void init() {
	f.clear(); rs.clear(); vs.clear();

}
void solve() {
	cal();
	
	for (int i = 0; i <= 20; i++) freq[i] = 0;
	for (int i = 0; i < rs.size(); i++) freq[rs[i]]++;
	for (int i = 0; i <= 20; i++) {
		if (freq[i] > 0) f.push_back(ii(i,freq[i]));
	}
	
	for (int i = 0; i < f.size(); i++) {
		if (f[i].first == 0) vs.push_back(rs.size());
		else { vs.push_back(rs.size()+1-f[i].first); }
	}
	ll ans=1;
	int m=0;
	if (f[0].first != 0) {
		for (int i = f.size() - 1; i >= 0; i--) {
			ans = (ans*C[f[i].second][vs[i] - m]);
			m += f[i].second;
		}
	}
	else {
		ans = 0;
		for (int j = 1; j< f.size(); j++) {
			ll val = 1; m=0;
			for (int i = f.size() - 1; i > 0; i--) {
				int t=f[i].second;
				if (i == j) t--;
				val = (val* C[t][vs[i] - 1 - m]);
				m += t;
			}
			ans += val;
		}
		
	}
	cout << ans-1 << endl;
}
int main()
{
	for (int i = 0; i <= 20; i++) C[i][i] = C[0][i] = 1;
	for (int i = 2; i <= 20; i++) {
		C[1][i] = i;
		for (int j = 2; j < i; j++) C[j][i] = (C[j][i - 1] + C[j - 1][i - 1]);
	}
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> K; solve();
		init();

	}
//	system("pause");
    return 0;
}

