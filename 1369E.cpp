#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
int n,m,w[100010],f[100010],d[100010];
bool used[200010];
vector<ii> a[100010];
vi res;
void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> w[i], f[i] = used[i] = 0;
	for (int i = 1; i <= m; i++) {
		int x, y; cin >> x >> y; f[x]++; f[y]++;
		a[x].push_back(ii(y,i)); a[y].push_back(ii(x,i));
	}
	priority_queue<ii, vector<ii>, less<ii>> q;
	for (int i = 1; i <= n; i++) {
		d[i] = w[i] - f[i];
		q.push(ii(d[i], i));
	}
	while (!q.empty()) {
		ii front = q.top(); q.pop();
		int u = front.second; 
		if (d[u] != front.first) continue;
		if (d[u] >= 0) {
			for (int i = 0; i < a[u].size(); i++) {
				int ind = a[u][i].second,v=a[u][i].first;
				if (!used[ind]) {
					res.push_back(ind);  used[ind] = 1;
					d[v]++; q.push(ii(d[v], v));
				}
			}
		}
		else break;
	}
	if (res.size() < m) cout << "DEAD" << endl;
	else {
		cout << "ALIVE" << endl;
		for (int i = res.size()-1; i >= 0; i--) cout << res[i] << " ";
		cout << endl;
	}
	
}
int main()
{
	solve();
//	system("pause");
    return 0;
}

