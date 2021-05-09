#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<li> vli;
int n;
ii a[200010];
ll d[200010],f[200010];
ll inf = ll(1e18),mod = ll(1e9)+7;
int BSearch(int val,int l,int r) {
	if (l == r) {
		if (a[l].first>=val) return l;
		return l + 1;
	}
	int mid = (l + r) / 2;
	if (a[mid].first == val) {
		int t = mid; while (t >=l && a[t].first == val) t--;
		return t + 1;
	}
	
	if (a[mid].first > val) {
		if (mid > l) return BSearch(val, l, mid - 1);
		return l;
	}
	return BSearch(val, mid + 1, r);
}
int BSearch1(int val, int l, int r) {
	if (l == r) {
		if (a[l].first >= val) return l - 1;
		return l;
	}
	int mid = (l + r) / 2;
	if (a[mid].first == val) {
		int t = mid; while (t >= l && a[t].first == val) t--;
		return t;
	}
	if (a[mid].first > val) {
		if (mid > l) return BSearch(val, l, mid - 1);
		return l - 1;
	}
	return BSearch(val, mid + 1, r);
}
void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].second >> a[i].first;
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) d[i] = ll(1e18),f[i]=0;
	d[n + 1] = inf; f[n + 1] = 0;
	a[0].first = 0, a[0].second = 0;
	a[n + 1].first = int(1e9) + 7;
	a[n + 1].second = int(1e9) + 8;

	priority_queue<li, vli, greater<li>> q;
	q.push(li(0, 0));
	d[0] = 0; f[0] = 1;
	while (!q.empty()) {
		li front = q.top(); q.pop();
		int ind = front.second;
		if (front.first > d[ind]) continue;
		int l = BSearch(a[ind].second, ind + 1, n+1),r=n+1;
		while (l <= r) {
			if (l == n + 1) {
				
				if (d[l] > d[ind]) {
					d[l] = d[ind];
					f[l] = f[ind];

				}
				else if (d[l] == d[ind]) {
					f[l] = (f[l] + f[ind]) % mod;
				}
			}
			else {
				if (d[l] > d[ind] + a[l].first - a[ind].second) {
					d[l] = d[ind] + a[l].first - a[ind].second;
					f[l] = f[ind];
					q.push(li(d[l], l));
				}
				else if (d[l] == d[ind] + a[l].first - a[ind].second) {
					f[l] = (f[l] + f[ind]) % mod;
				}
			
				if (a[l].second <= a[r].first) {
					r = BSearch1(a[l].second, l + 1, r);
				}
			}
			l++;
		}
	}
	cout << f[n + 1] << endl;
}

int main()
{
	solve();
//	system("pause");
    return 0;
}

