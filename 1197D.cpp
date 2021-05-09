#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
ll n,m,k,a[300001];
ll s[300001],b[300001];
ll ST[1400001],inf= ll(1e17);
ll ans =0;
ll build(int id, int l, int r) {
	if (l == r) {
		ST[id] = l;
		return s[l];
	}
	int mid = (l + r) / 2;
	ll u= build(2 * id, l, mid);
	ll v= build(2 * id + 1, mid + 1, r);
	if(u>=v) {
		ST[id] = ST[2 * id]; 
		return s[ST[id]];
	}
	ST[id] = ST[2 * id + 1];
	return s[ST[id]];
}
void cal() {
	for (int i = 1; i <= n; i++) {
		int u = i / m;
		if (i%m != 0) u++;
		b[i] = u*k;
	}
}
int get(int id,int l,int r,int u,int v) {
	if (l > v || r < u) return -1;
	if (l >= u && r <= v) return ST[id];
	int mid = (l + r) >> 1;
	int x = get(2 * id, l, mid,u,v),y=get(2*id+1,mid+1,r,u,v);
	if (x != -1) {
		if (y != -1) {
			if (s[x] >= s[y]) return x;
			return y;
		}
		return x;
	}
	return y;
}
void solve() {
	cin >> n >> m >> k;
	a[0] = 0, s[0] = 0;
	for (int i = 1; i <= n; i++) cin >> a[i], s[i] = s[i - 1] + ll(a[i]);
	cal(); build(1, 1, n);
	for (int i = 1; i <= n; i++) {
		int r = n;
		int ind = get(1, 1, n, i, r);
		ll val = s[ind] - s[i - 1] - b[ind - i + 1];
		r = ind;
		while (r>=i) {
			ind = get(1, 1, n,i, r);
			val = max(val,s[ind] - s[i - 1] - b[ind - i + 1]);
			r = ind-1;
		}
		ans = max(ans, val);
	}
	
	cout << ans << endl;
}
int main()
{
	solve();
//	system("pause");
    return 0;
}

