#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
int l, r, sl0[32], sl1[32];
ll p2[32], p3[32];
int gt0[32], gt1[32];
void solve() {
	for (int i = 0; i < 32; i++) gt0[i] = gt1[i] = sl0[i] = sl1[i] = 0;
	cin >> l >> r;
	int x = l, y = r;
	if(l==r && l==0 ) {cout<<1<<endl; return;}
	int t = 0, ind0, ind1;
	while (x > 0) { x >>= 1; t++; }
	ind0 = t - 1;
	if(ind0 !=-1) sl0[ind0] = 0, gt0[ind0] = 1;
	for (int i = ind0 - 1; i >= 0; i--) {
		int x = (l >> i) % 2;
		sl0[i] = sl0[i + 1] + 1 - x;
		gt0[i] = gt0[i + 1] * 2 + x;
	}

	t = 0; while (y > 0) { y >>= 1; t++; }
	ind1 = t - 1; gt1[ind1] = 1;
	sl1[ind1] = 0;
	for (int i = ind1 - 1; i >= 0; i--) {
		int x = (r >> i) % 2;
		sl1[i] = sl1[i + 1] + 1 - x;
		gt1[i] = gt1[i + 1] * 2 + x;
	}
	ll ans = 0;
	if (ind0 >= ind1) { cout << 0 << endl; return; }

	for (int i = ind0 + 1; i < ind1; i++) {
		for (int j = ind0 + 1; j < i; j++) {
			ans += p2[i - j - 1] * p3[j];
		}
		for (int j = ind0 - 1; j >= 0; j--) {
			if ((l >> j) % 2 == 0) {

				int x = sl0[j + 1];
				ans += p2[i - ind0 - 1] * p3[j] * p2[x];

			}
		}
	}
	for (int i = ind1 - 1; i >= 0; i--) {
		if ((r >> i) % 2 == 0) continue;
		for (int j = ind0 + 1; j < ind1; j++) {
			ll val = 0;
			if (i > j) val = p2[i - j - 1] * p3[j];
			if (i == j) val = p3[j];
			if (i < j) {
				if ((r >> j) % 2 == 1) continue;
				int u0 = sl1[i + 1] - sl1[j];
				val = p2[u0] * p3[i] * 2;

			}
			ans += val;
		}
	}


	for (int i = ind1 - 1; i >= 0; i--) {
		if ((r >> i) % 2 == 0) continue;
		for (int j = ind0 - 1; j >= 0; j--) {
			if ((l >> j) % 2 == 1) continue;
			ll val = 0;

			if (i > ind0) {
				int u0 = sl0[j + 1];
				val = p2[i - ind0 - 1] * p2[u0] * p3[j];
			}
			else {
				if (i == ind0) {
					int u0 = sl0[j + 1];
					val = p2[u0] * p3[j];
				}
				else {
					// i< ind0 
					if (i > j) {
						int x1 = gt1[i+1] - gt1[ind0 + 1] * p2[ind0 - i];
						int x0 = gt0[i+1] - gt0[ind0 + 1] * p2[ind0 - i];
						if ((x1 + x0) != (x1^x0)) continue;
						int u0 = sl0[j + 1] - sl0[i];
						val = p2[u0] * p3[j];

					}
					else {
						if (i == j) {
							int x1 = gt1[i + 1] - gt1[ind0 + 1] * p2[ind0 - i];
							int x0 = gt0[i + 1] - gt0[ind0 + 1] * p2[ind0 - i];
							if ((x1 + x0) != (x1^x0)) continue;
							val = p3[j];
						}
						else {
							//i <j
							if ((r >> j) % 2 == 1) continue;
							int x1 = gt1[j] - gt1[ind0 + 1] * p2[ind0 - j + 1];
							int x0 = gt0[j] - gt0[ind0 + 1] * p2[ind0 - j + 1];
							if ((x1 + x0) != (x1 ^ x0)) continue;
							int u0 = sl1[i + 1] - sl1[j];
							val = p2[u0] * 2 * p3[i];
						}
					}
				}
			}
			ans += val;
		}
	}

	for (int i = ind0 + 1; i <ind1; i++) {
		if ((r >> i) % 2 == 1) continue;
		int u0 = sl1[0] - sl1[i];
		ans += p2[u0];
	}

	for (int i = ind0 - 1; i >= 0; i--) {
		if ((l >> i) % 2 == 1 || (r >> i) % 2 == 1) continue;

		int x1 = gt1[i + 1] - gt1[ind0 + 1] * p2[ind0 - i];
		//day la + 1:
		int x0 = gt0[i + 1] - gt0[ind0 + 1] * p2[ind0 - i];
		if ((x1 + x0) != (x0^x1)) continue;
		int u0 = sl1[0] - sl1[i];
		ans += p2[u0];
	}

	for (int i = ind0 + 1; i < ind1; i++) {

		int u0 = sl0[0];
		int x = i - ind0 - 1 + u0;
		ans += p2[x];
	}

	for (int i = ind1 - 1; i >= 0; i--) {
		if ((r >> i) % 2 == 0) continue;
		if (i > ind0) {
			int u0 = sl0[0];
			ll val = p2[i - ind0 - 1 + u0];
			ans += val;
		}
		else {
			if (i == ind0) {
				ans += p2[sl0[0]];
			}
			else {
				int x1 = gt1[i + 1] - gt1[ind0 + 1] * p2[ind0 - i];
				int x0 = gt0[i + 1];
				if ((x1 + x0) != (x1 ^x0)) continue;
				ans += p2[sl0[0] - sl0[i]];
			}
		}

	}

	int x1 = gt1[0] - gt1[ind0 + 1] * p2[ind0 + 1];
	int x0 = gt0[0] - gt0[ind0 + 1] * p2[ind0 + 1];
	if ((x1 + x0) == (x1 ^ x0)) ans++;
	cout << ans * 2 + (l==0) << endl;
}

int main()
{
	p2[0] = p3[0] = 1; for (int i = 1; i < 32; i++) p2[i] = p2[i - 1] * 2, p3[i] = p3[i - 1] * 3;
	int t; cin >> t;
	while (t--) {
		solve();
	}
//	system("pause");
	return 0;
}