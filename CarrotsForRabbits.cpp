#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef unsigned long long ll;
int n, k;
ll a[100001];
ll s[100001],ans=0;
ll cal(ll m,int p) {
	ll x = m / p, r = m%p;
	
	return (x + 1)*(x + 1)*r + (p - r)*x*x;
}
void solve() {
	cin >> n>>k;
	for (int i = 0; i < n; i++) cin >> a[i];
	if (n == 1) { cout << cal(a[0], k) << endl; return; }
	sort(a, a + n); s[0] = a[0];
	for (int i = 1; i < n; i++) s[i] = s[i - 1] + a[i];
	ll x = a[0]*k/s[n-1];

	int t;
	if (x > 0) {
		ll u= s[n - 1] - s[0];
		ll val1 = cal(a[0], x), val2 = cal(a[0], x + 1);
		
		ll u1 = cal(u, k - x) + val1, u2 = cal(u, k - x - 1)+val2;
		if (u1 <= u2) {
			t = k - x;
			ans += val1;
		}
		else t = k - x - 1,ans+=val2;
	}
	else t = k-1,ans+= a[0]*a[0];
	for (int i = 1; i < n-1; i++) {
	
		ll x = a[i]*t / (s[n - 1] - s[i - 1]) ; 
			
		if (x > 0) {
			ll u = s[n - 1] - s[i];
		
			ll val1 = cal(a[i], x), val2 = cal(a[i], x + 1);
			ll u1 = cal(u, t - x) + val1, u2 = cal(u, t - x - 1) + val2;
			if (u1 <= u2) {
					t = t - x;
					ans += val1;
			}
			else t = t - x - 1, ans += val2;
			
		}
		else t = t - 1,ans+=a[i]*a[i];
		
	}
	ans += cal(a[n - 1], t);
	cout << ans << endl;
}
int main()
{
	solve();
//	system("pause");
    return 0;
}
