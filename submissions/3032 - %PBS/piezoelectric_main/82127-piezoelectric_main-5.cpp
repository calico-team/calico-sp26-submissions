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
	while(T--)cout<<[&](){
		ll L,W,E,R;
		cin>>L>>W>>E>>R;
		return E/(L+L+W+W)/R;
	}()<<"\n";
}

