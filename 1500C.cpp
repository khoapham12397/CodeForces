#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <string>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
int n, m,a[1500][1500],b[1500][1500], oab[1500], oba[1500];
bool used[1500];
string sa[1500], sb[1500];
void solve() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		used[i] =false;
		for (int j = 0; j < m; j++) cin >> a[i][j];
	}
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> b[i][j];
	for (int i = 0; i < n; i++) {
		sa[i] = "";
		for (int j = 0; j < m; j++) {
			int x = a[i][j] ,y =b[i][j];
			vi vt;
			while (x > 0) {
				sa[i] += char((x%10) + 48);
				x /= 10;
			}
			sa[i] += ' ';
			while (y > 0) {
				sb[i] += char((y % 10) + 48);
				y /= 10;
			}
			sb[i] += ' ';
		}
	}
	//tu do minh se co duoc 2 cai hoan vi"
	for (int i = 0; i < n; i++) {
		bool ok = false;
		for (int j = 0; j < n; j++) {
			if(used[j]) continue;
			if (sa[i] == sb[j]) {
				oab[i] = j; oba[j] = i; ok = true;
				used[j] = true;
				break;
			}
		}
		if (!ok) { cout << -1 << endl; return; }
	}

	bool sorted = true;
	for (int i = 0; i < n; i++) if (oab[i] != i) { sorted = false; break; }
	if (sorted) { cout << 0 << endl;  return; }
	vi sCol;
	for (int col = 0; col < m; col++) {
		bool ok = true;
		for (int i = 1; i < n; i++) {
			if (b[i][col] < b[i - 1][col]) { ok = false; break; }
		}
		if (ok) sCol.push_back(col);
	}
	
	int st = 0;
	vii rs;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < sCol.size(); j++) {
			int col = sCol[j];
			if (b[i][col] != b[i - 1][col]) {
				if (i - 1 != st) rs.push_back(ii(st, i - 1));
				st = i; break;
			}
		}
	}
	if(st!= n-1) rs.push_back(ii(st, n - 1));
	for (int i = 0; i < rs.size(); i++) {
		int st = rs[i].first, sf = rs[i].second;
		for (int j = st+1; j <= sf; j++) {
			if (oba[j] < oba[j - 1]) {
				cout << -1 << endl;
				return;
			}
		}
	}
	cout << sCol.size() << endl;
	for (int i = 0; i < sCol.size(); i++) cout << sCol[i]+1 << " "; cout << endl;
}
int main()
{
	solve();
//	system("pause");
    return 0;
}

