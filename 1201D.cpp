#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vl2;

int n, m, k, q;
bool b[200001];
int L[200001], R[200001];
vi vtl[200001],trs[200001];
vl2 dp[200001];
ll cal(int x, int y, int l, int r) {
	ll val = 0;
	if (x <= l) val = abs(r - y) + r - x;
	if (x > l && x <= r) {
		if (y > l && y <= r) {
			if(x >=y ) val = 2 * (r - l) - (x - y);
			else val = 2 * (r - l) - (y - x);
		}
		else {
			if (y <= l) val = r - y + r - x;
			else val = y - l + x - l;
		}
	}
	if (x > r) {
		val = abs(y - l) + x - l;
	}
	return val;
}
ll tinh(int l, int r, int y) {
	if (y < l) return r - y;
	if (y >= l && y <= r) {
		ll u = max(y - l, r-y);
		return 2 * (r - l) - u;
	}
	return y - l;
}
void solve() {
	cin >> n >> m >> k >> q;
	if(k==0) {cout<<0<<endl; return;}
	for (int i = 0; i < k; i++) {
		int x, y; cin >> x >> y;
		trs[x].push_back(y);
	}
	for (int i = 0; i < q; i++) {
		int x; cin >> x; b[x] = 1;
	}
	int ind= 1;
	while (ind<=m && !b[ind]) ind++;
	int x = ind; L[ind] = ind;
	
	
	for (int i = 1; i < x; i++) L[i] = -1;
	
	for (int i = ind+1; i <= m; i++) {
		if (b[i]) L[i] = i,x=i;
		else L[i] = x;
	}
	ind = m; while (ind >= 1 && !b[ind]) ind--;
	for (int i = m; i > ind; i--) R[i] = -1;
	R[ind] = ind;
	x = ind; 
	for (int i = ind - 1; i >= 1; i--) {
		if (b[i]) R[i] = i,x=i;
		else R[i] = x;
	}
	for (int i = 1; i <= n; i++) {
		sort(trs[i].begin(), trs[i].end());
	}
	int fr = n;
	while (trs[fr].size() == 0) fr--;
	
	if (trs[1].size() > 0) {
		int r = trs[1][trs[1].size() - 1];
		if (L[r] != -1) {
			vtl[1].push_back(L[r]);
			dp[1].push_back(r - 1 + r - L[r]);

		}
		
		if (R[r] != -1 && R[r] != L[r]) {
			vtl[1].push_back(R[r]);
			dp[1].push_back(r - 1 + R[r] - r);
		}
	}
	else {
		vtl[1].push_back(R[1]);
		dp[1].push_back(R[1] - 1);
	}
	
	// ro rang la l =r and x=y dung la vay :

	for (int i = 2; i < fr; i++) {
		int len = trs[i].size();
		if (len == 0) {
			for (int j = 0; j < vtl[i - 1].size(); j++) {
				vtl[i].push_back(vtl[i - 1][j]);
				dp[i].push_back(dp[i - 1][j] + 1);
			}
			continue;
		}
		int l = trs[i][0],r=trs[i][len-1];
		if (L[l] != -1) {
			ll val = ll(1e18);
			for (int j = 0; j < vtl[i - 1].size(); j++) {
				int y = vtl[i - 1][j];
				val = min(val,ll(1)+ dp[i-1][j] +  cal(L[l],y,l,r));
				
			}
			vtl[i].push_back(L[l]);
			dp[i].push_back(val);
		}
		if (R[l] != -1 && R[l] != L[l]) {
			ll val = ll(1e18);
			for (int j = 0; j < vtl[i - 1].size(); j++) {
				int x = vtl[i - 1][j];
				val = min(val, ll(1) + dp[i - 1][j] + cal(R[l], x, l, r));
			}
			vtl[i].push_back(R[l]);
			dp[i].push_back(val);
		}
		if (l != r) {
			if (L[r] != -1 && L[r] != R[l]) {
				ll val = ll(1e18);
				for (int j = 0; j < vtl[i - 1].size(); j++) {
					int x = vtl[i - 1][j];
					val = min(val, ll(1) + dp[i - 1][j] + cal(L[r], x, l, r));

				}
				vtl[i].push_back(L[r]);
				dp[i].push_back(val);
			}
			if (R[r] != -1 && R[r] != L[r]) {
				ll val = ll(1e18);
				for (int j = 0; j < vtl[i - 1].size(); j++) {
					int x = vtl[i - 1][j];
					val = min(val, ll(1) + dp[i - 1][j] + cal(R[r], x, l, r));

				}
				vtl[i].push_back(R[r]);
				dp[i].push_back(val);
			}

		}
		
	}
	if (fr == 1) {
		cout<<trs[1][trs[1].size() - 1]-1;
		return;
	}
	ll ans = ll(1e18);
	for (int i = 0; i < vtl[fr - 1].size(); i++) {
		int y = vtl[fr - 1][i];
		int l = trs[fr][0],r=trs[fr][trs[fr].size()-1]; 
		ans = min(ans,dp[fr-1][i]+ tinh(l, r, y)+ll(1));
	}
	cout << ans << endl;
}
int main()
{
	solve();
//	system("pause");
    return 0;
}

