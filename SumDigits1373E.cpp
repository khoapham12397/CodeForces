#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int N, K;
char kt[10] = { '0','1','2','3','4','5','6','7','8','9' };
void solve() {
	string ans="";
	if (K == 0) {
		int u = N / 9, r = N % 9;
		if (r > 0) ans += kt[r];
		for (int i = 0; i < u; i++) ans += "9";
		cout << ans << endl; return;
	}
	if (K < 9) {
		int t = 9 - K,s=0;
		for (int i = t; i < 10; i++) s += i;
		while(s>N && t<9){
			t++;
			s=(t + K - 9)*(t + K - 8) / 2 + 45 - t*(t - 1) / 2;
		}
		if (s > N) {
			int t = 8 - K;
			while (s>N && t > 0) {
				s = (t + K)*(t + K + 1) / 2 - t*(t - 1) / 2;
				t--;
			}
			if (s == N) { cout << t << endl; }
			if (s > N) { 
				if (N == K*(K + 1) / 2) cout << 0 << endl;
				else cout << -1 << endl;
			}
			return;
		}
		if (s == N) { cout << t << endl; return; }
		int x = (N - s)/(K+1);
		int u = x / 9, r = x % 9;
		string ans = "";
		if (r > 0) { ans += kt[r]; }
		for (int i = 0; i < u; i++) ans += '9';
		ans += kt[t];
		cout << ans << endl;
	}
	else {
		int t = 9,s;
		s = 45 - t*(t - 1) + (t + K - 9)*(t + K - 8) / 2;
		while (s > N && t>0) {
			t--;
			s = 45 - t*(t - 1) + (t + K - 9)*(t + K - 8) / 2;
		}
		if (s > N) {cout << -1 << endl; return;}
		if (s == N) { cout << t << endl; return; }
		int t1 = N - s;
		if (t1 < 8) { ans += kt[t1]; cout << ans << endl; return; }
		else {
			int x = t1-8,u,r;
			u = x / 9; r = x % 9;
			if (r > 0) ans += kt[r];
			for (int i = 0; i < u; i++) ans += '9';
			cout << ans << endl; 
		}
		
	}

}
int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N >> K;
		solve();
	}
//	system("pause");
    return 0;
}

