
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii>i3;
int n,a[1000001];
typedef struct node {
	int val,rl,rr;
	node() {
		val = 0; rl = 0; rr = 0;
	}
	node(int v, int l, int r) {
		val = v; rl = l; rr = r;
	}
}Node;
node ST[4000004];
void readInput(){
	string s; 
	getline(cin, s);
	n = s.length();
	for (int i = 1; i <= n; i++) {
		a[i] = (s[i - 1] == '(') ? 0 : 1;
	}
}
void build(int id,int l,int r) {
	if (l == r) {
		ST[id].val = 0;
		ST[id].rl = 1 - a[l];
		ST[id].rr = a[l];
		
		return;
	}
	int mid = (l + r) / 2;
	build(2 * id, l, mid);
	build(2 * id + 1, mid + 1, r);
	int d = min(ST[2 * id].rl, ST[2 * id + 1].rr);
	ST[id].val = ST[2 * id].val + ST[2 * id + 1].val+ d;
	ST[id].rl = ST[2 * id].rl - d + ST[2 * id + 1].rl;
	ST[id].rr = ST[2 * id + 1].rr - d + ST[2 * id].rr;
}
node cal(int id,int l,int r,int u,int v) {
	if (r<u || l> v) {
		return node(0, 0, 0);
	}
	if (l >= u && r <= v)return ST[id];
	int mid = (l + r) / 2;
	node x= cal(2 * id, l, mid, u, v);
	node y = cal(2 * id + 1, mid + 1, r, u, v);
	int d = min(x.rl, y.rr);
	int val = x.val + y.val + d;
	return node(val, x.rl - d + y.rl, y.rr - d + x.rr);
}
void solve() {
	readInput();
	build(1, 1, n);
	int q; cin >> q;
	for (int i = 0; i < q; i++) {
		int x, y; cin >> x >> y;
		cout << cal(1, 1, n, x, y).val*2<<endl;
	}
}
int main()
{
	//readInput();
	solve();
//	system("pause");
	return 0;
}

