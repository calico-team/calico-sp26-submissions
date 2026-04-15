// NAM MÔ A DI ĐÀ PHẬT

#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3","unroll-loops")

// defines
#define int long long
#define inf LLONG_MAX/20
#define fastio() ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define fr front
#define bk back
#define fi first
#define se second

// typedefs
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pi;
typedef pair<string, ll> psi;
typedef pair<ll, pi> pii;
typedef pair<pi, pi> piii;

signed main(){
    fastio();
    int t;
    cin>>t;
    while(t--){
		int r,c;
		cin>>r>>c;
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				int ans=(j+2*i)%5;
				cout<<ans<<" ";
			}
			cout<<'\n';
		}
	}
    return 0;
}
