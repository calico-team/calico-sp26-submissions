#include <bits/stdc++.h>
using namespace std;

#define F(i,l,r) for(int i=l,i##_end=(int)r;i<i##_end;i++)
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
#define f first
#define s second
 
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

void solve(){
	int n;cin>>n;vector<int>r(n),c(n);;
	F(i,0,n){F(j,0,n){char c;cin>>c;r[i]+=c=='#';}}
	F(i,0,n){F(j,0,n){char f;cin>>f;c[i]+=f=='#';}}
	int mn=0,mx=0;
	F(j,0,n){
		int x=r[j],y=c[j];
		// check if we can overlap in this row.
		mn+=max(x,y);mx+=x*y;
	}
	cout<<mx<<" "<<mn<<"\n";

}

int32_t main(){cin.tie(0)->sync_with_stdio(false);int t;cin>>t;while(t--)solve();}
