#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
int n,par[200001];
ull mod = 998244353;
ull fact[200001];
vi adj[200001];

ull cal(int u) {
	ull ans = 1,ch=0;
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (par[u] != v) {
			par[v] = u;
			ch++;
			ans = (ans*cal(v)) % mod;
		}
	}
	if (ch == 0) return ull(1);
	if(u!=1) ans = (ans*fact[ch+1]) % mod;
	else ans = (ans*fact[ch]) % mod;
	return ans;
}

void solve() {
	cin >> n;
	for (int i = 1; i < n; i++) {
		int x, y; cin >> x >> y;
		par[i] = 0;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	fact[0] = fact[1] = ull(1);
	for (int i = 2; i <= n; i++) fact[i] = (fact[i - 1] * i) % mod;
	par[n] = 0;
	
	cout << (cal(1)*ull(n)) % mod << endl;

	
}
int main()
{
	solve();
//	system("pause");
    return 0;
}

