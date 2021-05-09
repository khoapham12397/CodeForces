#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ull,ii> node;
int n, k;
ull a[100001];
ull ans = 0;
ull cal(ull m,int p) {
	ull x = m / p, r = m%p;
	return (x + 1)*(x + 1)*r + x*x*(p - r);
}
void solve() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> a[i];
	priority_queue<node, vector<node>, less<node>> q;
	for (int i = 0; i < n; i++) {
		q.push(node(a[i] * a[i] - cal(a[i], 2), ii(0, i)));
	}
	ull delta = 0;
	for (int i = 0; i < k-n; i++) {
		node u = q.top(); q.pop();
		
		delta += u.first;
		int t = u.second.first,ind=u.second.second;
		q.push(node(cal(a[ind], t + 2) - cal(a[ind], t + 3),ii(t+1,ind)));
	}
	int fl = 0;
	for (int i = 0; i < n; i++) {
		ans += a[i] * a[i];
		if (ans >= delta && fl==0) ans -= delta,fl=1;
	}
	cout << ans << endl;
}

int main()
{
	solve();
//	system("pause");
	return 0;
}

