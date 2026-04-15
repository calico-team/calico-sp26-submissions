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

constexpr int N=20, V=400;
int n,m;
char mp[N][N];

int a[N][N],id,S,T;

vector<int> to[V];

void addedge(int u,int v){
	if(v==-1)v=T;
	to[u].push_back(v);
}

void solve(){
	for(int u=0;u<V;u++)to[u].clear();

	cin>>n>>m;
	rep(i,1,n)rep(j,1,m)cin>>mp[i][j];

	memset(a,-1,sizeof(mp));
	rep(i,1,n)rep(j,1,m)a[i][j]=++id;
	S=++id;
	T=++id;

	rep(i,1,n)rep(j,1,m){
		char x=mp[i][j];
		if(x=='<')addedge(a[i][j],a[i][j-1]);
		if(x=='>')addedge(a[i][j],a[i][j+1]);
		if(x=='^')addedge(a[i][j],a[i-1][j]);
		if(x=='v')addedge(a[i][j],a[i+1][j]);
		if(x=='S'){
			if(mp[i-1][j]!='v' && mp[i-1][j]!='.')addedge(a[i][j],a[i-1][j]);
			if(mp[i+1][j]!='^' && mp[i+1][j]!='.')addedge(a[i][j],a[i+1][j]);
			if(mp[i][j-1]!='>' && mp[i][j-1]!='.')addedge(a[i][j],a[i][j-1]);
			if(mp[i][j+1]!='<' && mp[i][j+1]!='.')addedge(a[i][j],a[i][j+1]);
		}
	}
	addedge(S,a[1][1]);

	vector<int> d(T+1);
	rep(u,1,T)for(int v:to[u])d[v]++;

	vector<ll> p(T+1);
	p[S]=3656158440062976LL;
	vector<int> stk{S};
	while(stk.size()){
		int u=stk.back(); stk.pop_back();
		int s=to[u].size();

		for(int v:to[u]){
			p[v]+=p[u]/s;
			if(!--d[v])stk.push_back(v);
		}
	}
	if(p[T]==0)cout<<"0 1\n";
	else{
		ll g=__gcd(p[T],p[S]);
		p[T]/=g;
		p[S]/=g;
		cout<<p[T]<<" "<<p[S]<<"\n";
	}
}

signed main(){
	ios::sync_with_stdio(0); cin.tie(0);

	int TTT; cin>>TTT;
	while(TTT--)solve();
}
