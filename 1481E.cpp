#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n,a[500010],dp[500010],l[500010],r[500010],f[500010];

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i],l[i]=f[i]=0;
	for (int i = 1; i <= n; i++) {
		f[a[i]]++;
		if (l[a[i]] == 0) l[a[i]] = i;
		r[a[i]] = i;
	}
	vector<int> s; s.assign(n + 1, 0);
	dp[n] = 1; 
	s[a[n]] = 1;
	for (int i = n - 1; i >= 1; i--) {
		s[a[i]]++;
		if (l[a[i]] == i) dp[i] = max(dp[i + 1], dp[r[a[i]] + 1]+ f[a[i]]);
		else dp[i] = max(dp[i + 1], s[a[i]]);
	}
	cout << n - dp[1] << endl;
}
int main()
{
	solve();
//	system("pause");
    return 0;
}

