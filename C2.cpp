
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;
typedef vector<int> vi;
typedef pair<int, vi> ivi;
typedef pair<int, int> ii;
int n,a[2000],F[128][8],k,b[128];
int dp[2000][14001];
map<ii, vi> V;
vi vt1,vt0;
void readInput() {
	cin >> n >> k;
	cin.ignore();
	for (int i = 0; i < n; i++) {
		string s;
		getline(cin, s);
		int val = 0;
		for (int j = 0; j <7; j++) {
			val += (1 << (6 - j)) *(int(s[j]) - 48);

		}
		a[i] = val;
		//cout << a[i] << " ";
	}
	cout << endl;
}
vi getMax(vi vt1, vi vt2) {
	for (int i = 0; i < vt1.size(); i++) {
		if (vt1[i] > vt2[i]) return vt1;
		if (vt1[i] < vt2[i]) return vt2;
	}
	return vt1;
}
void cal() {
	for (int i = 0; i < n; i++) for (int j = 0; j <= 7 * n; j++) dp[i][j] = 0;
	int a0 = a[0];
	int gt1=-1,cs;

	for (int i = 0; i <= 7; i++) {
		if (F[a0][i] != -1) {
			dp[0][i] = 1;
			vi vt; vt.push_back(F[a0][i]);
			V[ii(0, i)] = vt;
		}
		
	}
	
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <=min( 7 * (i + 1),k); j++) {
			

			for (int x = 0; x <= min(7,j); x++) {
				
				if (F[a[i]][x] != -1 && dp[i-1][j-x]==1 ) {
					
					vt1 = V[ii(i - 1, j - x)];
					vt1.push_back(F[a[i]][x]);
					dp[i][j] = 1;
					if(vt0.size()==0) vt0=vt1;
					else vt0 = getMax(vt0, vt1);
				}
			}
			
			if (dp[i][j] == 1) V[ii(i,j)]= vt0;
			vt0.clear();		
		}
	}
	
}
void solve() {
	for (int i = 0; i < 128; i++) b[i] = -1;
	b[119] = 0; b[18] = 1; b[93] = 2; b[91] = 3; b[58] = 4; b[107] = 5; b[111] = 6; b[82] = 7; b[127] = 8;
	b[123] = 9;
	for (int i = 0; i < 128; i++) for (int j = 0; j < 8; j++) F[i][j] = -1;
	for (int i = 0; i < 128; i++) F[i][0] = b[i];
	for (int i = 0; i < 128; i++) {
		//tinh F[i][j]
		F[i][0] = b[i];
		int s0 = 0;
		vi vt0;
		for (int x = 0; x < 7; x++) {
			if ((i >> x) % 2 == 1) {
				s0++;
				vt0.push_back(x);
			}
		}
		for (int st = 0; st < 128; st++) {
			int ok = 1,s1=0;
			for (int t = 0; t < 7; t++) {
				if ((st >> t) % 2 == 1) s1++;
			}
			for (int j = 0; j < vt0.size(); j++) {
				int x = vt0[j];
				if ((st >> x) % 2 == 0) {
					ok = 0; break;
				}
			}
			if (ok) {
				F[i][s1 - s0] = max(F[i][s1 - s0],b[st]);
				
			}
		}
	}

	cal();
	
	if (dp[n - 1][k]) {
		vi vt = V[ii(n - 1, k)];
		for (int i = 0; i < vt.size(); i++) cout << vt[i];
		cout << endl;
	}
	else cout << -1<<endl;
}


int main()
{
	readInput();
	solve();
//	system("pause");
	return 0;
}

