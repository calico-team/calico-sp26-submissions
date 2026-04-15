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

struct LazySeg { 
	const T ID{0,0}; T cmb(T a, T b) { return max(a,b); }
	vector<T>seg;vector<int>lazy;int SZ;
	LazySeg(int x){SZ=1;while(SZ<=x)SZ*=2;
	seg.assign(2*SZ,{0,0});lazy.assign(2*SZ,0);F(i,SZ,2*SZ)seg[i].s=i-SZ;build();}
	void push(int ind, int L, int R) { /// modify values for current node
		seg[ind].f += lazy[ind]; // dependent on operation
		if (L != R) for(int i=0;i<2;i++) lazy[2*ind+i] += lazy[ind]; /// prop to children
		lazy[ind] = 0; 
	} // recalc values for current node
	void pull(int ind){seg[ind]=cmb(seg[2*ind],seg[2*ind+1]);}
	void build() { for(int i=SZ-1;i>=1;i--) pull(i); }
	void upd(int lo,int hi,int inc,int ind,int L, int R) {
		push(ind,L,R); if (hi < L || R < lo) return;
		if (lo <= L && R <= hi) { 
			lazy[ind] = inc; push(ind,L,R); return; }
		int M = (L+R)/2; upd(lo,hi,inc,2*ind,L,M); 
		upd(lo,hi,inc,2*ind+1,M+1,R); pull(ind);
	}
	T query(int lo, int hi, int ind, int L, int R) {
		push(ind,L,R); if (lo > R || L > hi) return ID;
		if (lo <= L && R <= hi) return seg[ind];
		int M = (L+R)/2; return cmb(query(lo,hi,2*ind,L,M),
			query(lo,hi,2*ind+1,M+1,R));
	}
	void upd(int l,int r,int v){upd(l,r,v,1,0,SZ-1);}
	T query(int l,int r){return query(l,r,1,0,SZ-1);}
};

vector<pii>v;int add=0,n,m,k;pii p;

bool f(int d){
	LazySeg t(2*(n+m)+20);
	vector<pair<pii,int>>s;for(auto i:v){s.emplace_back(i,1);s.emplace_back(make_pair(i.f+d,i.s),-1);}
	sort(all(s));
	for(auto i:s){
		t.upd(i.f.s,i.f.s+d-1,i.s);pii x;
		if((x=t.query(0,2*(n+m)+19)).f>=k){p={i.f.f,x.s};return 1;}
	}
	return 0;
}

void solve(){
	cin>>n>>m>>k;v.clear();vector<pii>g;
	F(i,0,n)F(j,0,m){char c;cin>>c;if(c=='-')v.emplace_back(i-j,i+j),g.emplace_back(i,j);}
	int lo=0,hi=n+m;
	while(lo<hi-1){
		int m=(lo+hi)>>1;
		if(f(m))hi=m;
		else lo=m;
	}
	auto e=f(hi);
	F(i,0,v.size()){if(max(abs(v[i].f-p.f),abs(v[i].s-p.s))<=hi and k>=1){cout<<g[i].f<<" "<<g[i].s<<"\n";k--;}}
}
int32_t main(){cin.tie(0)->sync_with_stdio(false);int t;cin>>t;while(t--)solve();}
