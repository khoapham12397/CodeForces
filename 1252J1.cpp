#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
int n,k,g1,g2,g3;
int dp[51][51][2];
char s[100005];
vi pos;
void solve() {
	scanf("%d %d %d %d %d", &n, &k, &g1, &g2, &g3);
    scanf("%s", &s);
	int ans = 0;
	int st = 0,ss=0; while (st < n && s[st] == '#') st++,ss++;
	for (int i = st; i < n; i++) {
		if (s[i] == '#') ss++, pos.push_back(i);
	}
	int len = pos.size();

	if (len > 0) {
		for(int i=0;i<len;i++) for(int j=0;j<=len;j++) for(int j1=0;j1<2;j1++) dp[i][j][j1]=0;
		dp[0][0][0] = (pos[0] - st) / 2;
		dp[0][0][1] = -1;
		dp[0][1][0] = -1;
		if (pos[0] + 1 < n && s[pos[0] + 1] == '.') dp[0][1][1] = (pos[0] - 1 - st) / 2;
		else dp[0][1][1] = -1;
		for (int i = 1; i < len; i++) {
			dp[i][0][0] = dp[i - 1][0][0] + int((pos[i] - pos[i - 1] - 1) / 2);
			dp[i][0][1] = -1;

			for (int t = 1; t <= i ; t++) {
				dp[i][t][0] = -1;
				if(dp[i-1][t][0]!=-1) dp[i][t][0] = dp[i - 1][t][0] + int(pos[i] - pos[i - 1] - 1) / 2;
				if (dp[i - 1][t][1] != -1) {
					dp[i][t][0] = max(dp[i][t][0], dp[i - 1][t][1] + int(pos[i] - pos[i - 1] - 2) / 2);
				}
				
				dp[i][t][1] = -1;
				if (pos[i] + 1 < n && s[pos[i] + 1] == '.' && s[pos[i] - 1] == '.') {
					if (dp[i - 1][t - 1][0] != -1) {
						dp[i][t][1] = dp[i - 1][t - 1][0] + int((pos[i] - pos[i - 1] - 2) / 2);
					}
					if (dp[i - 1][t - 1][1] != -1) {
						dp[i][t][1] = max(dp[i][t][1], dp[i - 1][t - 1][1] + int((pos[i] - pos[i - 1] - 3) / 2));
					}
				}
			}
			dp[i][i + 1][0] =  dp[i][i + 1][1] = -1;
			if (pos[i] + 1 < n && s[pos[i] + 1] == '.' && s[pos[i] - 1] == '.' && dp[i - 1][i][1] != -1) 
				dp[i][i + 1][1] = dp[i - 1][i][1] + int((pos[i]-pos[i-1]-3)/2);
		}
		
		for (int t = 0; t <= len; t++) {
			int s2max=-1;
			if ( dp[len - 1][t][0] != -1) {
				s2max = dp[len - 1][t][0];
				if (pos[len - 1] + 1 < n) s2max += int((n-1 - pos[len - 1]) / 2);
			}
			if (dp[len - 1][t][1] != -1) {
				int x = dp[len - 1][t][1];
				if (pos[len - 1] + 2 < n) x += int((n - 2 - pos[len - 1]) / 2);
				s2max = max(s2max, x);
			}
			if (s2max != -1) {
				int r = n - t * 3 - s2max * 2  - (ss-t);
				int val = 0;
				if (r >= k) {
					val = g1*k + g2*s2max + g3*t;
					ans = max(ans, val);
				}
				else {
					val = r*g1 + t*g3 + g2*s2max;
					int d = k - r;
					if (s2max> 0 && g1 * 2 > g2) {
						if (d <= s2max * 2) {
							int x = d / 2;
							val += 2 * x*g1 - x*g2 + ((d % 2 == 1) && (g1 > g2))*(g1-g2);
						}
						else {
							val += s2max * 2 * g1 - s2max*g2;
						}
					}
					
					ans = max(ans, val);
				}
			}
		}
		cout << ans << endl;
	}
	else {
		int s2 = (n - st) / 2;
		int r = n - 2 * s2 - ss;
		if(r>=k) {
			cout << k*g1 + s2*g2 << endl;
			return;
		}
		else {
			int d = k - r;
			int val = r*g1 + s2*g2;
			if (s2 > 0 && g1 * 2 > g2) {
				if (d <= s2 * 2) {
					int x = d / 2;
					val += 2 * x*g1 - x*g2 + (d % 2 == 1 && g1 > g2)*(g1-g2);
				}
				else val += s2 * 2 * g1 - s2*g2;
			}
			cout << val << endl;
		}
	}
}
int main()
{
	solve();
//	system("pause");
    return 0;
}

