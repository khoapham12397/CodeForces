#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<ii> vii;
int n,par[200010];
vii adj[200010];
ll ans = 0, f[200010][4];
// cu lam nay bitmask la ok ez: vl :
void cal(int u) {
	f[u][0] = f[u][1] =f[u][2]=f[u][3] = 0;
	ll u0=0, u1=0,u2=0, u3=0;
	ll res = 0;
	vector<int> childs;
	for (int i = 0; i < adj[u].size(); i++) {
		ii edge = adj[u][i];
		int v = edge.first,x= edge.second;
		if (par[u] == v) continue;
		par[v] = u; cal(v);
		childs.push_back(v);
		if (x == 1) {
			f[u][2] += f[v][2] + f[v][0];
			f[u][3] += f[v][3] + 1;
			ll x2 = f[v][2] + f[v][0],x3= f[v][3]+1;
			
			res += (x3 * u3) * 2 + (x3 * u2) + x2 * u3 + x3*u0;
			
			u3 = f[u][3];
			u2 = f[u][2];
		}
		else {
			f[u][0] += f[v][0] + 1;
			f[u][1] += f[v][1] + f[v][3];
			ll x0 = f[v][0] + 1, x1 = f[v][1] + f[v][3];
			res += x0* u0 * 2 + x0 * u1 + x0 * u3 + x1*u0;
			u0 = f[u][0];
			u1 = f[u][1];
		}
	}
	ans += f[u][3] * 2 + f[u][2];
	ans += f[u][0] * 2 + f[u][1];
	ans += res;

}

void solve() {
	cin >> n;
	for (int i = 1; i < n; i++) {
		int x, y, z; cin >> x >> y >> z;
		adj[x].push_back(ii(y, z)); adj[y].push_back(ii(x, z));
		par[i] = 0;
	}
	par[n] = 0;
	cal(1);
	cout << ans << endl;
}
int main()
{
	solve();
//	system("pause");
    return 0;
}

