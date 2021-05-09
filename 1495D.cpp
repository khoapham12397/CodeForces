#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
int n, m , d[410][410];
int inf = int(1e9), res[410][410], ml[401],par[401][401];
ll mod = 998244353, f[401][401];
vi adj[401];
vi rel[401][401];
bool inSet[410];

void solve() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		adj[x].push_back(y); adj[y].push_back(x);
	}
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) d[i][j] = inf;
	
	for (int i = 1; i <= n; i++) {
		d[i][i] = 0;
		for (int j = 0; j < adj[i].size(); j++) {
			d[i][adj[i][j]] = 1;
		}
	}


	for (int i = 1; i <= n; i++) {
		queue<int> q;
		vi vs; vs.assign(n + 1, -1);
		vi fre; fre.assign(n + 1, 0);
		vs[i] = 0;
		for (int j = 0; j < adj[i].size(); j++) {
			int x = adj[i][j];
			par[i][x] = i;
			q.push(x); f[i][x] = 1; rel[i][1].push_back(x); fre[x] = 1;
			vs[x] = 1;
		}
		ll val = 1;
		int t = adj[i].size(),t1=0,lv=1;
		while (t > 0) {
			lv++; 
			for (int j = 0; j < t; j++) {
				int v = q.front(); q.pop();
				val = (val * ll(fre[v])) % mod;
				for (int j1 = 0; j1 < adj[v].size(); j1++) {
					int  u = adj[v][j1];
					if (vs[u]==-1) { 
						par[i][u] = v;
						q.push(u); d[i][u] = d[i][v] + 1;
						f[i][u] += f[i][v];
						fre[u] = 1;
						vs[u] = lv; t1++; rel[i][lv].push_back(u);
					}
					else if (vs[u] == lv) { f[i][u] += f[i][v]; fre[u]++; }
				}
			}
			t = t1; t1 = 0;
		}
		res[i][i] = val;
		ml[i] = lv - 1;
		
	}
	
	
	for (int s = 1; s < n; s++) {
		for (int t = s+ 1; t <= n; t++) {
			if (f[s][t] > 1) { res[s][t] = res[t][s] = 0; continue; }
			bool  ok = true;
			vii vt;
			vi paths, cnt(n+1,0); paths.push_back(t);
			
			int x = t;
			while (x != s) {
				x = par[s][x]; paths.push_back(x);
			}
			for (int k = 1; k <= n; k++) {
				int x = d[s][t];
				if (k == t || k == s) continue;
				if (x == d[s][k] + d[k][t]) {
					continue;
				}
				if (x + d[t][k] == d[s][k]) {
					//nam khuc duoi:
					for (int i = 0; i < adj[k].size(); i++) {
						int v = adj[k][i];
						if (d[t][v] + d[s][t] == d[s][v] && d[t][v] + 1 ==d[t][k]) {
							cnt[k]++;
						}
					}
					continue;
				}
				
				if (x + d[s][k] == d[t][k]) {
					//nam khuc dau:
					for (int i = 0; i < adj[k].size(); i++) {
						int v = adj[k][i];
						if (d[s][v] + d[s][t] == d[t][v] && d[s][v] + 1==d[s][k]) {
							cnt[k]++;
						}
					}
					continue;
				}
				int y = d[s][k], z = d[t][k];
				if ((x + y + z) % 2 == 1) { res[s][t] = res[t][s] = 0; ok = false; break; }
				int gt = ((x + z - y) >> 1);
				if (gt >= paths.size()-1) { res[s][t] = res[t][s] = 0; ok=false; break; }
				int  vu = paths[gt]; 
				if (d[vu][k] != (y + z - x) >> 1) { res[s][t] = res[t][s] = 0; ok=false;break; }
				for (int i = 0; i < adj[k].size(); i++) {
					int v = adj[k][i];
					if (d[vu][v] == d[vu][k] - 1 && d[s][v] == d[s][vu] + d[vu][v] && d[t][v] == d[t][vu] + d[vu][v]) {
						cnt[k]++;
					}
				}
			}
			if (!ok) continue;
			ll val = 1;
			for (int i = 1; i <= n; i++) {
				if (cnt[i] != 0) val = (val*ll(cnt[i])) % mod;
			}
			res[s][t] = res[t][s] = val;
			
		}
		
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << res[i][j] << " ";
		}cout << endl;
	}
}

int main()
{
	solve();
	//system("pause");
    return 0;
}

