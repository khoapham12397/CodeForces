#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef vector<int> vi;
typedef unsigned long long ll;
int n,q;
vi res;
ll fact[21],k=1,ans=0,L,R,st=200005;
void solve() {
	int x = 0;
	res.clear();
	while (fact[x] < k) x++;
	if (fact[x] == k) {
		st = n - x; 
		for (int i = n; i > n - x; i--) res.push_back(i);
	}
	else {
		st = n - x;
		ll t = ll(k / fact[x - 1]);
		int x1;
		if (k % fact[x - 1] == 0) {
			x1 = st + t;
			res.push_back(x1);
			for (int i = n; i > st; i--) if (i != x1) res.push_back(i);
		}
		else {
			x1 = st + t + 1;
			res.push_back(x1);
			ll r = k - t*fact[x - 1];
			vi cans; 
			for (int i = st + 1; i <= n; i++) {
				if (i != x1) {
					cans.push_back(i);
				}
			}
			while (r > 0) {
				int y = cans.size();
				ll t = ll(r / fact[y - 1]);
				int xx;
				if (r%fact[y - 1] == 0) {
					xx = cans[t - 1]; res.push_back(xx);
					for (int i = y - 1; i >= 0; i--) if (i != t-1) res.push_back(cans[i]);
					r = 0; break;
				}
				xx = cans[t]; res.push_back(xx);
				cans.erase(cans.begin() + t );
				r = r - t*fact[y - 1];
			}
		}
	}
	
}
void cal() {
	ans = 0;
	if (R <= st) {
		ans = (R*(R + 1)) / 2 - L*(L - 1) / 2;
	}
	else {
		if (L <= st) {
			ans = st*(st + 1) / 2 - L*(L - 1) / 2;
			for (int i = 0; i < R - st; i++) ans += res[i];
		}
		else {
			ans = 0;
			for (int i = L - st - 1; i <= R - st - 1; i++) ans += res[i];
		}
	}
	cout << ans << endl;
}
int main()
{	
	fact[0] = fact[1] = 1;
	for (int i = 2; i <= 19; i++) fact[i] = fact[i - 1] * ll(i);
	cin >> n >> q;
	for (int i = 0; i < q; i++) {
		int x; cin >> x;
		if (x == 1) {
			cin >> L >> R;
			cal();
		}
		else {
			ll y; cin >> y; k += y;
			solve();
		}
	}
//	system("pause");
    return 0;
}

