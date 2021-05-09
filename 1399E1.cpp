#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int, int> ii;
typedef pair<ll, ii> i3;
typedef pair<ll, int> li;
typedef vector<ii> vii;

int n,par[100010],f[100010];

ll S,cv= 0;
vii adj[100010];
priority_queue<i3, vector<i3>, less<i3>> heap;

void cal(int u) {
	bool leaf = true;
	f[u] = 0;
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i].first;

		if (v != par[u]) {
			int w = adj[u][i].second;
			leaf = false;
			par[v] = u;
			cal(v);
			ll val = ll(w) - ll(w/2);
			cv += ll(w)*ll(f[v]);
			heap.push(i3(val*ll(f[v]),ii(f[v],w)));
			f[u] += f[v];
		}
	}
	if (leaf) f[u] = 1;
}
void solve() {
	cin >> n >> S;
	cv = 0;
	for (int i = 1; i <= n; i++) adj[i].clear(),f[i]=0;
	while (!heap.empty()) heap.pop();
	for (int i = 1; i < n; i++) {
		par[i] = 0;
		int x, y, w; cin >> x >> y >> w;
		adj[x].push_back(ii(y, w));
		adj[y].push_back(ii(x, w));
	}par[n] = 0;
	
	cal(1);
	int t = 0;
	
	while (cv > S) {
		i3 front = heap.top(); heap.pop();
		
		ll x = front.first;
		
		int w = front.second.first;
		cv -= x; 
		ll gt = ll(front.second.second >>1);
		ll val = (ll(gt) - ll(gt >> 1))* ll(w);
				
		heap.push(i3(val, ii(w,gt)));
		t++;
	}
	
	cout << t << endl;
}
int main()
{
	int t; cin >> t;
	while (t--) solve();
//	system("pause");
    return 0;
}

