#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MX=2002;
int cnt[MX][MX];
int prefix[MX][MX];
char grid[1002][1002];
int a[1000002],b[1000002],c[1000002],d[1000002];
void solve(){
	int n,m,k;
	cin>>n>> m>>k;
	for(int i=0; i<n; i++){
		for(int j=0;j<m;j++)cin>>grid[i][j];
	}
	memset(cnt,0,sizeof(cnt));
	memset(prefix,0,sizeof(prefix));
	int seats=0;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(grid[i][j]=='-'){
				a[seats]=i;
				b[seats]=j;
				c[seats]=i+j;
				d[seats]=i-j+m-1;
				seats++;
				cnt[i+j][i-j+m-1]++;
			}
		}
	}	
	for(int i=0; i<n+m-1; i++){
		for(int j=0; j<n+m-1; j++){
			prefix[i+1][j+1]=cnt[i][j]+prefix[i][j+1]+prefix[i+1][j]-prefix[i][j];
		}
	}
	int L=0,R=n+m-2;
	int bestX=0,bestY=0;
	while(L<R){
		int mid=(L+R)/2;
		int X=-1,Y=-1;
		bool flg=0;
		for(int i=0; i+mid<n+m-1 && !flg; i++){
			int tmp=i+mid;
			for(int j=0; j+mid<n+m-1; j++){
				int tmp2=j+mid;
				int sum=prefix[tmp+1][tmp2+1]-prefix[i][tmp2+1]-prefix[tmp+1][j]+prefix[i][j];
				if(sum >=k){
					X=i;
					Y=j;
					flg=1;
					break;
				}
			}
		}
		if(flg){
			R=mid;
			bestX=X;
			bestY=Y;
		}
		else{
			L=mid+1;
		}
	}
	for(int i=0; i+L<n+m-1; i++){
		bool done=false;
		int tmp=i+L;
		for(int j=0; j+L<n+m-1; j++){
			int tmp2=j+L;
			int sum=prefix[tmp+1][tmp2+1]-prefix[i][tmp2+1]-prefix[tmp+1][j]+prefix[i][j];
			if(sum >=k){
				bestX=i;
				bestY=j;
				done=true;
				break;
			}
		}
		if(done) break;
	}
	int ans=0;
	for(int i=0; i<seats; i++){
		if(ans >= k)break;
		if(bestX<=c[i] and c[i] <= bestX+L and bestY<=d[i] and d[i]<= bestY+L){
			cout<< a[i]<<" "<<b[i]<<'\n';
			ans++;
		}
	}
					
}
main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >>t;
	while(t--)solve();
}



