#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
typedef unsigned long long ll;
int n,sa[200010],sb[200010],sc[200010],sq[200010],sab[200010],la=0,lb=0,lc=0,lq=0;
int nbc[200010];
ll p3[200010];
ll ans = 0;
//sbc thi tinh nguoc lai ???
vector<int> indQs;
string S;
ll mod = 1000000007;
ll powMod(ll x,ll y) {
	ll ans = 1, z = x;
	while (y > 0) {
		if (y % 2 == 1) ans = (ans*z) % mod;
		z = (z*z) % mod;
		y >>= 1;
	}
	return ans;
}
void solve() {
	cin >> n; cin >> S;
	ll inv2 = powMod(2, mod - 2),inv6=powMod(6,mod-2);
	sa[0] = sb[0] = sc[0] = sq[0]=0;
	if (S[0] == 'a') sa[0]++,la++;
	if (S[0] == 'b') sb[0]++,lb++;
	if (S[0] == 'c') sc[0]++,lc++;
	if (S[0] == '?') indQs.push_back(0),sq[0]=1,lq++;
	sab[0] = 0;
	p3[0] = 1;
	
	for (int i = 1; i < n; i++) {
		p3[i] = (p3[i - 1] * 3) % mod;
		sab[i] = sab[i - 1]; sa[i] = sa[i - 1]; sb[i] = sb[i - 1]; sc[i] = sc[i - 1];
		sq[i] = sq[i - 1];
		if (S[i] == 'a') la++, sa[i]++;
		if (S[i] == 'b') lb++, sb[i]++,sab[i]=(sab[i]+sa[i-1])%mod;
		if (S[i] == 'c') lc++, sc[i]++;
		if (S[i] == '?') indQs.push_back(i),lq++,sq[i]++;
	}
	p3[n] = (p3[n - 1] * 3) % mod;
	nbc[n - 1] = 0;
	for (int i = n - 2; i >= 0; i--) {
		nbc[i] = nbc[i + 1];
		if (S[i] == 'b') {
			nbc[i] = (nbc[i] + (lc - sc[i]) % mod) % mod;
		}
	}
	//dem so luong co ban:
	int k = indQs.size();
	//cout << "So luong ? = " << k << endl;
	for (int i = 1; i < n; i++) {
		if (S[i] == 'c') ans = (ans + (sab[i - 1] * p3[k]) % mod) % mod;
	}
	//cout << "So luong co ban: " << ans<<endl;
	ll ans1 = 0,ans2=0;
	for (int i = 0; i < indQs.size(); i++) {
		int ind = indQs[i];
		if (ind < n - 1) ans1 = (ans1 + (nbc[ind + 1] * p3[k - 1]) % mod) % mod;
		if (ind > 0 && ind <n-1) ans1 = (ans1 + (((sa[ind] *(lc- sc[ind])) % mod)*p3[k - 1]) % mod) % mod;
		if (ind > 0) ans1 = (ans1 + (sab[ind - 1] * p3[k - 1]) % mod) % mod;
	}
	//cout << "So luong co 1 dau ? = " << ans1 << endl;
	//day la sinh ra boi 1 dau :
	
	for (int i = 0; i < n; i++) {
		if (S[i] == 'a'& i<n-1) {
			ll slq = ll(lq) - ll(sq[i]);
			ans2= (ans2+(((((slq*(slq - 1)) % mod)*inv2)%mod)*p3[k-2])%mod) %mod;
		}
		if (S[i] == 'b' && i>0) {
			ll slq1 = ll(sq[i - 1]), slq2 = ll(lq) - ll(sq[i - 1]);
			ans2 = (ans2 + (((slq1*slq2)%mod)*p3[k - 2]) % mod) % mod;
		}
		if (S[i] == 'c' && i < n && i>0) {
			ll slq = ll(sq[i - 1]);
			ans2 = (ans2 + ((((((slq - 1)*slq) % mod)*inv2) % mod)*p3[k-2])%mod) % mod;
		}
	}
	//cout << "So luong co 2 dau ? = " << ans2 << endl;
	ans = (ans + (ans1 + ans2) % mod) % mod;
	if (k > 2) ans = (ans + (((((((ll(k)*ll(k - 1)) % mod)*ll(k - 2)) % mod)*inv6)%mod*p3[k-3])%mod) % mod) % mod;

	cout << ans << endl;
}
int main()
{
	solve();
//	system("pause");
    return 0;
}

