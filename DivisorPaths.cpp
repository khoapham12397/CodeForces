#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <unordered_map>

using namespace std;
typedef unsigned long long ull;
typedef pair<ull, int> uli;
typedef pair<int, int> ii;
unordered_map<ull, vector<uli>> dats;
unordered_map<ull, bool> caled;
bitset<1000010> bs;
int q;
ull D,mod= 998244353;
ull C[100][100];
vector<ull> primes;
void sieve(ull n) {
	bs.set();
	bs[0] = bs[1] = 0;
	for (ull i = 2; i <= n; i++) {
		if (bs[i] == 1) {
			for (ull j = i*i; j <= n; j += i) {
				bs[j] = 0;
			}
			primes.push_back(i);
		}
	}
}
ull gcd(ull u, ull v) {
	if (u%v==0) return v;
	return gcd(v, u%v);
}
int find(ull m,vector<uli> vt) {
	for (int i = 0; i < vt.size(); i++) {
		if (vt[i].first == m) return i;
	}
}
vector<uli> ptnt(ull m) {
	vector<uli> vt;
	if (m == 1) return vt;
	for (int i = 0; i < primes.size(); i++) {
		ull p = primes[i];

		if (m%p == 0) {
			int t = 0;
			while (m%p == 0) m /= p, t++;
			vt.push_back(uli(p, t));
		}
		if (m == 1) break;

		if (m <= primes[primes.size()-1] && bs[int(m)]==1) {
			vt.push_back(uli(m, 1)); m = 1;
			break;
		}
		if (m < p*p) break;
	}
	if (m > 1) {
		vt.push_back(uli(m, 1)); 
	}
	return vt;
}
void solve() {
	cin >> D>>q;
	for (int i = 0; i < 100; i++) C[0][i] =C[i][i]=1;
	
	for (ull i = 2; i < 100; i++) {
		C[1][i] = i%mod;
		for (ull j = 2; j < i; j++) {
			C[j][i] = (C[j][i - 1] + C[j - 1][i - 1]) % mod;
		}
	}
	for (int i = 0; i < q; i++) {
		ull u, v,d; cin >> u >> v;
		if(u==v) {cout<<1<<endl;continue;} 

		if (u > v) d = gcd(u, v);
		else d = gcd(v, u);
		vector<uli> vt1, vt2;
		if (caled[u]) vt1 = dats[u];
		else 
			vt1 = ptnt(u); dats[u] = vt1; caled[u] = true;
		
		if (u == v) vt2 = vt1;
		else {
			if (caled[v]) vt2 = dats[v];
			else { vt2 = ptnt(v); dats[v] = vt2; caled[v] = true;}
		}
		
		int ts1 = 0, ts2 = 0;
		ull res1 = 1, res2 = 1, res = 0;
		for (int i = 0; i < vt1.size(); i++) ts1 += vt1[i].second;
		for (int i = 0; i < vt2.size(); i++) ts2 += vt2[i].second;
		if (u == v && d!=1) {
			int gtmax = 0,slm=0;
			for (int i = 0; i < vt1.size(); i++) {
				if (vt1[i].second > gtmax) {
					gtmax=vt1[i].second; slm = 1;
				}
				else if (vt1[i].second == gtmax) slm++;
			}
			cout << slm << endl;
			continue;
		}
		if (d==1) {
			for (int i = 0; i < vt1.size(); i++) {
				res1 = (res1*C[vt1[i].second][ts1]) % mod;
				ts1 -= vt1[i].second;
			}
			
			for (int i = 0; i < vt2.size(); i++) {
				res2 = (res2*C[vt2[i].second][ts2]) % mod;
				ts2 -= vt2[i].second;
			}
			res = (res1*res2)%mod;
		}
		else {
			//gia su neu co 2 so bang nhau thi no se lam the nao ???

			int val1=ts1,val2=ts2;
			res = 0;
			ull pres1 = 1,pres2=1,tg=d;
			//dieu nay rat la dac hiet dung la vay 

			for (int i = 0; i < vt1.size(); i++) {
				ull p = vt1[i].first;
				if (tg%p == 0) {
					int t = 0; 
					while (tg%p == 0) {
						tg /= p;
						t++;
					}
					vt1[i].second -= t;
					val1 -= t;
				}
			}
			for (int k= 0; k < vt1.size(); k++) {
				res1 = (res1*C[vt1[k].second][val1]) % mod;
				val1 -= vt1[k].second;
			}
			tg = d;
			
			for (int i = 0; i < vt2.size(); i++) {
				ull p = vt2[i].first;
				if (tg%p == 0) {
					int t = 0;
					while (tg%p == 0) {
						tg /= p; t++;
					}
					vt2[i].second -= t;
					val2 -= t;
				}
			}
			for (int k = 0; k < vt2.size(); k++) {
				res2 = (res2*C[vt2[k].second][val2]) % mod;
				val2 -= vt2[k].second;
			}
			res = (res1*res2)%mod;
			
		}
		cout << res << endl;
	}

	
	
}
int main()
{
	sieve(1000000);
	solve();

//	system("pause");
	return 0;
}

