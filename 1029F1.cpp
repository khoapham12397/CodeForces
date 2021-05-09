#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
using namespace std;
bitset<1000100>bs;
typedef long long ll;
typedef pair<ll, int> li;

vector<int> primes;
vector<ll> usa, usb,usc;
vector<li> vt,vtA,vtB,vtC;
int b[50];
ll A, B,ans=1000000000000000;
void sieve(ll up) {
	bs.set(); bs[0] = bs[1] = 0;
	for (ll i = 2; i <= up; i++) {
		if (bs[i]) {
			for (ll j = i*i; j <= up; j++) {
				bs[j] = 0;
			}
			primes.push_back(i);
		}
	}
}
ll gcd(ll x, ll y) {
	if (y == 0) return x;
	return gcd(y, x%y);
}
ll pow(ll x,ll y) {
	ll z = x;
	for (int i = 1; i < y; i++) z *= x;
	return z;
}
void timuocA(int t) {
	//find all uoc so cua A+B, A,B:
	for (int i = 0; i <= vtA[t].second; i++) {
		b[t] = i;
		if (t == vtA.size() - 1) {
			ll val = 1;
			for (int j = 0; j <= t; j++) {
				val = (val*pow(vtA[j].first, b[j]));
			}
			usa.push_back(val);
		}
		else timuocA(t + 1);
	}
}
void timuocB(int t) {
	for (int i = 0; i <= vtB[t].second; i++) {
		b[t] = i;
		if (t == vtB.size() - 1) {
			ll val = 1;
			for (int j = 0; j <= t; j++) {
				val = (val*pow(vtB[j].first, b[j]));
			}
			usb.push_back(val);
		}
		else timuocB(t + 1);
	}
}
void timuocC(int t) {
	for (int i = 0; i <= vtC[t].second; i++) {
		b[t] = i;
		if (t == vtC.size() - 1) {
			ll val = 1;
			for (int j = 0; j <= t; j++) {
				val = (val*pow(vtC[j].first, b[j]));
			}
			usc.push_back(val);
		}
		else timuocC(t + 1);
	}
}
void duyet(int t) {
	for (int i = 0; i <= vt[t].second; i++) {
		b[t] = i;
		if (t == vt.size() - 1) {
			ll val = 1;
			for (int j = 0; j <= t; j++) {
				val = (val*pow(vt[j].first, b[j]));
			}
			ans = min(ans, 2 * (val + A / val + B / val));
		}
		else duyet(t + 1);
	}
}

vector<li> ptnt(ll a) {
	ll x = a;
	vector<li> ans;
	for (int i = 0; i < primes.size(); i++) {
		int p = primes[i];
		if (x%p == 0) {
			int t = 0;
			while (x%p == 0) t++, x /= p;
			ans.push_back(li(p, t));
		}
		if (x == 1) break;
		if (p*p > a) break;
	}

	ll st = primes[primes.size() - 1];
	if (x > st) {
		for (ll i = st + 2; i*i <= a; i++) {
			if (x%i == 0) {
				int t = 0;
				while (x%i == 0) x /= i, t++;
				ans.push_back(li(i, t));
			}
		}
		if (x > 1) ans.push_back(li(x, 1));
	}
	else if (x > 1) ans.push_back(li(x, 1));
	return ans;
}
void calD() {
	ll d = gcd(A, B);
	if (d == 1) { ans = (A + B + 1) * 2; return; }
	
	vt = ptnt(d);
	duyet(0);
}
void cal1() {
	ll C = A + B;
	vtC = ptnt(A + B);
	
	vtA = ptnt(A), vtB = ptnt(B);


	 if(A>1) timuocA(0); 
	 else usa.push_back(1);
	 if(B>1) timuocB(0); 
	 else usb.push_back(1);
	
	 timuocC(0);

	sort(usa.begin(), usa.end()); sort(usb.begin(), usb.end()); sort(usc.begin(), usc.end());
	

	for (int i = 0; i < usc.size()/2; i++) {
		ll a = usc[i],b ; 
		b = C / a;
		int ok = 0;
		for (int j = 0; j < usa.size() / 2; j++) {
			if (usa[j] < a && A / usa[j] < b) {
				ok = 1; break;
			}
		}
		if (!ok) {
			for (int j = 0; j < usb.size() / 2; j++) {
				if (usb[j] < a && B / usb[j] < b) { ok = 1; break; }
			}
		}
		if (ok) ans = min(ans, 2 * (a + b));
	}
}
void solve() {
	cin >> A >> B;
	ll d = gcd(A, B);
	ll x = d;
	calD();
	cal1();
	cout << ans << endl;
}
int main()
{
	sieve(1000000);
	solve();
//	system("pause");
	return 0;
}

