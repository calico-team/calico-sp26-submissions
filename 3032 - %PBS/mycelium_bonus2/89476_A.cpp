#include<bits/stdc++.h>
using namespace std;
#define sc cerr
#define qlog(x) {sc<<#x<<" = "<<(x)<<"\n";}
#define rep(i,l,r) for(ll i=(l);i<=(r);i++)
#define irep(i,l,r) for(ll i=(l);i>=(r);i--)
#define qloga(a,l,r) {sc<<#a<<" : "; rep(I,l,r){sc<<(a)[I]<<" ";}sc<<"\n";}
#define qlogSTL(a) {sc<<#a<<" : "; for(const auto &I:(a)){sc<<(I)<<" ";}sc<<"\n";}
typedef long long ll;
typedef unsigned long long ull;

constexpr int N=2e4+10, C=N/2;
bitset<N> mp[N];
bitset<N> ext[N];
void spread(vector<pair<int,int>> &A,int val){
	vector<pair<int,int>> nw;
	nw.reserve(A.size());

	for(const auto &X:A){
		int x=X.first, y=X.second;

		if(!ext[x+1][y]){
			mp[x+1][y]=val;
			ext[x+1][y]=1;
			nw.emplace_back(x+1,y);
		}
		if(!ext[x-1][y]){
			mp[x-1][y]=val;
			ext[x-1][y]=1;
			nw.emplace_back(x-1,y);
		}
		if(!ext[x][y+1]){
			mp[x][y+1]=val;
			ext[x][y+1]=1;
			nw.emplace_back(x,y+1);
		}
		if(!ext[x][y-1]){
			mp[x][y-1]=val;
			ext[x][y-1]=1;
			nw.emplace_back(x,y-1);
		}
	}
	nw.swap(A);
}

ll solve(){
	int gx,gy, mx,my;
	cin>>gx>>gy>>mx>>my;

	for(int i=0;i<N;i++)mp[i].reset();
	for(int i=0;i<N;i++)ext[i].reset();
	ext[gx+C][gy+C]=1;
	ext[mx+C][my+C]=1;
	mp[gx+C][gy+C]=0;
	mp[mx+C][my+C]=1;
	vector<pair<int,int>> G{{gx+C,gy+C}},M{{mx+C,my+C}};
	while(M.size()){
		spread(G,0);
		spread(G,0);
		spread(G,0);
		spread(M,1);
		spread(G,0);
		spread(G,0);
		spread(G,0);
		spread(G,0);
		spread(M,1);
	}
	ll ans=0;
	for(int i=0;i<N;i++)for(int j=0;j<N;j++)if(mp[i][j]==1)ans++;
	return ans;
}

signed main(){
	ios::sync_with_stdio(0); cin.tie(0);

	int T;
	cin>>T;
	while(T--)cout<<solve()<<"\n";
}
