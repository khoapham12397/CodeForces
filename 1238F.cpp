#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<int> vi;
int n,ans=1,par[300001],f[300001];

vi adj[300001];
int duyet(int u) {
	int x1=0, x2=0;
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (par[u] != v) {
			par[v] = u;
			int x=duyet(v);
			if (x >= x1) {
				x2 = x1; x1 = x;
			}
			else if (x > x2) x2 = x;
		}
	}
	
	
	if (x1 == 0 && x2 == 0) {
		return 1;
	}
	int t = x1 + x2 + 1;
	if (adj[u].size() > 2)
		t+= adj[u].size()-2;
	ans = max(ans, t);
	int val = x1+1;
	if (adj[u].size() > 2)  val += adj[u].size()-2;

	return val;
}
void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) adj[i].clear();
	for (int i = 1; i < n; i++) {
		par[i] = 0;
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	par[n] = 0;
	ans = 0;
	duyet(1);
	cout << ans << endl;
}
int main()
{
	int T; cin >> T;
	for (int i = 0; i < T; i++) {
		solve();
		
	}
//	system("pause");
    return 0;
}

