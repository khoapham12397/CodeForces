#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
int n,s[300010], f[300010],s0[300010],s1[300010];
int ST[1200010];
ll a[300010];
void build(int id,int l,int r) {
	if (l == r) {
		ST[id] = l;
		return;
	}
	int mid = (l + r) >> 1;
	build(2 * id, l, mid);
	build(2 * id + 1, mid + 1, r);
	if (f[ST[2 * id]] > f[ST[2 * id + 1]]) ST[id] = ST[2 * id];
	else ST[id] = ST[2 * id + 1];
}
int get(int id,int l,int r,int u,int v) {
	if (l > v || r < u) return -1;
	if (l >= u && r <= v) return ST[id];
	int mid = (l + r) >> 1;
	int x = get(2 * id, l, mid, u, v), y = get(2 * id + 1, mid + 1, r, u, v);
	if (x == -1) return y;
	if (y == -1) return x;
	if (f[x] > f[y]) return x;
	return y;
}
int BSearch(int val,int l,int r) {
	if (l == r) {
		if (s[l] <= val) return l;
		return l - 1;
	}
	int mid = (l + r) >> 1;
	if (s[mid] == val) return mid;
	if (s[mid] > val) {
		if (mid > l) return BSearch(val, l, mid - 1);
		return l - 1;
	}
	return BSearch(val, mid + 1, r);
}
void solve() {
	cin >> n;
	
	for (int i = 1; i <= n; i++) cin >> a[i];
	s[0]  = s1[0] = 0;
	s0[0] = 1;
	for (int i = 1; i <= n; i++) {
		ll x = a[i];
		int t = 0;
		while (x > 0) {
			if (x % 2 == 1) t++;
			x >>= 1;
		}
		f[i] = t;
		s[i] = s[i - 1] + t;
		s0[i] = s0[i - 1] + ((s[i] % 2)==0);
		s1[i] = s1[i - 1] + ((s[i] % 2) == 1);
	}
	build(1, 1, n);
	ll ans = 0;
	for (int i = 2; i <= n; i++) {
		int l = 0;
		while (l < i) {
			int ind = get(1, 1, n, l+1, i);
			
			int val = s[i] - 2 * f[ind];
			if (val < 0) {
				l = ind; 
				continue;
			}
		
			int id1 = BSearch(val, l, ind - 1);
			if (id1 >= l) {
				if (s[i] % 2 == 0) {
					if (l == 0) ans += ll(s0[id1]);
					else ans += ll(s0[id1]) - ll(s0[l - 1]);
				}
				else{
					if(l==0) ans += ll(s1[id1]);
					else ans += ll(s1[id1] -s1[l-1]);
				}
			}
			
			l = ind;
		}
	}
	cout << ans << endl;
}
int main()
{
	solve();
//	system("pause");
    return 0;
}

