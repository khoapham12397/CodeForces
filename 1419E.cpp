#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <bitset>
#include <map>
using namespace std;
typedef long long ll;

typedef pair<int, int> ii;
typedef vector<ii> vii;
map<int, bool> used;
bitset<1000010> bs;
vii vt;
vector<int> primes;
int n,b[50];

void sieve(ll up) {
	bs.set(); bs[0] = bs[1] = 0;
	for (ll i = 2; i <= up; i++) {
		if (bs[i]) {
			for (ll j = i*i; j <= up; j += i) bs[j] = 0;
			primes.push_back(i);
		}
	}
}
void duyet(int t, int val, int i1, int i2,vector<int> &res) {
	int lm=vt[t].second;
	if (t == i1 || t == i2) lm--;
	for (int i = 0; i <= lm; i++) {
		int x = 1;

		for (int j = 0; j < i; j++) x *= vt[t].first;
		int v = val*x;
		if (t == vt.size() - 1) {
			int u = v*vt[i1].first*vt[i2].first;
			
			if (!used[u]) {
				used[u] = 1;
				res.push_back(u);
			}
		}
		else duyet(t + 1, v,i1,i2,res);
	}

}
void duyet2(int t,int val,int i1,vector<int> &res) {
	int lm = vt[t].second; if (t == i1) lm--;
	int i0 = (i1 + vt.size() - 1) % vt.size(),i2= (i1+1)%vt.size();

	for (int i = 0; i <= lm; i++) {
		int x = 1;
		for (int j = 0; j < i; j++) x *= vt[t].first;
		int v = val*x;
		if (t == vt.size() - 1) {
			int u = v*vt[i1].first;
			if (!used[u] && u != vt[i1].first*vt[i0].first && u != vt[i1].first*vt[i2].first) {
				used[u] = 1;
				res.push_back(u);
			}
		}
		else duyet2(t + 1, v,i1,res);
	}

}
int gcd(int a, int b) {
	if (b == 0)return a;
	return gcd(b, a%b);
}
void solve() {
	vt.clear(); 
	used.clear();

	int x = n;
	for (int i = 0; i < primes.size(); i++) {
		int p = primes[i];
		if (x%p == 0) {
			int t = 0;
			while (x%p == 0) t++, x /= p;
			vt.push_back(ii(p, t));
		}
		if (x == 1) break;
		if (p*p > n) break;
	}
	int st = primes[primes.size() - 1];
	if (x > st) {
		for (int i = st + 2; i*i <= n; i += 2) {
			if (x%i == 0) {
				int t = 0;
				while (x%i == 0) x /= i, t++;
				vt.push_back(ii(i, t));
			}
			
		}
		if (x > 1) vt.push_back(ii(x, 1));
	}
	else if (x > 1) vt.push_back(ii(x, 1));
	
	int l = vt.size();
	if (l == 1) {
		int x = vt[0].first;
		for (int i = 1; i <= vt[0].second; i++) {
			cout << x << " ";
			x *= vt[0].first;
		}
		cout << endl; cout << 0 << endl;
		return;
	}
	if (l == 2) {
		if (vt[0].second == 1 && vt[1].second == 1) {
			cout << vt[0].first << " " << vt[1].first << " " << n<<endl;
			cout << 1 << endl;
		}
		else {
			int x = vt[0].first;
			for (int i = 1; i <= vt[0].second; i++) {
				cout << x << " ";
				x *= vt[0].first;
			}
			vector<int> res;
			duyet(0, 1, 0, 1,res);
			for (int i = 0; i < res.size() - 1; i++) cout << res[i] << " ";
			x = vt[1].first;
			for (int i = 1; i <= vt[1].second; i++) {
				cout << x << " ";
				x *= vt[1].first;
			}
			cout << res[res.size() - 1] << endl;
			cout << 0 << endl;
		}
		return;
	}
	for (int i = 0; i < vt.size(); i++) {
		vector<int> res;
		duyet2(0, 1, i, res);
		for (int j = 0; j < res.size(); j++) cout << res[j] << " ";
		cout << vt[i].first*vt[(i + 1) % l].first << " ";
		
	}cout << endl;
	
	cout << 0 << endl;
	
}
int main(){
	sieve(1000000);
	int T; cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n;
		solve();
	}
//	system("pause");
    return 0;
}

