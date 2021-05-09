#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
ll f0[200010], f1[200010], sf0[200010], sf1[200010], n;
int par[200010];
ll d[200010], sd[200010],ans= 0;
vi adj[200010];
void duyet(int u) {
	f0[u] = f1[u] = d[u] = 0;
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (v != par[u]) {
			par[v] = u;
			duyet(v);
			f0[u] += f1[v];
			f1[u] += f0[v]+1;
			d[u] += d[v] + ll(f0[v]) + ll(f1[v]) + 1;
		}
	}
}
void cal(int u) {
	int p = par[u];
	
	ll vp = sd[p] - (d[u] + ll(f0[u]) + ll(f1[u]) + 1);
	
	int x0 = sf1[p] - f0[u] - 1, x1= sf0[p] - (f1[u]);
	sf0[u] = x0 + f0[u]; 
	
	sf1[u] = x1 + f1[u]+1;

	sd[u] = vp + d[u] + x0+x1+1;
	ans = ans + ((sd[u] + sf1[u]) >> 1);

	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (par[u] != v) cal(v);
	}
}
void solve() {
	cin >> n;
	for (int i = 1; i < n; i++) {
		int x, y; cin >> x >> y;
		adj[x].push_back(y); adj[y].push_back(x);
		par[i] = 0;
	}
	par[n] = 0;
	duyet(1);
	
	sd[1] = d[1]; 
	
	sf0[1] = f0[1]; sf1[1] = f1[1];
	ans = ans + ((sd[1] + ll(f1[1])) >> 1);
	for (int i = 0; i < adj[1].size(); i++) {
		cal(adj[1][i]);
	}
	cout << (ans>>1) << endl;
}
int main()
{
	solve();
//	system("pause");
    return 0;
}

