#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n,a[100010],L[100010],R[100010],sl[100010],sr[100010];
int STL[400010], STR[400010];
void buildL(int id,int l,int r) {
	if (l == r) {
		STL[id] = l; return;
	}
	int mid = (l + r) >> 1;
	buildL(2 * id, l, mid);
	buildL(2 * id + 1, mid + 1, r);

	if (sl[STL[2 * id]] <= sl[STL[2 * id + 1]]) STL[id] = STL[2 * id];
	else STL[id] = STL[2 * id + 1];
}
void buildR(int id, int l, int r) {
	if (l == r) {
		STR[id] = l; return;
	}
	int mid = (l + r) >> 1;
	buildR(2 * id, l, mid);
	buildR(2 * id + 1, mid + 1, r);

	if (sr[STR[2 * id]] < sr[STR[2 * id + 1]]) STR[id] = STR[2 * id];
	else STR[id] = STR[2 * id + 1];
}
int getL(int id, int l, int r, int u, int v) {
	if (l > v || r < u) return -1;
	if (l >= u && r <= v) return STL[id];
	int mid = (l + r) >> 1;
	int x = getL(2 * id, l, mid, u, v), y= getL(2*id+1,mid+1,r,u,v);
	if (x == -1) return y;
	if (y == -1) return x;
	if (sl[x] <= sl[y]) return x;
	return y;
}
int getR(int id, int l, int r, int u, int v) {
	if (l > v || r < u) return -1;
	if (l >= u && r <= v) return STR[id];
	int mid = (l + r) >> 1;
	int x = getR(2 * id, l, mid, u, v), y = getR(2 * id + 1, mid + 1, r, u, v);
	if (x == -1) return y;
	if (y == -1) return x;
	if (sr[x] < sr[y]) return x;
	return y;
}
void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	L[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (a[i - 1] > a[i]) L[i] = i;
		else {
			int j = L[i - 1];
			while (j > 1 && a[j - 1] <= a[i]) j = L[j - 1];
			L[i] = j; 
		}
	}
	R[n] = n;
	for (int i = n - 1; i >= 1; i--) {
		if (a[i] < a[i + 1]) R[i] = i;
		else {
			int j = R[i + 1];
			while (j < n && a[j + 1] <= a[i]) j = R[j + 1];
			R[i] = j;
		}
	}
	sl[0] = 0; for (int i = 1; i <= n; i++) sl[i] = sl[i - 1] + a[i];
	sr[n + 1] = 0; for (int i = n; i >= 1; i--) sr[i] = sr[i + 1] + a[i];
	
	buildL(1, 1, n); 
	buildR(1, 1, n);
	int ans = -(1e9);
	for (int i = 1; i <= n; i++) {
		int l = L[i],r=R[i],x=0,y=0;
		
		if (l< i) {
			if(l>1) x = sl[i - 1] - sl[getL(1, 1, n, l - 1, i - 1)];
			else x = max(sl[i - 1], sl[i - 1] - sl[getL(1, 1, n, l, i - 1)]);
		}
		
		if (r>i) {
			if (r < n) {
				int ind = getR(1, 1, n, i + 1, r + 1);
				y = sr[i + 1] - sr[ind];
			}
			else y = max(sr[i + 1], sr[i + 1] - sr[getR(1, 1, n, i + 1, r)]);
		}
		ans = max(ans, x + y);
	
	}
	cout << ans << endl;
}
int main()
{
	solve();
//	system("pause");
    return 0;
}

