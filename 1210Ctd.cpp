#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
int n,par[100001];
vector<int> adj[100001];
ll a[100001],ans=0,mod=1000000007;
ll gcd(ll x, ll y) {
	if (y == 0) return x;
	return gcd(y, x%y);
}

void cal2(int u,map<ll,int> frep) {
	map<ll, int> frev;
	map<ll, int>::iterator it;
	ans = (ans + a[u]) % mod;
	if (u == 1) {
		frev[a[u]] = 1;
	}
	else {
		for (it = frep.begin(); it != frep.end(); it++) {
			ll x = it->first, sl = it->second;
			ll d;
			if (a[u] > x) d = gcd(a[u], x);
			else d = gcd(x, a[u]);
			ans = (ans + (d*sl) % mod) % mod;
			frev[d] += sl;
		}
		frev[a[u]]++;
	}
	
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (par[u] != v) {
			par[v] = u;
			cal2(v, frev);
		}
	}
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
	map<ll, int> f;
	cal2(1,f);
	cout << ans << endl;
}
int main()
{
	solve();
//	system("pause");

    return 0;
}

