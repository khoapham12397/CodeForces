#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int,int> ii;
int n,a[510],b[510];
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	vector<ii> vta,vtb;
	int ght=0;
	if(n%2==1){
		if(a[(n+1)/2] != b[(n+1)/2]) {cout<<"No"<<endl; return;}
		ght= (n-1)/2;
		
	}else ght= n/2;

	for(int i=1;i<=ght;i++){
		vta.push_back(ii(min(a[i],a[n+1-i]), max(a[i],a[n+1-i])));
		vtb.push_back(ii(min(b[i],b[n+1-i]), max(b[i],b[n+1-i])));
	}
	sort(vta.begin(), vta.end()); sort(vtb.begin(),vtb.end());
	for(int i=0;i<vta.size();i++){
		if(vta[i]!=vtb[i]) {cout<<"No"<<endl; return;}
	}
	cout<<"Yes"<<endl;
}
int main(){

	int t;cin>>t;
	while(t--) solve();
	return 0;
}