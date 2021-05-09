#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> i3;
int T, n ,pre[200001], ex1,ex2;
bool visited[200001],stoped=false;
vector<i3> cycs;
vector<int> ss;
vector<int> adj[200001];
void init() {
	for (int i = 1; i <= n; i++) adj[i].clear(), visited[i] = false, pre[i] = 0;
	cycs.clear();
	stoped = false;
}

void findCycle(int u) {
	visited[u] = true;
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (!visited[v]) {
			pre[v] = u; findCycle(v);
			if (stoped) return;
		}else if (visited[v] && pre[u] != v) {
			stoped = true;
			cycs.push_back(i3(u,ii(pre[u],v)));
			int x = pre[u],y=u;
			while (x != v) {
				cycs.push_back(i3(x, ii(pre[x], y)));
				y = x;
				x = pre[x];
			}
			cycs.push_back(i3(v, ii(y, u)));
			return;
		}
		if (stoped) return;
	}
}
//nhu the nay : 

int duyet(int u,int pa) {
	int ans = 1;
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (v != pa) ans+=duyet(v, u);
	}
	return ans;
}
void solve() {
	findCycle(1);
	//cout << "Length of cycle: " << cycs.size() << endl;
	
	ll x = 0,s=0;
	for (int i = 0; i < cycs.size(); i++) {
		int u = cycs[i].first,sl=1;
		for (int j = 0; j < adj[u].size(); j++) {
			int v=adj[u][j];
			if (v != cycs[i].second.first && v != cycs[i].second.second) sl += duyet(v,u);
		}
		ss.push_back(sl);
		x += ll(sl)*ll(sl);
		s += ll(sl);
	}
	ll ans = 0; 
	if (n % 2 == 0) ans += ll(n - 1)*ll(n / 2);
	else ans += ll((n - 1) / 2)*ll(n);
	cout << (s*s - x) / 2+ans << endl;
	
}

int main()
{
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n;
		
		for (int j = 0; j < n; j++) {
			int x, y; cin >> x >> y;
			adj[x].push_back(y); adj[y].push_back(x);
		}
		solve();
		init();
	}
//	system("pause");
	return 0;
}

