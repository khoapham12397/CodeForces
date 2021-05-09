#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> i3;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef pair<int, vi> node;
int n, a[5001];
node ST[20001];
ll S[5001];
vii vtb;
void build(int id,int l,int r) {
	if (l == r) {
		ST[id].first = vtb[l].first;
		ST[id].second.push_back(l);
		return;
	}
	int mid = (l + r) / 2;
	build(2 * id, l, mid);
	build(2 * id + 1, mid + 1, r);
	if (ST[2 * id].first == ST[2 * id + 1].first) {
		ST[id].first = ST[2 * id].first;
		ST[id].second = ST[2 * id].second;
		vi vt2 = ST[2 * id + 1].second;
		for (int i = 0; i < vt2.size(); i++) ST[id].second.push_back(vt2[i]);
	}
	else {
		int ind;
		if (ST[2 * id].first < ST[2 * id + 1].first) ind = 2 * id;
		else ind = 2 * id + 1;
		ST[id].first = ST[ind].first;
		ST[id].second = ST[ind].second;
	}
	
}
node get(int id, int l, int r, int u, int v) {
	if (l > v || u > r) return node(ll(1e9 + 7), NULL);
	if (l >= u && r <= v) return ST[id];
	int mid = (l + r) / 2,gt;
	node u1 = get(2 * id, l, mid, u, v),u2=get(2*id+1,mid+1,r,u,v);
	vi res;
	if (u1.first == u2.first) {
		gt = u1.first;
		res = u1.second; for (int i = 0; i < u2.second.size(); i++) res.push_back(u2.second[i]);
	}
	else {
		if (u1.first < u2.first) {
			gt = u1.first; res = u1.second;
		}
		else gt = u2.first, res = u2.second;
	}
	return node(gt, res);
}
ll cal(int l, int r, int val) {
	if (l > r) return 0;
	node u = get(1, 1, vtb.size() - 1, l, r);
	vi indMins = u.second;
	int gt = u.first;
	ll ans = S[r] - S[l - 1], res;
	int st = l;
	res = gt - val;
	for (int i = 0; i < indMins.size(); i++) {
		res += cal(st, indMins[i] - 1, gt);
		st = indMins[i] + 1;
	}
	res += cal(st, r, gt);
	return min(ans, res);
}
void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int t = 1;
	vtb.push_back(ii(0, 0));
	for (int i = 2; i <= n; i++) {
		if (a[i] == a[i - 1]) t++;
		else {
			vtb.push_back(ii(a[i - 1], t));
			t = 1;
		}
	}
	vtb.push_back(ii(a[n], t));
	int len = vtb.size() - 1;
	S[0] = 0;
	S[1] = ll(vtb[1].second);
	for (int i = 2; i <= len; i++) {
		S[i] = S[i - 1] + ll(vtb[i].second);
	}
	build(1, 1, len);
	cout << cal(1, len, 0) << endl;
}
int main()
{
	solve();
//	system("pause");
	return 0;
}

