#include <bits/stdc++.h>
using namespace std;

#define F(i,l,r) for(int i=l,i##_end=(int)r;i<i##_end;i++)
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
#define f first
#define s second
template<typename T,typename V>
ostream& operator<<(ostream& os, pair<T,V> t) {os<<"("<<t.first<<" "<<t.second<<")";return os;}
template<template<typename>class C,typename G>
ostream& operator<<(ostream&os,C<G>x){int f=0;os<<'{';for(auto&i:x)os<<(f++?", ":""),os<<i;os<<"}";return os;}
void _print(){cerr << "]\n";}
template<typename T,typename... V>
void _print(T t,V... v){cerr<<t;if(sizeof...(v))cerr<<", ";_print(v...);}
#ifdef DEBUG
#define dbg(x...) cerr<<"\e[91m"<<__func__<<":"<<__LINE__<<" ["<<#x<<"] = [";_print(x);cerr<<"\e[39m"<< endl;
#else
#define dbg(x...)
#endif

#define T pii

vector<pii>v;int add=0,n,m,k,a[4335][4335];pii p;

bool f(int d){
	F(i,0,2*(n+m+9)+3)F(j,0,2*(n+m+9)+3)a[i][j]=0;
	for(auto i:v){a[i.f][i.s]++;a[i.f+d][i.s]--;a[i.f][i.s+d]--;a[i.f+d][i.s+d]++;assert(min(i.f,i.s)>=1 and max(i.f,i.s)+d<=2*(n+m)+2);}
	F(i,0,2*(n+m+5)){
		F(j,0,2*(n+m+5)){
			a[i+1][j+1]+=a[i+1][j]+a[i][j+1]-a[i][j];
			if(a[i+1][j+1]>=k){p={i+1,j+1};return 1;}
		}
	}
	return 0;
}

void solve(){
	cin>>n>>m>>k;v.clear();vector<pii>g;p={-1,-1};add=0;
	F(i,0,n)F(j,0,m){char c;cin>>c;if(c=='-')v.emplace_back(i-j,i+j),g.emplace_back(i,j),add=min(add,i-j);}
	for(auto &i:v)i.f-=add;
	for(auto &i:v)i.f++,i.s++;
	int lo=0,hi=n+m+1;
	while(lo<hi-1){
		int m=(lo+hi)>>1ll;
		if(f(m))hi=m;
		else lo=m;
	}
	auto e=f(hi);
	dbg(hi);
	F(i,0,v.size()){if(v[i].f<=p.f and p.f<v[i].f+hi and v[i].s<=p.s and p.s<v[i].s+hi and k>=1){cout<<g[i].f<<" "<<g[i].s<<"\n";k--;}}
	assert(k==0);
}
int32_t main(){cin.tie(0)->sync_with_stdio(false);int t;cin>>t;while(t--)solve();}
