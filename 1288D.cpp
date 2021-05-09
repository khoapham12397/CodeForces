#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ii, int> i3;
typedef vector<ii> vii;
typedef pair<int, vi> node;
map<int, vi> th;
int n,m,f[256],pos[256],x1=1,x2=2,ans=-1;
vi a[300001];
vii b[300001];

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		map<int, vi> mm;
		for (int j = 0; j < m; j++) {
			int x; cin >> x; 
			a[i].push_back(x);
			mm[x].push_back(j);
		}
		map<int, vi>::iterator it;
		int msk = 0;
		for (it = mm.begin(); it != mm.end(); it++) {
			vi vt = it->second;
			b[i].push_back(ii(it->first, msk));
			for (int j = 0; j < vt.size(); j++) msk+= (1<<vt[j]);
		}
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
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < b[i].size(); j++) {
			int x = b[i][j].first, msk = b[i][j].second;
			if (ans >= x) continue;
			if (msk == 0) {
				ans = x; x1=x2 =i;
			
			}
			else {
				if (f[msk] >= x) { ans = x; x1 = i; x2 = pos[msk]; }
			}
		}
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

