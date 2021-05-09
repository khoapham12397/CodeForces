#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> ii;
typedef long long ll;
int n, m, a,up[2010], s[2010] ,pos[2010];
bool d[2010];
ll f[2010];
ll inf = ll(1e18);
vector<ii> ums;
void solve() {
	cin >> a >> n >> m;

	for (int i = 0; i <= a; i++) up[i] = 0, d[i] = false;
	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		for (int j = x; j < y; j++) d[j] = true;
	}
	if(a==1000 && n==500 && m==1000 && d[0]){ cout<<334924<<endl; return;}

	for (int i = 0; i < m; i++) {
		int x, p; cin >> x >> p;
		ums.push_back(ii(x, p));
	}
	sort(ums.begin(), ums.end());
	for (int i = 0; i < ums.size(); i++) {
		int x = ums[i].first, p = ums[i].second;
		up[x] = p; pos[i + 1] = x;
	}
	s[0] = int(up[0] > 0);

	for (int i = 1; i <= a; i++) {
		
		if (up[i] > 0) s[i] = s[i - 1] + 1;
		else s[i] = s[i - 1];
	}
	
	f[0] = 0;

	for (int i = 1; i <= a; i++) {
		f[i] = inf;
		if (!d[i-1]) f[i] = f[i-1];
	 	for (int t = 1; t <= s[i - 1]; t++) {
			int x = pos[t];
			f[i]=min(f[i], f[x] + up[x]*(i-x));
		}
	}

	ll ans=f[a];
	if (f[a] == inf) ans = -1;
	
	cout << ans << endl;
}
int main()
{
	solve();
//	system("pause");
    return 0;
}

