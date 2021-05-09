#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <functional>
using namespace std;
typedef pair<int, int> ii;
typedef pair<int,ii> i3;
typedef long long ll;

typedef pair<ll, int> li;
typedef vector<int> vi;

ll d[801][801],inf=ll(1e18);
vector<i3> edges;
map<int, bool> ms;
vi vers;
ll a[401][401];
int n,m,k ,ord[200010];
vector<ii> adj[810];
void djk(int s) {
	priority_queue<li, vector<li>, greater<li>> q;
	q.push(li(0, s));
	while (!q.empty()) {
		li front = q.top(); q.pop();
		int u = front.second;
		if (d[s][u] != front.first) continue;
		for (int i = 0; i < adj[u].size(); i++) {
			ii v = adj[u][i];
			if (d[s][v.first] > d[s][u] + ll(v.second)) {
				d[s][v.first] = d[s][u] + ll(v.second);
				q.push(li(d[s][v.first], v.first));
			}
		}
	}
}
void solve() {
	cin >> n >> m >> k;
	if (n <= 400) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j) a[i][j] = 0;
				else a[i][j] = inf;
			}
		}
		for (int i = 0; i < m; i++) {
			int x, y, z; cin >> x >> y >> z;
			a[x][y] = a[y][x] = z;
		}
		for (int i = 1; i <= n; i++) {
			for (int st = 1; st <= n; st++) {
				for (int sf = 1; sf <= n; sf++) {
					a[st][sf] = min(a[st][sf], a[st][i] + a[i][sf]);
				}
			}
		}
		
		vector<ll> ds;
		for (int i = 1; i < n; i++) for (int j = i + 1; j <= n; j++) {
			ds.push_back(a[i][j]);
		}

		sort(ds.begin(), ds.end());
		cout << ds[k - 1] << endl;
		return;
	}
	edges.assign(m, i3());
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		edges[i].first = z; edges[i].second = ii(min(x, y), max(x, y));
	}
	sort(edges.begin(), edges.end());
	
	for (int i = 0; i < k; i++) {
		int x = edges[i].second.first, y = edges[i].second.second;
		ms[x] = 1; ms[y] = 1;
	}
	
	map<int, bool>::iterator it;
	for (it = ms.begin(); it != ms.end(); it++) {
		vers.push_back(it->first);
	}
	sort(vers.begin(), vers.end());
	for (int i = 0; i < vers.size(); i++) ord[vers[i]] = i;
	for (int i = 0; i < k; i++) {
		int x = edges[i].second.first, y = edges[i].second.second,w= edges[i].first;
		adj[ord[x]].push_back(ii(ord[y], w));
		adj[ord[y]].push_back(ii(ord[x], w));
	}
	int sld = vers.size();
	for (int i = 0; i < sld; i++) for (int j = 0; j < sld; j++) {
		if (i == j) d[i][j] = 0;
		else d[i][j] = inf;
	
	}
	for (int i = 0; i < sld; i++) {
		djk(i);
	}
	vector<ll> ds;
	for (int i = 0; i < sld - 1; i++) for (int j = i + 1; j < sld; j++) ds.push_back(ll(d[i][j]));
	sort(ds.begin(), ds.end());
	cout << ds[k - 1] << endl;
}
int main()
{
	solve();
//	system("pause");
    return 0;
}

