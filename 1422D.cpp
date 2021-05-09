#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair < ii, int> i3;
typedef vector<int> vi;
typedef vector<ii> vii;

int n,m,ordx[100010],ordy[100010],d[100010],f[100010],sx,sy,fx,fy;
vector<i3> ax,ay;
void solve() {
	cin >> n >> m;
	ax.assign(m,i3(ii(),0));
	ay.assign(m, i3(ii(), 0));
	cin >> sx >> sy >> fx >> fy;
	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		f[i] = abs(fx - x)+ abs(fy - y);
		d[i] = min(abs(sx-x), abs(sy-y));
		ax[i]=i3(ii(x, y), i);
		ay[i]=i3(ii(y, x), i);
	}
	
	sort(ax.begin(), ax.end());
	for (int i = 0; i < m; i++) ordx[ax[i].second] = i;
	sort(ay.begin(), ay.end());
	for (int i = 0; i < m; i++) ordy[ay[i].second] = i;
	priority_queue<ii, vii, greater<ii>> q;
	for (int i = 0; i < m; i++) q.push(ii(d[i], i));
	int ans = abs(sx - fx) + abs(sy - fy);
	while (!q.empty()) {
		ii front = q.top(); q.pop();
		int u = front.second;
		if(front.first > ans ) break;
		if (front.first != d[u] ) continue;

		int tx = ordx[u] , ty= ordy[u];
		int ind = tx - 1, gh = max(0,tx-2000);
		while (ind >= gh) {
			int v = ax[ind].second;
		
			int del = abs(ax[ind].first.first - ax[tx].first.first);
			int val = d[u] + del;
			if (d[v] > val  && val<=ans) {
				d[v] = val;
				ans = min(ans,val + f[v]);
				q.push(ii(d[v], v));
			}
			if(val > ans ) break;
			ind--;
		}
		ind = tx + 1; gh = min(tx+2000,m-1);
		while (ind <= gh) {
			int v = ax[ind].second;
			int del = abs(ax[ind].first.first - ax[tx].first.first);
			int val = d[u] + del;
			if (d[v] > val && val<=ans) {
				d[v] = val;
				ans = min(ans, val + f[v]);
				q.push(ii(d[v], v));
			}
			if(val > ans ) break;
			ind++;
		}
		ind = ty - 1; gh = max(0,ty-2000);
		while (ind >= gh ) {
			int v = ay[ind].second;
			int del = abs(ay[ind].first.first - ay[ty].first.first);
			int val = d[u] + del;
			if (d[v] > val && val<=ans) {
				d[v] = val;
				ans = min(ans, val + f[v]);
				q.push(ii(d[v], v));
			}
			if(val > ans ) break;
			ind--;
		}
		

		ind = ty + 1;  gh = min(m-1,ty+2000);
		while (ind <=gh) {
			int v = ay[ind].second;
			int del = abs(ay[ind].first.first - ay[ty].first.first);
			int val = d[u] + del;
			if (d[v] > val && val<=ans) {
				d[v] = val;
				ans = min(ans, val + f[v]);
				q.push(ii(d[v], v));
			}
			if(val > ans ) break;
			ind++;
		}
	}

	for (int i = 0; i < m; i++) ans = min(ans, d[i] + f[i]);
	cout << ans << endl;
}
int main()
{
	solve();
//	system("pause");
	return 0;
}

