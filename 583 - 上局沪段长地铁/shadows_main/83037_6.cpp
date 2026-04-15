#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
ll kh[1005][1005],kl[1005][1005],jkl[1005],kkl[1005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll T;
	cin>>T;
	while(T--){
		cin>>n;
		for(ll i=1;i<=n;i++){
			kkl[i]=0;
			for(ll o=1;o<=n;o++){
				char c;
				cin>>c;
				if(c=='#')kh[i][o]=1;
				else kh[i][o]=0;
				kkl[i]+=kh[i][o];
			}
		}
		ll ansd=0,ansx=0;
		for(ll i=1;i<=n;i++){
			jkl[i]=0;
			for(ll o=1;o<=n;o++){
				char c;
				cin>>c;
				if(c=='#')kl[i][o]=1;
				else kl[i][o]=0;
				jkl[i]+=kl[i][o];
			}
			ansx+=max(jkl[i],kkl[i]);
		}
		for(ll i=1;i<=n;i++){
			for(ll o=1;o<=n;o++){
				if(kh[i][o]==1)ansd+=jkl[i];
			}
		}
		cout<<ansd<<" "<<ansx<<endl;
	}
	return 0;
}
