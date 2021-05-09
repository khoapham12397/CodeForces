#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef unsigned long long ull;
typedef pair<int, int> ii;
int n, m, R, Sl[1001][1001], a[1001][1001],P[2001];
ii pos[2001];
ull ans = 0;
ull F[2001],C[2001][2001];
ull mod = 1000000007,b[2001];
void solve() {
	cin >> n >> m >> R;
	for (int i = 0; i <= 1000; i++) for (int j = 0; j <= 1000; j++) a[i][j] = Sl[i][j]= 0;
	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y >> b[i+1];
		pos[i + 1].first = x,pos[i+1].second=y;
		a[x][y] = 1;
	}
	for (int i = 0; i <= n; i++) C[0][i] = C[i][i] = 1;
	for (int i = 2; i <= n; i++) {
		C[1][i] = i%mod;
		for (int j = 2; j < i; j++) C[j][i] = (C[j][i - 1] + C[j - 1][i - 1]) % mod;
	}
	Sl[1][1] = a[1][1];
	for (int i = 2; i <= 1000; i++) {
		Sl[i][1] = Sl[i - 1][1]+a[i][1];
		Sl[1][i] = Sl[1][i - 1]+a[1][i];
	}
	
	for (int i = 2; i <= 1000; i++) {
		for (int j = 2; j <= 1000; j++) {
			Sl[i][j] = Sl[i][j - 1] + Sl[i - 1][j] - Sl[i-1][j - 1] + a[i][j];

		}
	}
	
	for (int i = 1; i <= n; i++) {
		int l1 = max(pos[i].second - R, 1), r1 = min(pos[i].second + R, 1000), t1 = max(1, pos[i].first - R), d1 = min(1000, pos[i].first + R);
		int x = Sl[d1][r1] - Sl[d1][l1 - 1] - Sl[t1 - 1][r1] + Sl[t1 - 1][l1 - 1];
		P[i] = x;
		ull val=0; if (n-x >= m) val = C[m][n-x];
		F[i] = val;

		ans = (ans + ((mod+C[m][n]- val)%mod * (b[i]*b[i])%mod)%mod) % mod;
	}

	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j <= n; j++) {
			int trung = 0,lm,rm,tm,dm;
			int l1 = max(pos[i].second - R, 1),r1=min(pos[i].second+R,1000),t1=max(1,pos[i].first-R),d1=min(1000,pos[i].first+R);
			int l2 = max(pos[j].second - R, 1), r2 = min(pos[j].second + R, 1000), t2 = max(1, pos[j].first - R), d2 = min(1000, pos[j].first + R);
			
			if (r1<l2 || l1>r2 || d1 < t2 || d2 < t1) trung = 0;
			else {
				lm = max(l1, l2); rm = min(r1, r2); tm = max(t1, t2); dm = min(d1, d2);
				trung = Sl[dm][rm] - Sl[dm][lm - 1] - Sl[tm - 1][rm] + Sl[tm - 1][lm - 1];
				
			}
			
			int kgc = n - P[i] - P[j] + trung;
			ull st = 0,val=0;
			if (kgc >= m) st = C[m][kgc];
			val = (F[i] + F[j] - st)%mod;
			ans = (ans + ((mod + C[m][n] - val) % mod)*(2 * b[i] * b[j]) % mod) % mod;
		}
	}
	cout << ans << endl;
}

int main()
{
	solve();
	//system("pause");
	return 0;
}

