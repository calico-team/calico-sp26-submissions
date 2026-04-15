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
	int n,m;
	cin>>n>>m;
	int a[n+5][m+5];
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			a[i][j]=(i*2+j)%5;
		}
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++)cout<<a[i][j]<<' ';
		cout<<'\n';
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