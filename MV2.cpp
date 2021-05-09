
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
const int inf = 10000000;
typedef pair<int, int> ii;
typedef vector<pair<int, int>> vii;
typedef vector<int> vi;
ii nodes[200001];
int n, m, d[200001], F[200001];
vi adj[200001];
void readInput() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) adj[i].clear();

	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
	}
}
void solve() {
	
	priority_queue<ii, vii, greater<ii>>pq;
	for (int i = 1; i <= n; i++) d[i] = inf;

	pq.push(ii(0, 1)); d[1] = 0;
	while (!pq.empty()) {
		ii front = pq.top(); pq.pop();
		int u = front.second;
		if (d[u] > front.first) continue;
		for (int i = 0; i < adj[u].size(); i++) {
			int v = adj[u][i];
			if (d[v] > d[u] + 1) {
				d[v] = d[u] + 1;
				pq.push(ii(d[v], v));
			}
		}
	}
	
	cout << endl;
	
	for (int i = 0; i < n; i++) {
		nodes[i].first = d[i + 1];
		nodes[i].second = i + 1;
	}
	sort(nodes, nodes + n);
	
	int x = nodes[n - 1].second;
	F[x] = d[x];
	for (int i = 0; i < adj[x].size(); i++) {
		int v = adj[x][i];
		if (d[v] <= d[x]) {
			F[x] = min(F[x], d[v]);
		}

	}

	for (int i = n - 2; i >= 0; i--) {
		int x = nodes[i].second;
		F[x] = d[x];
		for (int i = 0; i < adj[x].size(); i++) {
			int v = adj[x][i];
			if (d[v] <= d[x]) {
				F[x] = min(F[x], d[v]);
			}
			else {
				F[x] = min(F[x], F[v]);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << F[i] << " ";
	}cout << endl;
	
}
int main()
{
	int T; cin >> T;
	for (int i = 0; i < T; i++) {
		readInput();
		solve();
	}
	
	return 0;
}

