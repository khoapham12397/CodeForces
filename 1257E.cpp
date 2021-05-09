#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef vector<int> vi;
typedef long long ll;
int n,k1,k2,k3,dp1[200010],dp3[200010],s1[200010],s3[200010],s12[200010],s32[200010];
int f3[200010];
vi a1, a2, a3;
void solve() {
	cin >> k1 >> k2 >> k3;
	n = k1 + k2 + k3;
	for (int i = 0; i < k1; i++) { int x; cin >> x; a1.push_back(x); }
	for (int i = 0; i < k2; i++) { int x; cin >> x; a2.push_back(x); }
	for (int i = 0; i < k3; i++) { int x; cin >> x; a3.push_back(x); }
	sort(a1.begin(), a1.end());
	sort(a2.begin(), a2.end());
	sort(a3.begin(), a3.end());
	int t = 1;

	for (int i = 0; i < k1; i++) {
		for (int j = t; j < a1[i]; j++) {
			s1[j] = i;
		}
		t = a1[i];
	}
	for (int j = a1[k1 - 1]; j <= n; j++) {
		s1[j] = k1;
	}

	t = n;
	for (int i = k1 - 1; i >= 0; i--) {
		for (int j = a1[i] + 1; j <= t; j++) s12[j] = k1 - 1-i;
		t = a1[i];
	}
	for (int j = 1; j <= t; j++) s12[j] = k1;
	
	t = n;
	for (int i = k3 - 1; i >= 0; i--) {
		for (int j = a3[i] + 1; j <= t; j++) {
			s3[j] = k3 - 1 - i;
			
		}
		t = a3[i];
	}
	for (int j = 1; j <= t; j++) {
		s3[j] = k3;
	}
	t = 1;
	for (int i = 0; i < k3; i++) {
		for (int j = t; j < a3[i]; j++) {
			s32[j] = i;
		}
		t = a3[i];
	}
	for (int j = t; j <= n; j++) s32[j] = k3;

	dp1[0] = k1; 
	
	for (int i = 1; i <= n; i++) {
		dp1[i] = (k1 - s1[i]) +i-s1[i] - s32[i];
	}
	for (int i = n; i >= 1; i--) {
		dp3[i] = k3 - s3[i] + n-i+1-s3[i] - s12[i];
	}
	dp3[n + 1] = k3;
	f3[n + 1] = k3;
	for (int i = n ; i >= 1; i--) {
		f3[i] = min(f3[i + 1], dp3[i]);
	}
	ll ans = ll(1e18);
	for (int i = 0; i <= n; i++) {
		ans=min(ans,ll(dp1[i]) + ll(f3[i + 1]));
	}
	cout << ans << endl;
}
int main()
{
	solve();
//	system("pause");
    return 0;
}

