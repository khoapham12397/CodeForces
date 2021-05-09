
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int n,k;
string vts[100005];
typedef struct node {
	bool isLeaf;
	char kt;
	vector<node*> childs;
	bool w;
	bool l;
}Node;
void build(Node* p , int t,int id) {
	for (int i = 0; i < p->childs.size(); i++) {
		if (p->childs[i]->kt == vts[id][t]) {
			if (t == vts[id].size() - 1) {
				p->childs[i]->isLeaf = true;
				return;
			}
			else {
				build(p->childs[i], t + 1, id);
				return;
			}
		}
	}
	Node*p1 = new Node();
	p1->kt = vts[id][t];
	p->childs.push_back(p1);
	if (t == vts[id].size() - 1) {
		p1->isLeaf = true;
	}
	else {
		p1->isLeaf = false;
		build(p1, t + 1, id);
	}
}
Node* root;
int calW(Node* p,int t) {
	
	if (p->childs.size() == 0) {
		if (t == 1) {
			return 1;
		}
		else return 0;
	}
	int ans;
	if (t == 0) ans = -1;
	else ans = 2;
	for (int i = 0; i < p->childs.size(); i++) {
		if (t == 0) {
			ans = max(ans, calW(p->childs[i],(t+1)%2));
		}
		else ans = min(ans, calW(p->childs[i],(t+1)%2));
	}
	return ans;
}
int calL(Node* p ,int t) {
	if (p->childs.size() == 0) {
		if (t == 0) return 1;
		return 0;
	}
	int ans;
	if (t == 0) ans = -1;
	else ans = 2;
	for (int i = 0; i < p->childs.size(); i++) {
		if (t == 0) ans = max(ans, calL(p->childs[i], (t + 1) % 2));
		else ans = min(ans, calL(p->childs[i], (t + 1) % 2));
	}
	return ans;
}
void solve() {
	root = new Node();
	root->isLeaf = false;

	cin >> n >> k;
	cin.ignore();
	for (int i = 0; i < n; i++) {
		string s; getline(cin, s);
		vts[i] = s;
		build(root, 0, i);
	}
	bool cdW,cdL;
	
	cdW=calW(root,0);
	cdL=calL(root,0);
	
	int st = cdL + cdW * 2;
	int ans;
	if (st == 0 || st==1) ans = 2;
	if (st == 3) ans = 1;
	if (st == 2) {
		if (k % 2 == 0) ans = 2;
		else ans = 1;
	}
	if (ans == 1) cout << "First" << endl;
	else cout << "Second" << endl;
}

int main()
{
	solve();
//	system("pause");
	return 0;
}

