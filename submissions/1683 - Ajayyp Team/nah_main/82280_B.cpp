#include "bits/stdc++.h"
using namespace std;
#define mod 1000000007
#define ll long long
#define ff first
#define ss second
#define pb push_back
#define N 24
#define maxn 200005
#define INF (int)1e9

void solve(){
	int n,p,r,k;
	cin>>n>>p>>r>>k;
	int a[n+5];
	for(int i=1; i<=n; i++)cin>>a[i];
	for(int i=1; i<=n; i++){
		p-=a[i];
		if(p<0){
			cout<<"nah i’d lose\n";
			return;
		}
		if(i%k==0)p+=r;
	}
	cout<<"nah i’d win\n";
}
 
int main(){
	// freopen("in.txt","w",stdout);
	// freopen("out.txt","r",stdin);
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll t=1;
	cin>>t;
	while(t--) solve();
}