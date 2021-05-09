
#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <fstream>
using namespace std;
typedef long long ll;
int n,a[5000005],scp=0;
ll F[5000005], ans;
vector<int> primes;
bitset<5000010> bs;
bool iSQ[5000005];
void sieve(ll up) {
	bs.set();
	bs[0] = 0; bs[1] = 1;
	for (ll i = 2; i <= up; i++) {
		if (bs[i]) {
			for (ll j = i*i; j <= up; j += i) {
				bs[j] = 0;
				a[j] = i;
			}
			primes.push_back(i);
			a[i] = i;
		}
	}
}

void solve() {
	if (n < 9) {
		ans=0;
		return;
	}
	if (n == 9) {
		ans=1; return;
	}
	sieve(5000001);
	for (int i = 0; i < 9; i++) F[i] = 0,iSQ[i]=0;
	iSQ[1] = 1; iSQ[4] = 1; iSQ[9] = 1;
	F[9] = 1;
	scp = 3;
	ans = 1;
	for (int i = 10; i <= n; i++) {
		if (bs[i]) {
			F[i] = 0;
		}
		else {
			int sl = 0,x=i,t=1;
			while (x%a[i] == 0) sl++, x/= a[i],t*=a[i];
			if (sl % 2 == 0) {
				int y = i / t;
				if (iSQ[y]) {
					F[i] = scp*(scp - 1) / 2;
					ans += F[i];
					scp += 1; iSQ[i] = 1;
				}
				else {
					int sct=1;
					int y1 = y, s = 0;
					while (1) {
						s = 0;
						y1 = y;
						while (y1%a[y] == 0) s++,y1/=a[y];
						if (s % 2 == 1) { sct = a[y]; break; }
						else {
							y = y1;
						}
					}
					
					F[i] = F[i / sct];
					ans += F[i];
				}
			}
			else {
				F[i] = F[i / a[i]];
				ans += F[i];
			}
		}
	}
	//cout << ans << endl;
}
int main()
{
	fstream f;
	f.open("SQUARE.INP","r");
	f >> n;
	f.close();

	solve();

	f.open("SQUARE.OUT","w");
	f<<ans<<endl;
	f.close();
	//system("pause");
	return 0;
}

