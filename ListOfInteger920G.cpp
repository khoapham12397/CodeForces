#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
using namespace std;
typedef pair<int, int > ii;
int K, P,cd;
int cal(int ct,vector<ii> vt) {
	int t = vt.size(),res=0;
	for (int st = 1; st < (1 << t); st++) {
		int val = 1,sl=0;
		for (int j = 0; j < t; j++) {
			if ((st >> j) % 2 == 1) val *= vt[j].first,sl++;
		}
		if (sl % 2 == 0) res -= ct / val;
		else res += ct / val;
	}

	
	return ct - res;
}
void solve() {
	vector<ii> vt;
	int x = P;
	for (int i = 2; i*i <= P; i++) {
		if (x%i == 0) {
			int t = 0;
			while (x%i == 0) t++, x /= i;
			vt.push_back(ii(i, t));
		}
	}
	
	if (x > 1) vt.push_back(ii(x, 1));
	

	int t = vt.size();
	
	int res0 = cal(cd,vt),r = 10000000,l=cd;
	int ans;
	while (1) {
		int mid = (l + r) / 2;
		int v = cal(mid, vt) - res0;
		if (v == K) {
			ans = mid;
			break;
		}
		if (v> K) {
			r = mid - 1;
		}
		else l = mid + 1;
	}
	while (1) {
		int ok = 1;
		for (int j = 0; j < vt.size(); j++) {
			if (ans%vt[j].first == 0) {
				ok = 0; break;
			}
		}
		if (ok) break;
		else ans--;
	}
	cout << ans << endl;
}
int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> cd >> P >> K;
		solve();
	}
//	system("pause");
    return 0;
}

