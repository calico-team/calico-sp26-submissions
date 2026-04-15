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
	ll n;
	cin>>n;
	ll a[n+5],b[n+5];
	for(ll i=1; i<=n; i++)cin>>a[i],b[i]=a[i];
	ll x=0,x1=0;
	for(ll i=1; i<n; i++)x+=abs(a[i]-a[i+1]);
	sort(a+1,a+1+n);
	for(ll i=1; i<=n; i++)x1+=abs(b[i]-a[n/2+1]);
	if(x<x1){
		for(ll i=1; i<=n; i++)cout<<b[i]<<' ';
	}else{
		for(ll i=1; i<=n; i++)cout<<a[n/2+1]<<' ';
	}
	cout<<'\n';
}
 
int main(){
	// freopen("in.txt","w",stdout);
	// freopen("out.txt","r",stdin);
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll t=1;
	cin>>t;
	while(t--) solve();
}