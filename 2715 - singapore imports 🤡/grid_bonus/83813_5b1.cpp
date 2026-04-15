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
		int n;
		cin>>n;
		vector<int> v(n);
		for(int i=0;i<n;i++){
			cin>>v[i];
		}
		if(n<=2){
			for(int i=0;i<n;i++){
				cout<<v[i]<<" ";
			}
			cout<<'\n';
			continue;
		}
		vector<int> ans=v;
		for(int i=1;i<n-1;i++){
			vector<int> cur(3);
			cur[0]=v[i-1];
			cur[1]=v[i];
			cur[2]=v[i+1];
			sort(cur.begin(),cur.end());
			ans[i]=cur[1];
		}
		for(int i=0;i<n;i++){
			cout<<ans[i]<<" ";
		}
		cout<<'\n';
	}
    return 0;
}
