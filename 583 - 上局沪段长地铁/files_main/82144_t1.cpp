#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	ll t;
	cin>>t;
	while(t--){
		string a,b,ans;
		cin>>a>>b;
		ans=a;
		ll ji=0;
		for(int i=0;i<a.size();i++){
			if(b[ji]==a[i])ji++;
			else ans[i]='#';
		}
		cout<<ans<<endl;
	}
	return 0;
}
