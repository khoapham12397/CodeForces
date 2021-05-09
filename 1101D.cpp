#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
using namespace std;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<int> vi;
bitset<200010> bs;
vi primes;
void sieve(ll up) {
	bs.set(); bs[0] = bs[1] = 0;
	for(ll  i= 2;i<=up;i++){
		if (bs[i]) {
			for (ll j = i*i; j <= up; j += i) bs[j] = 0;
			primes.push_back(i);
		}
	}
}

int n,par[200010],a[200010],ans=0;
vi adj[200010];
vector<ii> ds[2000010];
void duyet(int u) {
	int x = a[u];
	if (x == 1) return;
	for (int i = 0; primes[i]*primes[i] <= x; i++) {
		int  p = primes[i];
		if (x % p == 0) {
			while (x%p == 0) x /= p;
			ds[u].push_back(ii(p,0));
		}
	}
	if (x > 1) ds[u].push_back(ii(x, 0));
	vi ds2; ds2.assign(ds[u].size(), 0);
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (par[u] != v) {
			par[v] = u;
			duyet(v);
			for (int i = 0; i < ds[u].size(); i++) {
				for (int j = 0; j < ds[v].size(); j++) {
					if (ds[u][i].first == ds[v][j].first) {
						if (ds[u][i].second < ds[v][j].second) ds2[i] = ds[u][i].second, ds[u][i].second = ds[v][j].second;
						else if (ds2[i] < ds[v][j].second) ds2[i] = ds[v][j].second;
					}
				}
			}
		}
	}
	
	for (int i = 0; i < ds[u].size(); i++) {
		ans = max(ans, ds[u][i].second + ds2[i] + 1);
		ds[u][i].second++;
	}
}
void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i < n; i++) {
		int x, y; cin >> x >> y;
		adj[x].push_back(y); adj[y].push_back(x);
	}
	duyet(1);
	
	cout << ans << endl;
}
int main()
{
	sieve(200000);
	solve();
//	system("pause");
	return 0;
}

