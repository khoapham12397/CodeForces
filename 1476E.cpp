#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
int m, n, k, p27[5],a[100010],visited[100010],tt,ord[100010];
vi gts[100010],ado[100010];

vector<ii> vtb;
string s[100010],p[100010];
int BSearch(int val, int l, int r) {
	if (l == r) {
		if (val == vtb[l].first) return vtb[l].second;
		return -1;
	}
	int mid = (l + r) >> 1;
	if (val == vtb[mid].first) return vtb[mid].second;
	if (vtb[mid].first > val) {
		if (l < mid) return BSearch(val, l, mid - 1);
		return -1;
	}
	return BSearch(val, mid + 1, r);
}
bool duyet(int u) {
	visited[u] = 1;
	for (int i = 0; i < ado[u].size(); i++) {
		int v = ado[u][i];
	
		if (visited[v] == 1) return false;
		if (visited[v] == -1) if(!duyet(v)) return false;
		
	}
	ord[tt] = u+1; tt--;
	visited[u] = 0;
	return true;
}
void solve() {
	cin >> n >> m >> k;
	tt = n-1;
	p27[0] = 1;
	for (int i = 1; i < 5; i++) p27[i] = 27 * p27[i - 1];
	for (int i = 0; i < n; i++) cin >> p[i],visited[i]=-1;
	for (int i = 0; i < m; i++) cin >> s[i] >> a[i];
	vtb.assign(n, ii(0,0));
	
	for (int i = 0; i < n; i++) {
		int val = 0;
		for (int j = 0; j < k; j++) {
			if (p[i][j] != '_') val += p27[j] * (int(p[i][j]) - 96);
		}
		vtb[i] = ii(val,i);
	}
	
	sort(vtb.begin(), vtb.end());
	
	for (int i = 0; i < m; i++) {
		for (int msk = 0; msk < (1 << k); msk++) {
			int val=0;
			for (int j = 0; j < k; j++) {
				if ((msk >> j) % 2 == 1) val += p27[j] * (int(s[i][j]) - 96);
			}
			int id= BSearch(val, 0, vtb.size() - 1);
			if (id != -1) gts[i].push_back(id);
		}
	}
	
	for (int i = 0; i < m; i++) {
		bool ok = false; int x = a[i] - 1;
		for (int j = 0; j < gts[i].size(); j++) {
			int v = gts[i][j];
			if (v == x) { ok = true;}
			else ado[x].push_back(v);
		}
		if (!ok) { cout << "NO" << endl; return; }
	}

	for (int i = 0; i < n; i++) {
		if (visited[i] == -1) {
			if (!duyet(i)) { cout << "NO" << endl; return; }
		}
	}
	
	cout << "YES" << endl;
	for (int i = 0; i < n; i++) cout << ord[i] << " ";
	cout << endl;
}
int main()
{
	solve();
//	system("pause");
    return 0;
}

