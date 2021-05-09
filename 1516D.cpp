#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
bitset<100010> bs;
int n,a[100010], P[100010][20],q, pos[100010] , par[100010],h[100010];
vi primes;
void sieve(ll up) {
	bs.set(); bs[0] = bs[1] = 0;
	for (ll i = 2; i <= up; i++) {
		if (bs[i]) {
			for (ll j = i*i; j <= up; j += i) bs[j] = 0;
			primes.push_back(i);
		}
	}
}
void solve() {
	sieve(100000);
	cin >> n >> q;
	
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 0; i < 18; i++) {
		P[0][i] = 0;
	}
	par[0] = 0; h[0] = 0;
	for (int i = 1; i <= n; i++) {
		int x = a[i];
		int gtmax = 0;
		for (int j = 0; j < primes.size(); j++) {
			int p = primes[j];
			if (x%p == 0) {
				while (x%p == 0) x /= p;
				gtmax = max(gtmax, pos[p]);
				pos[p] = i;
			}
			if (x < p*p) break;
		}
		if (x > 1) gtmax = max(gtmax, pos[x]), pos[x] = i;
	
		par[i]=max(par[i - 1], gtmax);
		P[i][0] = par[i];
		
		for (int k = 1; k < 18; k++) {
			P[i][k] = P[P[i][k - 1]][k - 1];
		}
		h[i] = h[par[i]] + 1;

	}

	for (int i = 0; i < q; i++) {
		int l, r; cin >> l >> r;
		int u = l - 1,x= r;
		bool br = 0;
		while (1) {
			for (int j = 17; j >= 0; j--) {
				if (P[x][j] == u) {
					x = u, br = 1; break;
				}
				if (P[x][j] > u) { x = P[x][j];  break; }
				if (j == 0) br = 1;
			}
			if (br) break;
		}
		if (x == u) {
			cout << h[r] - h[u]<<endl;
		}
		else cout << h[r] - h[x] + 1 << endl;
	}
}
int main()
{
	solve();
//	system("pause");
    return 0;
}

