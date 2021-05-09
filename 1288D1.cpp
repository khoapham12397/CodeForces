#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef pair<int, vi> node;
map<int, vi> th;
int n,m,f[256],pos[256],x1=1,x2=2,ans=-1;
vi a[300001];
vector<node> ds;
bool cal(int id) {
	
	int x = ds[id].first,t=0; 
	vi inds = ds[id].second;
	
	for (int i = 0; i < inds.size(); i++) {
		int ind = inds[i],msk=0;
		for (int j = 0; j < m; j++) {
			if (a[ind][j] < x) msk += (1 << j);
		}
		if (msk == 0) {
			x1 = ind, x2 = ind;
			return 1;
		}
		else {
			if (f[msk] >= x) { x1 = ind; x2 = pos[msk]; return 1; }
		}
	}
	return 0;
}
void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			int x; cin >> x; 
			a[i].push_back(x);
			th[x].push_back(i);
		}
	}
	map<int, vi>::iterator it;
	for (it = th.begin(); it != th.end(); it++) {
		ds.push_back(node(it->first,it->second));
	}
	
	for (int msk = 1; msk < (1 << m); msk++) {
		vi inds;
		for (int j = 0; j < m; j++) if (((msk >> j) % 2) == 1) inds.push_back(j);
		int gtmin = -1,p=1;
		
		for (int i = 1; i <= n; i++) {
			int val = int(1e9)+7;
			for (int j = 0; j < inds.size(); j++) {
				val = min(val, a[i][inds[j]]);
			}
			if (gtmin < val) { p = i; gtmin = val; }
		}

		f[msk] = gtmin; pos[msk] = p;
	}
	
	int l=0,r=ds.size()-1;
	while (l <= r) {
		int mid = (l + r) / 2;

		if (cal(mid)) {
			ans = ds[mid].first;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	if (x1 >= x2) cout << x2 << " " << x1 << endl;
	else cout << x1 << " " << x2 << endl;
}
int main()
{
	solve();
	//	system("pause");
    return 0;
}

