#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int n;
map<ii, bool> ms;
vii a[510],edges;
vi f[510],vals;
int rel[510][510];

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int x; cin >> x; a[i].push_back(ii(x,j));
		}
	}
	for (int i = 1; i <= n; i++) sort(a[i].begin(), a[i].end());
	
	vals.push_back(0);
	for (int i = 1; i <= n; i++) vals.push_back(a[i][0].first);
	int s = n + 1;
	for (int i = 1; i <= n; i++) {
		int level = 0;
		rel[i][i] = 0;
		for (int j = 1; j < a[i].size(); j++) {
			int val = a[i][j].first, v= a[i][j].second;
			if (val != a[i][j - 1].first) {
				level++;
			}
			rel[i][v] = level;
		}
	}
	
	for (int i = 1; i <= n; i++) {
		f[i].push_back(i);

		for (int j = 1; j < a[i].size(); j++) {
			int v = a[i][j].second ,val = a[i][j].first; 
			
			if (v < i) {
				int lv = rel[v][i]; 
				f[i].push_back(f[v][lv]);
				edges.push_back(ii(f[i][f[i].size() - 2], f[i][f[i].size() - 1]));
				for (int j1 = lv+1; j1 < f[v].size(); j1++) {
					f[i].push_back(f[v][j1]);
				}
				break;
			}
			else {
				if(val!= a[i][j-1].first){
					f[i].push_back(s); vals.push_back(val);
					s++;
					edges.push_back(ii(f[i][f[i].size() - 2], f[i][f[i].size() - 1]));
				}
			}
		}
	}

	
	
	cout << s - 1 << endl;
	for (int i = 1; i < s; i++) cout << vals[i] << " "; cout << endl;
	cout << f[1][f[1].size()-1] << endl;
	for (int i = 0; i < edges.size(); i++) cout << edges[i].first << " " << edges[i].second << endl;

}
int main()
{
	solve();
//	system("pause");
    return 0;
}

