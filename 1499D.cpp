#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

bitset<100010> bs;
typedef pair<int, int> ii;
typedef vector<ii> vii;
vi primes,usx;
vii vtx,unt[20000010];
int c, d, x,p2[21];
int slnt[20000010] = {0};
int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}
void sieve(ll n) {
	bs.set(); 
	bs[0] = bs[1] = 0;
	for (ll i = 2; i <= n; i++) {
		if (bs[i]) {
			for (ll j = i*i; j <= n; j += i) bs[j] = 0;
			primes.push_back(i);
		}
	}
}
void ptnt(int t,int s) {
	int u = 1,p= vtx[t].first;
	for (int i = 0; i <= vtx[t].second; i++) {
		if (t == vtx.size() - 1) usx.push_back(s*u);
		else ptnt(t + 1, s*u);
		u *= p;
	}
}

void solve() {
	cin >> c >> d >> x;
	int k = 1;
	if (c > d) k = gcd(c, d);
	else k = gcd(d, c);
	if (x%k != 0) { cout << 0 << endl; return; }
	c = c / k; d = d / k; x = x / k;

	vtx.clear();usx.clear();

	int ans = 0;
	int val = x;
	for (int i = 0; i < primes.size(); i++) {
		int p = primes[i];
		if (val % p == 0) {
			int t = 0;
			while (val%p == 0) val /= p, t++;
			vtx.push_back(ii(p, t));
		}
	}
	if (val > 1) vtx.push_back(ii(val, 1));
	
	ptnt(0, 1);
	
	for (int i = 0; i < usx.size(); i++) {
		
		int b = usx[i];
		int y = x / b + d;
		if (y%c != 0) continue;
		int k = y / c,uc=1;
		if (k > b) uc = gcd(k, b);
		else uc = gcd(b, k);
		int slk = 0 , t=0;
		for (int j = 0; j < primes.size(); j++) {
			int p = primes[j];
			if (k%p == 0) {
				if (uc%p == 0) t++;
				slk++; while (k%p == 0) k /= p;
			}
		
			if (k < p*p) break;
		}
		if (k > 1) {
			slk++;
			if (uc%k == 0)t++;
		}
		if (t > 0) slk = slk - (t - 1);
		ans += p2[slk];
	}
	cout << ans << endl;

}
int main()
{
	sieve(3200);
	p2[0] = 1; for (int i = 1; i < 21; i++) p2[i] = (p2[i - 1] * 2) ;

	int t; cin >> t;
	while (t--) solve();
//	system("pause");
    return 0;
}

