#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef unsigned long long ull;
typedef pair<int, int> ii;
int T,freq[22];
int C[22][22];
ull k;
vector<int> rs;
void cal() {
	ull x = k;
	int m = 2, r;
	
	rs.clear();
	while (x > 0) {
		r = x%m;
		rs.push_back(r);
		x =ull(x / m);
		m++;
	}
}
void solve() {
	for (int i = 0; i < 21; i++) C[0][i] = C[i][i] = 1;
	for (int i = 2; i < 21; i++) {
		C[1][i] = i;
		for (int j = 2; j < i; j++) C[j][i] = (C[j][i - 1] + C[j - 1][i - 1]);
	}
	cal();
	for (int i = 0; i < 21; i++) freq[i] = 0;
	for (int i = 0; i < rs.size(); i++) freq[rs[i]]++;
	vector<ii> fr;

	for (int i = 0; i <= 20; i++) {
		if (freq[i] > 0) fr.push_back(ii(i, freq[i]));
	}
	int f[21],m;
	
	for (int i = 0; i < fr.size(); i++) {
		if (fr[i].first == 0) {
			f[i] = rs.size();
		}
		else {
			f[i] = rs.size() + 1 - fr[i].first;
		}
	}
	
	long long ans = 1; m = 0;
	for (int i = fr.size() - 1; i >= 0; i--) {
		ans *= C[fr[i].second][f[i] - m];
		m += fr[i].second;
	}
	cout << ans-1 << endl;
}
int main()
{
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> k;
		solve();
	}
//	system("pause");
	return 0;
}

