#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> ii;
typedef unsigned long long ll;
int n, m, a[510];
ll mod = 998244353, F[501][501];
ii gtmins[501][501];
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++) {
        gtmins[i][i].first = i, gtmins[i][i].second = a[i];
        int val = a[i], ind = i;

        for (int j = i + 1; j <= n; j++) {
            if (a[j] < val) {
                val = a[j]; ind = j;
            }
            gtmins[i][j].first = ind; gtmins[i][j].second = val;
        }
    }
    for (int i = 1; i <= n; i++) F[i][i] = 1;

    for (int d = 1; d <= n - 1; d++) {
        for (int l = 1; l <= n - d; l++) {
            int r = l + d;
            int ind = gtmins[l][r].first;
            ll val = 0,left=0,right=0;
            
            for (int x = l + 1; x < ind ; x++) left = (left + (F[l][x-1]*F[x][ind-1])%mod) % mod;
            if(ind>l) left = (left + ((F[l][ind - 1]*2) %mod)) % mod;
            else left = (left + 1) % mod;
            for (int y = ind + 1; y < r; y++) right = (right + (F[ind + 1][y] * F[y + 1][r])%mod ) % mod;
            if(r>ind) right = (right + ((F[ind + 1][r] * 2) % mod)) % mod;
            else right = (right + 1) % mod;

            F[l][r] = (left * right)%mod;
        }
    }
    cout << F[1][n] % mod << endl;
}
int main()
{
    solve();
//    system("pause");
    return 0;
}

