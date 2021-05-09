#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<ii> vii;
typedef vector<int> vi;
int n1, n2, n3, n4, m1, m2, m3; 
ii dp3[150010], dp2[150010], dp1[150010];
int a1[150010],a2[150010],a3[150010],inf = int(1e9)+7;
int tt4[150010], tt2[150010], tt3[150010];
ii a4[150010];
vector<vi> rel1, rel2, rel3;
void solve() {
	cin >> n1 >> n2 >> n3 >> n4;
	for (int i = 1; i <= n1; i++) cin >> a1[i];
	for (int i = 1; i <= n2; i++) cin >> a2[i];
	for (int i = 1; i <= n3; i++) cin >> a3[i];
	for (int i = 1; i <= n4; i++) cin >> a4[i].first, a4[i].second = i;
	sort(a4 + 1, a4 + n4 + 1);
	for (int i = 1; i <= n4; i++) tt4[a4[i].second] = i;
	rel1.assign(n1 + 1, vi()); rel2.assign(n2 + 1, vi());rel3.assign(n3 + 1, vi());
	cin >> m1;
	for (int i = 0; i < m1; i++) {
		int x, y; cin >> x >> y;
		rel1[x].push_back(y);
	}
	cin >> m2;
	for (int i = 0; i < m2; i++) {
		int x, y; cin >> x >> y;
		rel2[x].push_back(y);
	}
	cin >> m3;
	for (int i = 0; i < m3; i++) {
		int x, y; cin >> x >> y;
		rel3[x].push_back(y);
	}
	for (int i = 1; i <= n3; i++) {
		for (int j = 0; j < rel3[i].size(); j++) rel3[i][j] = tt4[rel3[i][j]];
		sort(rel3[i].begin(), rel3[i].end());
	}
	for (int i = 1; i <= n3; i++) {
		int ind = 1;
		for (int j = 0; j < rel3[i].size(); j++) {
			if (rel3[i][j] == ind) ind++;
			if (ind > n4) break; 
		}
		if (ind > n4) dp3[i] = ii(inf, i);
		else  dp3[i] = ii(a3[i] + a4[ind].first, i);
	}
	sort(dp3 + 1, dp3 + n3 + 1);

	for (int i = 1; i <= n3; i++) tt3[dp3[i].second] = i;
	for (int i = 1; i <= n2; i++) {
		for (int j = 0; j < rel2[i].size(); j++) rel2[i][j] = tt3[rel2[i][j]];
		sort(rel2[i].begin(), rel2[i].end());
	}
	for (int i = 1; i <= n2; i++) {
		int ind = 1;
		for (int j = 0; j < rel2[i].size(); j++) {
			if (ind > n3) break;
			if (rel2[i][j] == ind) ind++;
		}
		if (ind > n3 || dp3[ind].first == inf) dp2[i] = ii(inf, i);
		else dp2[i] = ii(dp3[ind].first + a2[i], i);
	}
	sort(dp2 + 1, dp2 + n2 + 1);
	for (int i = 1; i <= n2; i++) tt2[dp2[i].second] = i;
	for (int i = 1; i <= n1; i++) {
		for (int j = 0; j < rel1[i].size(); j++) rel1[i][j] = tt2[rel1[i][j]];
		sort(rel1[i].begin(), rel1[i].end());
	}
	int ans = inf;
	for (int i = 1; i <= n1; i++) {
		int ind = 1;
		for (int j = 0; j < rel1[i].size(); j++) {
			if (ind > n2) break;
			
			if (rel1[i][j] == ind) ind++;
		}
		if (ind > n2 || dp2[ind].first == inf) dp1[i] = ii(inf, i);
		else {
			dp1[i] = ii(dp2[ind].first + a1[i], i);
			ans = min(ans, dp1[i].first);
		}
	}
	if (ans != inf) cout << ans << endl;
	else cout << -1 << endl;
}
int main()
{
	solve();
//	system("pause");
    return 0;
}

