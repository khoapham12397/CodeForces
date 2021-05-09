#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m;

bool read() {
	return !!(cin >> n >> m);
}

const int N = 1200300;

const int mod = 1000 * 1000 * 1000 + 7;

int gcd(int a, int b, int& x, int& y) {
	if (!a) {
		x = 0, y = 1;
		return b;
	}
	int xx, yy, g = gcd(b % a, a, xx, yy);
	x = yy - b / a * xx;
	y = xx;
	return g;
}

inline int inv(int a) {
	int x, y;
	assert(gcd(a, mod, x, y) == 1);
	x %= mod;
	return x < 0 ? x + mod : x;
}

inline int mul(int a, int b) { return int(a * 1ll * b % mod); }
inline int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
inline int sub(int a, int b) { return a - b < 0 ? a - b + mod : a - b; }

inline void inc(int& a, int b) { a = add(a, b); }

int fact[N], ifact[N];

inline int C(int n, int k) {
	if (k < 0 || k > n) return 0;
	return mul(fact[n], mul(ifact[k], ifact[n - k]));
}

int pm[N], pm1[N];

void solve() {
	const int N = n + 1;

	fact[0] = 1; fore(i, 1, N) fact[i] = mul(fact[i - 1], i);
	forn(i, N) ifact[i] = inv(fact[i]);

	pm[0] = 1; fore(i, 1, N) pm[i] = mul(pm[i - 1], m);
	pm1[0] = 1; fore(i, 1, N) pm1[i] = mul(pm1[i - 1], sub(m, 1));

	int ans = pm[n];
	fore(s, 1, n + 1) {
		int cur = 1;
		cur = mul(cur, pm[s]);
		cur = mul(cur, pm1[n - s]);
		cur = mul(cur, C(n, s - 1));
		inc(ans, cur);
	}
	cout << ans << endl;
}