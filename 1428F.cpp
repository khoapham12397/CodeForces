#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
int n;
int st[2000010],gid[500010],L[500010],isg[500010];
vi vta;
ll dp[500010],ans=0;
void build(int id,int l,int r) {
	if (l == r) {
		st[id] = l; return;
	}
	int mid = (l + r) >> 1;
	build(2 * id, l, mid);
	build(2 * id + 1, mid + 1, r);
	int x = vta[st[2 * id]] , y= vta[st[2*id+1]];
	if (x > y) st[id] = st[2 * id];
	else st[id] = st[2 * id + 1];
}
int get(int id, int l, int r, int u, int v) {
	if (l >= u && r <= v) return st[id];
	if (l > v || r < u) return -1;
	int mid = (l + r) >> 1;
	int id1 = get(2 * id, l, mid, u, v), id2 = get(2 * id + 1, mid + 1, r, u, v);
	if (id1 == -1) return id2;
	if (id2 == -1) return id1;
	if (vta[id1] > vta[id2]) return id1;
	return id2;
}
string S;
void solve() {
	cin >> n; cin >> S;
	vta.push_back(0);
	int t = 1; 
	int ind = 0,sl=0,l; while (ind <n && S[ind] == '0') ind++;
	if(ind==n) {cout<<0<<endl; return;}
	l = ind+1;
	while (ind < n) {
		while (ind < n && S[ind] == '1') {
			gid[ind + 1] = t; L[ind + 1] = l;
			ind++; sl++;
		}
		isg[t] = l;
		vta.push_back(sl); sl = 0; t++;
		while (ind < n && S[ind] == '0') ind++;
		l = ind + 1;
	}
	int len = vta.size() - 1;
	
	build(1, 1, len);
	dp[1] = (S[0] == '1'); ans = dp[1];
	for (int i = 1; i < n; i++) {
		if (S[i] == '0') {
			dp[i + 1] = dp[i];
		}
		else {
			int l = L[i + 1];
			
			int val = i + 2 - l;
			int id = gid[i+1] ;
				
			if (id > 1) {
				int left = 1, right = id - 1 ,ind = 0;
				while (left <= right) {
					int mid = get(1, 1, len, left, right);
					if (vta[mid] == val) {
						ind = mid;
						break;
					}
					if (vta[mid] > val) {
						ind = mid;
						left = mid + 1;
					}
					else break;
				}
				
				if (ind != 0) {
					int j = isg[ind] + vta[ind] - 1;
					ll x= dp[j] - ((ll(val)*ll(val + 1)) / 2);
					int del = isg[id] - 1 - (j- (val-1)) +1 ;
					dp[i + 1] = (ll(val)*ll(val + 1)) / 2 + x + ll(del) *ll(val);
				}
				else dp[i + 1] = (ll(val)*ll(val + 1)) / 2 + ll(isg[id] - 1)*ll(val);
			}
			else dp[i + 1] = (ll(val)*ll(val + 1)) / 2 + ll(isg[id] - 1)*ll(val);
		}
		ans += dp[i+1];
	}
	cout << ans << endl;
}
int main()
{
	solve();
//	system("pause");
    return 0;
}

