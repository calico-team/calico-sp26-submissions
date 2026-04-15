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
		int n,p,r,k;
		cin>>n>>p>>r>>k;
		vector<int> e(n);
		for(int i=0;i<n;i++){
			cin>>e[i];
		}
		bool check=1;
		for(int i=0;i<n;i++){
			p-=e[i];
			if(p<0){
				check=0;
				break;
			}
			if(((i+1)%k)==0){
				p+=r;
			}
		}
		if(check) cout<<"nah i'd win"<<'\n';
		else cout<<"nah i'd lose"<<'\n';
	}
    return 0;
}
