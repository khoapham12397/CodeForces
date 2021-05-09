
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> ii;
typedef pair<ii, int> i3;
const int inf = 1e9;
int n,q;
int a[50005];
ii ST[200005];
vector<i3> qs;
void readInput() {
	cin >> n;
	for (int i = 1; i <= n; i++) a[i] = 0;
}
void down(int id) {
	int v = ST[id].second;
	ST[2 * id].first += v;
	ST[2 * id].second += v;
	ST[2 * id + 1].first += v;
	ST[2 * id + 1].second += v;
	ST[id].second = 0;
}
void update(int id,int l,int r,int u,int v,int val) {
	if (l > v || r < u) return;
	if (l >= u && r <= v) {
		//hoan toan ben trong nay luon:
		ST[id].second += val;
		ST[id].first += val;
		return;
	}
	//hoan toan chinh xac :
	int mid = (l + r) / 2;
	down(id);
	update(2 * id, l, mid, u, v, val);
	update(2 * id + 1, mid + 1, r, u, v, val);
	ST[id].first = max(ST[2 * id].first, ST[2 * id+1].first);
}
int get(int id,int l,int r,int u,int v) {
	if (l > v || r < u) return -inf;
	if (l >= u && r <= v) {
		
		return ST[id].first;
	}
	int mid = (l + r) / 2;
	down(id);
	return max(get(2 * id, l, mid, u, v), get(2 * id + 1, mid + 1, r, u, v));
}
void build(int id, int l, int r) {
	if (l == r) {
		ST[id].first = a[l];
		ST[id].second = 0;
		return;
	}
	int mid = (l + r) / 2;
	build(2 * id, l, mid);
	build(2 * id + 1, mid + 1, r);
	ST[id].first = max(ST[2 * id].first, ST[2 * id + 1].first);
	ST[id].second = 0;
}
void solve() {
	build(1,1,n);
	cin >> q;
	for (int i = 0; i < q; i++) {
		int c, l, r;
		cin >> c>>l>>r;
		if (c == 0) {
			int v;
			cin >>v;
			update(1, 1, n, l, r, v);
		}
		else {
			cout << get(1, 1, n, l, r) << endl;
		}
	}
}
int main()
{
	readInput();
	solve();
//	system("pause");
	return 0;
}

