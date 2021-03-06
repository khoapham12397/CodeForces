// Assign1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef vector<int> vi;
int n,c[101][101],emax=0,Assigned[101];
const int inf = 1000000;
vi adj[101];
void readData() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> c[i][j];
			emax = max(emax, c[i][j]);
		
		}
	}
}
bool duyet(int u ,int gt) {
	for (int i = 1; i <= n; i++) {
		if (!Assigned[i] && c[u][i]<=gt) {
			Assigned[i] = u;
			return true;
		}
		else {
			if (Assigned[i] != u && duyet(Assigned[i])) {
				Assigned[i] = u;
				return true;
			}
		}
	}
	return false;
}
bool match(int gt) {
	int s = 0;
	for (int i = 1; i <= n; i++) {
		s += duyet(i, gt);
	}
	if (s == n) return true;
	return false;
}
void xuly() {
	int l = 0,r=emax;
	int mid;
	int ans = emax;
	while (1) {
		mid = (l + r) / 2;
		if (match(mid)) {
			ans = mid;
			r = mid - 1;
		}
		else {
			if (l == r) break;
			else l = mid + 1;
		}
	}
	cout << ans << endl;
}
int main()
{
	readData();
	xuly();
	system("pause");
	return 0;
}

