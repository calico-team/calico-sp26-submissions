#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll T;
	cin>>T;
	while(T--){
		ll n,p,r,k;
		cin>>n>>p>>r>>k;
		ll cnt=0,ans=1;
		for(ll i=1;i<=n;i++){
			ll a;
			cin>>a;
			if(ans==0)continue;
			p-=a;
			if(p<0)ans=0;
			if(ans==0)continue;
			cnt++;
			if(cnt>=k){
				p+=r;
				cnt=0;
			}
		}
		if(ans)cout<<"nah i'd win"<<endl;
		else cout<<"nah i'd lose"<<endl;
	}
	return 0;
}
