#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
int n, m, a[100010], b[100010], c[100010], d[100010];
vector<vi> ts;
vi tm, inds;

void solve() {
	cin >> n >> m;
	int sl = 0;
	ts.assign(n + 1, vi());
	tm.assign(n + 1, 0);
	inds.assign(n + 1, 0);
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
		if (a[i] != b[i]) ts[b[i]].push_back(i), sl++;
		tm[b[i]] = i;
	}

	int k = 0, inc = 0;

	for (int i = 1; i <= m; i++) cin >> c[i];
	int x = c[m];
	if (ts[x].size()>0) {
		d[m] = ts[x][inds[x]];
		inds[x]++; inc = d[m]; k++;
	}
	else {
		if (tm[x] != 0) d[m] = tm[x],inc= tm[x];
		else { cout << "NO" << endl; return; }
	}
	for (int i = m - 1; i >= 1; i--) {
		int x = c[i];
		if (ts[x].size() > 0 && inds[x]< ts[x].size()) {
			d[i] = ts[x][inds[x]];
			inds[x]++; k++;
		}
		else {
			if (tm[x] != 0) d[i] = tm[x];
			else {
				if (inc != 0) d[i] = inc;
				else { cout << "NO" << endl; return; }
			}
		}
	}
	if (k < sl) { cout << "NO" << endl; return; }
	cout << "YES" << endl;
	for (int i = 1; i <= m; i++) cout << d[i] << " "; 
	cout << endl;
	
}
int main()
{
	int T; cin >> T;
	for (int i = 0; i<T; i++) solve();
//	system("pause");
	return 0;
}

