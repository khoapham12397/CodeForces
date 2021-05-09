#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
int n,m;
ll b[200010],c[200010];
ll gcd(ll x, ll y) {
	if (y == 0) return x;
	return gcd(y, x%y);
}
void solve() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> c[i];
	for (int i = 0; i < m; i++) cin >> b[i];
	if(n==1){
		for(int i=0;i<m;i++) cout<<c[0]+b[i]<<" ";
		cout<<endl;return;
	}
	sort(c, c + n);
	ll d = c[1] - c[0];
	for (int i = 1; i < n - 1; i++) {
		ll del = c[i + 1] - c[i];
		if (d > del)  d = gcd(d, del);
		else d = gcd(del, d);
	}
	for (int i = 0; i < m; i++) {
		ll x = c[0] + b[i];
		if (d > x) cout << gcd(d, x) << " ";
		else cout << gcd(x, d) << " ";
	}
	cout << endl;
}
int main()
{
	solve();
//	system("pause");
    return 0;
}

