#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> ii;
typedef long long ll;
int n,pos[200001],tt;
int team[200001];
ll dp[200001];
ii a[200001];
//nhom cac gia tri bang nhau lai:
int L[200001];
void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		a[i].first = x; a[i].second = i;
	}

	sort(a, a + n);
	//
	L[0] = 0;
	for (int i = 1; i < n; i++) {
		if (a[i].first == a[i - 1].first) L[i] = L[i - 1];
		else L[i] = i;
	}
	
	
	pos[2] = 0; dp[2] = a[2].first - a[0].first;
	for (int i = 3; i < n; i++) {
		ll val;
		int t, p0 = pos[i - 1];
		val = a[i].first - a[p0].first;
		if (p0 != 0) val += dp[p0 - 1];
		t = p0;
		int ghp=min(L[i],i-2);
		
		for (int p = p0+1; p <=ghp; p++) {
			if (p < 3) continue;
			ll del = a[i].first - a[p].first+dp[p-1];
			if (val > del) {
				val = del;
				t = p;
			}
		}
		dp[i] = val; pos[i] = t;
	}
	tt = 1;
	int t = 0,ind=n-1;
	while (ind > 0) {
		int x = pos[ind];
		for (int i = x; i <= ind; i++) team[a[i].second] = tt;
		ind = x - 1;
		tt++;
	}
	cout <<dp[n-1]<<" "<< tt - 1 << endl;
	for (int i = 0; i < n; i++) cout << team[i] << " ";
	cout << endl;
}
int main()
{
	solve();
	//system("pause");
    return 0;
}

