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

// what atrocious code
void solve(){
	int xg,yg,xm,ym;
	cin>>xg>>yg>>xm>>ym;
	xg+=100;
	yg+=100;
	xm+=100;
	ym+=100;
	// int grid[200][200];
	// memset(grid,-1,sizeof(grid));
	vector<vector<int>> grid(200,vector<int>(200,-1)); // shoutout thomas apparently idk how to declare 2d vector
	// -1 null, 0 grass, 1 my
	grid[xg][yg]=0;
	grid[xm][ym]=1;
	int dx[4]={-1,1,0,0};
	int dy[4]={0,0,-1,1};
	int last=0;
	for(int t=1;t<=1000;t++){
		vector<vector<int>> cur=grid;
		bool diff=0;
		if(t%2==0){
			for(int i=0;i<200;i++){
				for(int j=0;j<200;j++){
					if(grid[i][j]==-1){
						for(int k=0;k<4;k++){
							int i1=i+dx[k];
							int j1=j+dy[k];
							if(i1>=0&&i1<200&&j1>=0&&j1<200){
								if(grid[i1][j1]==0){
									cur[i][j]=0;
									diff=1;
									break;
								}
							}
						}
					}
				}
			}
		}
		if(t%7==0){
			for(int i=0;i<200;i++){
				for(int j=0;j<200;j++){
					if(grid[i][j]==-1&&cur[i][j]!=0){
						for(int k=0;k<4;k++){
							int i1=i+dx[k];
							int j1=j+dy[k];
							if(i1>=0&&i1<200&&j1>=0&&j1<200){
								if(grid[i1][j1]==1){
									cur[i][j]=1;
									diff=1;
									break;
								}
							}
						}
					}
				}
			}
		}
	grid=cur;
	if(diff) last=t;
	if(t-last>=10) break;
}
	int ans=0;
	for(int i=0;i<200;i++){
		for(int j=0;j<200;j++){
			if(grid[i][j]==1) ans++;
		}
	}
	cout<<ans<<'\n';	
}

signed main(){
    fastio();
    int t;
    cin>>t;
    while(t--){
		solve();
	}
    return 0;
}
