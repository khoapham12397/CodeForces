#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
int n,h[300010],L[300010],R[300010];
ll inf = ll(1e18);
ll a[300010],dp[300010];
ll ST[1200010];
void build(int id, int l,int r) {
	if (l == r) {
		ST[id] = l; return;
	}
	int mid = (l + r) >> 1;
	build(2 * id, l, mid);
	build(2 * id + 1, mid + 1, r);
	ST[id] = ST[2 * id];
}

int get(int id, int l, int r, int u, int v) {
	if (u > r || v < l) return -1;
	if (l >= u && r <= v) return ST[id];
	int mid = (l + r) >> 1;
	int ind1 = get(2 * id, l, mid, u, v), ind2 = get(2 * id+1, mid+1,r, u, v);
	if (ind1 == -1) return ind2;
	if (ind2 == -1) return ind1;
	if (dp[ind1] > dp[ind2]) return ind1;
	return ind2;
}
void update(int id, int l, int r, int ind) {
	if (ind < l || ind >r) return;
	if (dp[ST[id]] < dp[ind]) {
		ST[id] = ind;
	}
	if(l<r){
		int mid = (l + r) >> 1;
		update(2 * id, l, mid, ind);
		update(2 * id + 1, mid + 1, r, ind);
	}
}// ban dau cho la 0"
void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> h[i];
	for (int i = 1; i <= n; i++) cin >> a[i];
	L[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (h[i] > h[i - 1]) L[i] = i;
		else {
			int j = L[i - 1];
			while (j > 1 && h[i] < h[j-1]) j = L[j - 1];
			L[i] = j;
		}
	}
	R[n] = n;
	for (int i = n - 1; i >= 1; i--) {
		if (h[i] > h[i + 1]) R[i] = i;
		else {
			int j = R[i + 1];
			while (j < n && h[i] < h[j + 1]) j = R[j + 1];
			R[i] = j;
		}
	}
	ll l = 0, r = 0,ans=-inf;
	for (int i = 2; i <= n; i++) l += ll(L[i]);
	for (int i = 1; i <= n; i++) dp[i] = -inf;
	build(1, 1, n);
	for (int i = n - 1; i >= 1; i--) r += ll(R[i]);
	if (l < r) {
		dp[0] = 0;
		dp[1] = a[1]; update(1, 1, n, 1);
		for (int i = 2; i <= n; i++) {
			int j = L[i];
			if (j == i) {
				dp[i] = max(dp[i - 1], dp[i - 1] + a[i]);
				update(1, 1, n, i);
				continue;
			}
			int ind = get(1, 1, n, j, i - 1);
			
			ll val = max(dp[j - 1], dp[ind]) + a[i];
			if (j > 1) val = max(val, dp[j - 1]);
			
			dp[i] = val;
			update(1, 1, n, i);
		}
		cout << dp[n] << endl;
	}
	else {
		dp[n + 1] = 0; dp[n] = a[n];
		update(1, 1, n, n);
		for (int i = n - 1; i >= 1; i--) {
			int j = R[i];
			if (j == i) {
				dp[i] = max(dp[j + 1], dp[j + 1] + ll(a[i]));
				update(1, 1, n, i);
				continue;
			}
			int ind = get(1, 1, n, i+1,j);
			ll val = max(dp[ind],dp[j+1]) +a[i];
			if (j < n) val = max(val, dp[j + 1]);
			dp[i] = val;
			update(1, 1, n, i);
		}
		cout << dp[1] << endl;
	}

}
int main()
{
	solve();
//	system("pause");
    return 0;
}

