#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,jfz[21][21],jfm[21][21],vis[21][21];
char c[20][20];
void dfs(ll x,ll y){
	if(x>n||x<1||y<1||y>m){
		jfz[x][y]=1;jfm[x][y]=1;
		return;
	}
	if(c[x][y]=='X')return;
	if(vis[x][y])return;
	vis[x][y]=1;
	if(c[x][y]=='v'){
		dfs(x+1,y);
		jfz[x][y]=jfz[x+1][y];
		jfm[x][y]=jfm[x+1][y];
	}
	if(c[x][y]=='^'){
		dfs(x-1,y);
		jfz[x][y]=jfz[x-1][y];
		jfm[x][y]=jfm[x-1][y];
	}
	if(c[x][y]=='>'){
		dfs(x,y+1);
		jfz[x][y]=jfz[x][y+1];
		jfm[x][y]=jfm[x][y+1];
	}
	if(c[x][y]=='<'){
		dfs(x,y-1);
		jfz[x][y]=jfz[x][y-1];
		jfm[x][y]=jfm[x][y-1];
	}
	if(c[x][y]=='S'){
		ll jzs=0,fz,fm;
		jfz[x][y]=0;jfm[x][y]=1;
		if(c[x-1][y]!='v'&&c[x-1][y]!='.'){
			jzs++;dfs(x-1,y);
			fz=jfz[x-1][y];fm=jfm[x-1][y];
			if(fz!=0){
				ll ng=fm*jfm[x][y]/__gcd(fm,jfm[x][y]);
				jfz[x][y]=fz*(ng/fm)+jfz[x][y]*(ng/jfm[x][y]);
				jfm[x][y]=ng;
			}
		}
		if(c[x+1][y]!='^'&&c[x+1][y]!='.'){
			jzs++;dfs(x+1,y);
			fz=jfz[x+1][y];fm=jfm[x+1][y];
			if(fz!=0){
				ll ng=fm*jfm[x][y]/__gcd(fm,jfm[x][y]);
				jfz[x][y]=fz*(ng/fm)+jfz[x][y]*(ng/jfm[x][y]);
				jfm[x][y]=ng;
			}
		}
		if(c[x][y-1]!='>'&&c[x][y-1]!='.'){
			jzs++;dfs(x,y-1);
			fz=jfz[x][y-1];fm=jfm[x][y-1];
			if(fz!=0){
				ll ng=fm*jfm[x][y]/__gcd(fm,jfm[x][y]);
				jfz[x][y]=fz*(ng/fm)+jfz[x][y]*(ng/jfm[x][y]);
				jfm[x][y]=ng;
			}
		}
		if(c[x][y+1]!='<'&&c[x][y+1]!='.'){
			jzs++;dfs(x,y+1);
			fz=jfz[x][y+1];fm=jfm[x][y+1];
			if(fz!=0){
				ll ng=fm*jfm[x][y]/__gcd(fm,jfm[x][y]);
				jfz[x][y]=fz*(ng/fm)+jfz[x][y]*(ng/jfm[x][y]);
				jfm[x][y]=ng;
			}
		}
		jfm[x][y]*=jzs;
		ll jg=__gcd(jfz[x][y],jfm[x][y]);
		jfz[x][y]/=jg;jfm[x][y]/=jg;
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	ll t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>c[i][j];
				jfz[i][j]=0;jfm[i][j]=1;
				vis[i][j]=0;
			}
		}
		dfs(1,1);
		cout<<jfz[1][1]<<" "<<jfm[1][1]<<endl;
	}
	return 0;
}
