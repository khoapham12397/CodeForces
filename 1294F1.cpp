#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> i3;

ii fs[200010];
i3 fd[200010];
bool isLeaf[200010] = {false};
int n,par[200010], ans = 0 ,a=-1,b=-1,c=-1;
vi adj[200010];
void duyet(int u) {
	
	if (isLeaf[u]) {
		fs[u] = ii(0, u);
		fd[u] = i3(-1, ii(-1, -1));
		return;
	}
	
	int sa1=-1,da1=-1 , vs1=-1 ,vd1=-1,vd2=-1,sa2=-1,vs2=-1,vd3=-1,vd4=-1, da2=-1 ,sa3=-1,vs3=-1; 
	int bs1=-1, bs2=-1,bs3=-1 ,bd1=-1, bd2=-1;
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (par[u] != v) {
		
			par[v] = u;
			duyet(v);
		
			if (sa1 < fs[v].first +1 ) {
				if (sa1 != -1) {
					if (sa2 != -1) sa3 = sa2, vs3 = vs2, bs3 = bs2;
					sa2 = sa1; vs2 = vs1; bs2 = bs1;
				}
				sa1 = fs[v].first+1; vs1 = fs[v].second;
				bs1 = v;
			}
			else {
				if (sa2 < fs[v].first + 1) {
					if (sa2 != -1) sa3 = sa2, vs3 = vs2, bs3 = bs2;
					sa2 = fs[v].first + 1, vs2 = fs[v].second, bs2 = v;
				}
				else if (sa3 < fs[v].first + 1) sa3 = fs[v].first + 1, vs3 = fs[v].second,bs3=v;
			}
			if (fd[v].first != -1) {
				if (da1 < fd[v].first+1) {
					if (da1 != -1) {
						da2 = da1; vd3 = vd1; vd4 = vd2; bd2 = bd1;
					}
					da1 = fd[v].first+1;
					vd1 = fd[v].second.first; vd2 = fd[v].second.second;
					bd1 = v;
				}
				else if (da2 < fd[v].first + 1) {
					bd2 = v;
					da2 = fd[v].first + 1;
					vd3 = fd[v].second.first; vd4 = fd[v].second.second; 
				}
			}
			
		}
	}
	// 
	fs[u] = ii(sa1,vs1);
	if (da1 != -1) {
		if (sa2 != -1) {
			if (da1 < sa1 + sa2) {
				fd[u] = i3(sa1 + sa2, ii(vs1, vs2));
			}
			else fd[u] = i3(da1, ii(vd1, vd2));
		}else fd[u] = i3(da1, ii(vd1, vd2));
	}
	else {
		if (sa2 != -1)  fd[u] = i3(sa1 + sa2, ii(vs1, vs2));
		else fd[u] = i3(-1, ii(-1, -1));
	}
	int val = -1,ta=-1,tb=-1,tc=-1;
	
	
	if (sa3 != -1 && sa2 != -1) {
		val = sa1 + sa2 + sa3;
		ta = vs1, tb = vs2, tc = vs3;
	}
	if (bd1 != -1) {
		if (bd1 != bs1) {
			int gt = da1 + sa1;
			if (gt > val) {
				val = gt;
				ta = vs1, tb = vd1, tc = vd2;
			}
		}
		else {
			if (sa2 != -1) {
				int gt = da1 + sa2;
				if (gt > val) {
					val = gt; ta = vs2, tb = vd1, tc = vd2;
				}
			}
		}
		if (bd2 != -1) {
			if (bd2 != bs1) {
				int gt = da2 + sa1;
				if (gt > val) {
					val = gt; 
					ta = vs1, tb = vd3, tc = vd4;
				}
			}
		}
	}
	
	if (ans < val) {
		ans = val; a = ta, b = tb, c = tc;
	}
	
}
void solve() {
	cin >> n;
	for (int i = 1; i < n; i++) {
		par[i] = 0;
		int x, y; cin >> x >> y;
		adj[x].push_back(y); adj[y].push_back(x);
	}
	vi leafs;
	int root = 0;
	for (int i = n; i >= 1; i--) {
		if (adj[i].size() == 1) leafs.push_back(i), isLeaf[i] = true;
		else root = i;
	}

	if (leafs.size() == 2) {
		cout << n - 1 << endl;
		cout << leafs[0] << " " << leafs[1] << " " << root << endl;
		return;
	}
	duyet(root);
	cout << ans << endl;
	cout << a << " " << b << " " << c << endl;
}
int main()
{
	solve();
//	system("pause");
    return 0;
}

