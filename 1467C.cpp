#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef long long ll;
int inf = int(1e9) + 7;
void solve() {
	int n[3],xmin= inf,gtm[3],gtm2[3],xmin2=inf;
	ll s[3];
	for (int i = 0; i < 3; i++) cin >> n[i],gtm[i]=inf,gtm2[i]=inf,s[i]=0;
	vi v[3];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < n[i]; j++) {
			int x; cin >> x; v[i].push_back(x);
			if (gtm[i] > x) gtm2[i] = gtm[i], gtm[i] = x;
			else if (gtm2[i] > x) gtm2[i] = x;
			if (xmin > x) xmin2 = xmin, xmin = x;
			else if (xmin2 > x) xmin2 = x;
			s[i] += ll(x);
		}
	}
	ll tong =s[0]+s[1]+s[2];
	ll res = -1;
	for (int i = 0; i < 3; i++) {
		if (n[i] == 1) {
			res = max(res,tong-s[i] - ll(v[i][0]));
		}
	}
	for (int i = 0; i < 3; i++) {
		if (n[i]==2) {
			res = max(res, tong -s[i] - ll(gtm[i]) - ll(gtm2[i]));
		}
		res=max(res, tong -2*s[i]);
	}
	
	for (int i = 0; i < 2; i++) {
		for (int j = i + 1; j < 3; j++) {
			res = max(res, tong - ll(2) * ll(gtm[i]) - ll(2) * ll(gtm[j]));
		}
	}

	cout << res << endl;
}

int main()
{
	solve();
//	system("pause");
    return 0;
}

