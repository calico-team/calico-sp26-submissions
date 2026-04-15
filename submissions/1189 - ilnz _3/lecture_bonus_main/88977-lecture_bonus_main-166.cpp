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

vector<pii>v;int add=0,n,m,k,a[4335][4335],b[4336][4336];pii p;vector<int>w;

bool f(int d){
	F(i,0,(n+m+9)+3)F(j,0,(n+m+9)+3)a[i][j]=0;
	for(auto i:v){a[i.f][i.s]++;if(i.f+d<=n+m+4)a[i.f+d][i.s]--;if(i.s+d<=n+m+4)a[i.f][i.s+d]--;if(max(i.f+d,i.s+d)<=n+m+4)a[i.f+d][i.s+d]++;}
	F(i,0,(n+m+5)){
		F(j,0,(n+m+5)){
			a[i+1][j+1]+=a[i+1][j]+a[i][j+1]-a[i][j];
			if(a[i+1][j+1]>=k){p={i+1,j+1};return 1;}
		}
	}
	return 0;
}

void solve(){
	cin>>n>>m>>k;v.clear();w.clear();vector<pii>g;p={-1,-1};add=0;
	F(i,0,n)F(j,0,m){char c;cin>>c;if(c=='-')v.emplace_back(i-j,i+j),g.emplace_back(i,j),add=min(add,i-j),w.push_back(min(j,m-j-1));}
	for(auto &i:v)i.f-=add;
	for(auto &i:v)i.f++,i.s++;
	int lo=0,hi=n+m+1;
	while(lo<hi-1){
		int m=(lo+hi)>>1ll;
		if(f(m))hi=m;
		else lo=m;
	}
	dbg(hi);
	auto e=f(hi);
	int l=-1,r=m;
	vector<pair<int,pii>>po;F(i,0,v.size())po.emplace_back(w[i],v[i]);
	while(l<r-1){
		int m=(l+r)>>1ll;
		v.clear();for(auto i:po)if(i.f<=m)v.push_back(i.s);
		if(f(hi))r=m;
		else l=m;
	}
	sort(all(po));
	while(po.size() and po.back().f>r)po.pop_back();
	F(i,0,(n+m+9)+3)F(j,0,(n+m+9)+3)b[i][j]=a[i][j]=0;
	int d=hi;
	for(auto x:po){pii i=x.s;int w=x.f;a[i.f][i.s]+=w;a[i.f+d][i.s]-=w;a[i.f][i.s+d]-=w;a[i.f+d][i.s+d]-=w;b[i.f][i.s]++;b[i.f][i.s+d]--;b[i.f+d][i.s]--;b[i.f+d][i.s+d]++;}
	pii p={-1,-1};int ans=1e9;
	F(i,0,(n+m+5)){
		F(j,0,(n+m+5)){
			a[i+1][j+1]+=a[i+1][j]+a[i][j+1]-a[i][j];
			b[i+1][j+1]+=b[i+1][j]+b[i][j+1]-b[i][j];
			if(b[i+1][j+1]>=k){
				int o=a[i+1][j+1]-(b[i+1][j+1]-k)*r;
				if(o<ans){ans=o;p={i+1,j+1};}
			}
		}
	}
	dbg(po);
	dbg(p);
	vector<pii>x;
	F(i,0,po.size()){if(po[i].s.f<=p.f and p.f<po[i].s.f+hi and po[i].s.s<=p.s and p.s<po[i].s.s+hi and k>=1){int e=po[i].s.f+po[i].s.s-2+add;e/=2;x.emplace_back(e,po[i].s.s-e-1);}}
	dbg(x);
	sort(all(x),[&](pii i,pii j){return min(i.s,m-i.s-1)<min(j.s,m-j.s-1);});
	F(i,0,k){cout<<x[i].f<<" "<<x[i].s<<"\n";}
}
int32_t main(){cin.tie(0)->sync_with_stdio(false);int t;cin>>t;while(t--)solve();}
