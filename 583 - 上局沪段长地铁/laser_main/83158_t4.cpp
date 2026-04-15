#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll k,n,m,p,q,x[1001],y[1001];
ll jz[1001][1001];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	ll t;
	cin>>t;
	while(t--){
		cin>>k>>n>>m>>p>>q;
		for(int i=0;i<n;i++)for(int j=0;j<m;j++)jz[i][j]=0;
		for(int i=1;i<=k;i++){
			cin>>x[i]>>y[i];
			jz[x[i]][y[i]]=i;
		}
		ll jx=x[1],jy=y[1];
		while(1){
			jx+=q;jy+=p;
			jx%=n;jy%=m;
			if(jz[jx][jy]){
				cout<<jz[jx][jy]-1<<endl;
				break;
			}
		}
	}
	return 0;
}
