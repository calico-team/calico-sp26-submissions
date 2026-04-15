#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t,l,w,e,r,ans;
	cin>>t;
	for(int i=0;i<t;i++){
		ans=0;
		cin>>l>>w>>e>>r;
		ans+=e/((l+w)*r);
		cout<<ans/2<<endl;
	}
	return 0;
}
