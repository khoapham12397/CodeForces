#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;
int n,type[1010],sl[100000],K,del,el=0,opr=0;
bool stop = 0;
ll a[1010];
bitset<1000010>bs;
vector<ll> primes;
vector<ll> ps;
vi sc,sr;
vector<vi> res;
void sieve(ll up) {
	bs.set(); bs[0] = bs[1] = 0;
	for (ll i = 2; i <= up; i++) {
		if (bs[i]) {
			for (ll j = i*i; j <= up; j += i) bs[j] = 0;
			primes.push_back(i);
		}
	}
}
ll gcd(ll x, ll y) {
	if (y == 0) return x;
	return gcd(y, x%y);
}
bool cal(int t,int s) {
	opr++;
	if(opr >= 2*int(1e6)) return 0;
	if (s <= res[t].size() - 2) {
		sc[t] = res[t].size() - s; return 1;
	}
	if (s == res[t].size() ) {
		sc[t] = 0; return 1;
	}
	if (s > res[t].size() && t<res.size()-1) {
		sc[t] = 0;
		int s1 = s - res[t].size();
		if(sr[t + 1] >=s1 && cal(t + 1, s1)) return 1;
		s1 += 2;
		sc[t] = 2; if(sr[t+1] >= s1 && cal(t + 1,s1)) return 1;
		
		sc[t] = res[t].size(); if(sr[t+1]>=s && cal(t + 1, s)) return 1;
		if (res[t].size() > 2) {
			sc[t] = res[t].size() - 1; 
			if(sr[t+1]>=s-1 && cal(t + 1, s - 1)) return 1;
		}
		if (res[t].size() > 3) {
			sc[t] = 3;  s1 = s - res[t].size() + 3;
			if (sr[t + 1] >= s1 && cal(t + 1, s1)) return 1;
		}
	}
	else {
		if (t < res.size() - 1) {
			sc[t] = res[t].size();
			if(sr[t+1]>=s && cal(t + 1, s)) return 1;

			if (res[t].size() > 2) {
				sc[t] = res[t].size() - 1; 
				if(sr[t + 1] >= s - 1 && cal(t + 1, s - 1)) return 1;
			}
			if (res[t].size() > 3) {
				sc[t] = 3;  int s1 = s - res[t].size() + 3;
				if (sr[t + 1] >= s1 && cal(t + 1, s1)) return 1;
			}
		}
	}
	return 0;
}
void solve() {
	sieve(1000000);
	cin >> n >> K;
	vector<int> cs;
	
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		ll x = a[i];
		type[i] = 2;
		for (int j = 0; j < primes.size(); j++) {
			ll p = primes[j];
			if (x%p == 0) {
				while (x%p == 0) x /= p;
				if (x > 1)  type[i] = 0;
				else {
					type[i] = 1;
					sl[j]++;
				}
				break;
			}
		}
		if (type[i] == 2) cs.push_back(i);
	}
	for (int i = 0; i < primes.size(); i++) {
		if (sl[i] > 1) ps.push_back(primes[i]);
	}
	
	if (cs.size() > 0) {
		
		for (int i = 0; i < cs.size() - 1; i++) {
			for (int j = i + 1; j < cs.size(); j++) {
				int id1 = cs[i], id2 = cs[j];
				ll d = gcd(a[id2], a[id1]);
				if (d == a[id1]) {
					type[id1] = 1;
					if ((a[id2] / a[id1]) == d) {
						type[id2] = 1;
						ps.push_back(d);
					}
					else type[id2] = 0;
				}
			}
		}
	}
	int t = 0;
	
	res.assign(ps.size(), vector<int>());
	vector<int> rs;
	for (int i = 0; i < n; i++) {
		ll x = a[i]; bool ok = 0;
		for (int j = 0; j < ps.size(); j++) {
			if (type[i] == 1 && a[i] % ps[j] == 0) {
				res[j].push_back(i); t++;
				ok = 1;
				break;
			}
			else while (x%ps[j] == 0) x /= ps[j];
		}
		if (!ok && x == 1) rs.push_back(i);
	}
	int fmin = int(1e9),indMin =0;
	vector<int> vt; vt.assign(ps.size(), 0);
	vector<int> adj;
	for (int i = 0; i < rs.size(); i++) {
		int x = 0; 
		for (int j = 0; j < ps.size(); j++) {
			if (a[rs[i]] % ps[j] == 0) x++;
		}
		if (fmin > x) fmin = x, indMin = i;
	}
	
	if (rs.size() > 0) {
		for (int i = 0; i < ps.size(); i++) {
			if (a[rs[indMin]] % ps[i] == 0) {
				vt[i] = 1, adj.push_back(i);
			}
		}
	}
	if (t + rs.size() < K) { cout << 0 << endl; return; }
	
	if(t<=K && t+ rs.size() >=K){
		int u = 0;
		for (int i = 0; i < ps.size(); i++) {
			for (int j = 0; j < res[i].size(); j++) {
				cout << a[res[i][j]] << " ";
				u++; 
			}
		} if (u == K) { cout << endl; return; }
		for (int i = 0; i < rs.size(); i++) {
			cout << a[rs[i]] << " "; u++; if (u == K) { cout << endl; return; }
		}
	}
	del = t - K;

	for (int i = 0; i < ps.size(); i++) {
		sc.push_back(res[i].size());
		int  x = min(del, int(res[i].size()) - 2);
		del -= x; sc[i] -= x;
	}
	
	if (del == 0) {
		for (int i = 0; i < res.size(); i++) {
			for (int j = 0; j < sc[i]; j++) {
				cout << a[res[i][j]] << " ";
			}
		}cout << endl;
		return;
	}

	if (del % 2 == 0) {
		int s = ps.size() - del / 2;
		for (int i = 0; i < s; i++) for (int j = 0; j < 2; j++) {
			cout << a[res[i][j]] << " ";
		}
		cout << endl; 
		return;
	}
	int x = ((del - 1) / 2)+1;

	if (ps.size() - x < fmin) { 
		del = t - K;
		sr.assign(res.size(), 0); 
		for (int i = 0; i < res.size(); i++) sc[i] = res[i].size();
		sr[res.size() - 1] = sc[res.size() - 1];
		for (int i = res.size() - 2; i >= 0; i--)  sr[i] = sr[i + 1] + sc[i];
		if (cal(0, del)) {
			for (int i = 0; i < res.size(); i++) for (int j = 0; j < sc[i]; j++) cout << a[res[i][j]] << " ";
			cout << endl; return;
		}
		else { cout << 0 << endl; return; }
	}
	int u = 1;
	cout << a[rs[indMin]] << " ";
	for (int i = 0; i < adj.size(); i++) {
		for (int j = 0; j < 2; j++) {
			cout << a[res[adj[i]][j]] << " ";
			u++; 
		}
	}if (u == K) { cout << endl; return; }
	for (int i = 0; i < res.size(); i++) {
		if (!vt[i]) {
			for (int j = 0; j < 2; j++) {
				cout << a[res[i][j]] << " "; u++;
				if (u == K) { cout << endl; return; }
			}
			
		}
	}
}
int main()
{
	solve();
	//system("pause");
    return 0;
}

