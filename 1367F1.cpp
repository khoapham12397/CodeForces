#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> ii;

void solve() {
	int n;
	cin >> n;
	int b[3010];
	ii a[3010];
	for (int i = 0; i < n; i++) {
		cin >> a[i].first; a[i].second = i;
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		b[a[i].second] = i+1;
	}
	int s[3010];
	for(int i=1;i<=n;i++) s[i] =0;
	s[b[0]] = 1;
	int gtmax = 0;
	for (int i = 0; i < n; i++) {
		s[b[i]] = max(s[b[i] - 1] + 1,s[b[i]]);
		gtmax = max(gtmax, s[b[i]]);
	}
	cout << n - gtmax << endl;
}
int main()
{
	int t; cin >> t;
	while(t--) solve();
//	system("pause");
    return 0;
}

