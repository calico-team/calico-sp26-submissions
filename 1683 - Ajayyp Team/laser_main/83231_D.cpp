#include "bits/stdc++.h"
using namespace std;
#define mod 1000000007
#define ll long long
#define ff first
#define ss second
#define pb push_back
#define N 24
#define maxn 200005
#define INF (ll)1e9

void solve(){
	ll k,n,m,p,q;
	cin>>k>>n>>m>>p>>q;
	map<ll,map<ll,ll> > mm;
	ll x,y;
	for(ll i=0; i<k; i++){
		ll a,b;
		cin>>a>>b;
		if(i==0)x=a,y=b;
		mm[a][b]=i+1;
	}
	while(true){
		x=(x+q)%n;
		y=(y+p)%m;
		if(mm[x][y]){
			cout<<mm[x][y]-1<<'\n';
			return;
		}
	}
}
 
int main(){
	// freopen("in.txt","w",stdout);
	// freopen("out.txt","r",stdin);
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll t=1;
	cin>>t;
	while(t--) solve();
}