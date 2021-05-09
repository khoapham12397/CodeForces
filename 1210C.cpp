#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <map>
using namespace std;
bitset<1000100>bs;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
int n,par[100001],nc[100001];
vector<ll> primes;
vector<li> info[100001];
vector<int> adj[100001];
ll a[100001],ans=0,mod=1000000007;
ll gcd(ll x, ll y) {
	if (y == 0) return x;
	return gcd(y, x%y);
}
map<ll,int> cal(int u) {
	ans = (ans + a[u]) % mod;
	int t = 0;
	map<ll, int> freu;
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (v != par[u]) {
			t++;
			par[v] = u;
			ll d; 
			if (a[u] > a[v]) d = gcd(a[u], a[v]);
			else d = gcd(a[v], a[u]);
			ans = (ans + d) % mod;
			freu[d]++;
			map<ll,int> frev= cal(v);
			nc[u] += (nc[v]+1);
			if (d == 1) {
				ans = (ans + nc[v]) % mod;
				freu[1] += nc[v];
				continue;
			}
			map<ll, int>::iterator it;
			for (it = frev.begin(); it != frev.end(); it++) {
				ll x = it->first,y;
				int sl = it->second;
				if (x > d) y = gcd(x, d);
				else y = gcd(d,x);
				freu[y] +=sl;
				ans = (ans + y*sl) % mod;
			}
		}
	}

	if (t == 0) {
		nc[u] = 0;
		return freu;
	}
	return freu;
}
void solve() {
	cin >> n;
	for (int i =1; i <= n; i++) cin >> a[i];
	for (int i = 1; i < n; i++) {
		par[i] = 0;
		int x, y; cin >> x >> y;
		adj[x].push_back(y); adj[y].push_back(x);
	}
	par[n] = 0;
	cal(1);
	cout << ans << endl;
}
int main()
{
	solve();

    return 0;
}

