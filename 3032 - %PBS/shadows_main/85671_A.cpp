#include<bits/stdc++.h>
using namespace std;
#define sc cerr
#define qlog(x) {sc<<#x<<" = "<<(x)<<"\n";}
#define rep(i,l,r) for(ll i=(l);i<=(r);i++)
#define irep(i,l,r) for(ll i=(l);i>=(r);i--)
#define qloga(a,l,r) {sc<<#a<<" : "; rep(I,l,r){sc<<(a)[I]<<" ";}sc<<"\n";}
#define qlogSTL(a) {sc<<#a<<" : "; for(const auto &I:(a)){sc<<(I)<<" ";}sc<<"\n";}
typedef long long ll;
typedef unsigned long long ull;

signed main(){
	ios::sync_with_stdio(0); cin.tie(0);

	int T; cin>>T;
	while(T--){
		int n;
		cin>>n;
		vector<string> s(n),t(n);
		for(auto &x:s)cin>>x;
		for(auto &x:t)cin>>x;

		ll ans1=0,ans2=0;
		for(int i=0;i<n;i++){
			ll cnt1=0, cnt2=0;
			for(char x:s[i])if(x=='#')cnt1++;
			for(char x:t[i])if(x=='#')cnt2++;
			ans1+=cnt1*cnt2;
			ans2+=max(cnt1,cnt2);
		}
		cout<<ans1<<" "<<ans2<<"\n";
	};
}

