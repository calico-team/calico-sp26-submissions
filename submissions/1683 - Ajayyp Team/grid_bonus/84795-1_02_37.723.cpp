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
	sort(b+1,b+1+n);
	ll x=b[n/2+1];
	pair<ll,bool> dp[n+5][2];
	for(ll i=1; i<=n; i++)for(ll j=0; j<2; j++)dp[i][j]={1e9,0};
	dp[1][0]={0,0};
	dp[1][1]={abs(a[1]-x),0};
	for(ll i=2; i<=n; i++){
		if(abs(a[i]-a[i-1])+dp[i-1][0].ff<abs(a[i]-x)+dp[i-1][1].ff){
			dp[i][0]={abs(a[i]-a[i-1])+dp[i-1][0].ff,0};
		}else{
			dp[i][0]={abs(a[i]-x)+dp[i-1][1].ff,1};
		}
		if(abs(x-a[i])+abs(x-a[i-1])+dp[i-1][0].ff<abs(x-a[i])+dp[i-1][1].ff){
			dp[i][1]={abs(x-a[i])+abs(x-a[i-1])+dp[i-1][0].ff,0};
		}else{
			dp[i][1]={abs(x-a[i])+dp[i-1][1].ff,1};
		}
	}
	ll cur=1;
	if(dp[n][0].ff<dp[n][1].ff)cur=0;
	vector<ll> ans;
	for(ll i=n; i>=1; i--){
		if(cur)ans.pb(x);
		else ans.pb(a[i]);
		// cout<<i<<' '<<dp[i][cur].ff<<'\n';
		cur=dp[i][cur].ss;
	}
	reverse(ans.begin(),ans.end());
	for(ll i=0; i<ans.size(); i++)cout<<ans[i]<<' ';
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