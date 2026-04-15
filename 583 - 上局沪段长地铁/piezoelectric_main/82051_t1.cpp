#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	ll t;
	cin>>t;
	while(t--){
		ll l,w,e,r;
		cin>>l>>w>>e>>r;
		ll p=(l+w)*2*r;
		if(e%p==0)cout<<e/p<<endl;
		else cout<<e/p+1<<endl;
	}
	return 0;
}
