#include <bits/stdc++.h>
using namespace std;

#define int long long
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
	int n;cin>>n;vector<vector<int>>r(n,vector<int>(n,0)),c(n,vector<int>(n,0));
	F(i,0,n){F(j,0,n){char c;cin>>c;r[i][j]=c=='#';}}
	F(i,0,n){F(j,0,n){char f;cin>>f;c[i][j]=f=='#';}}
	int mn=0,mx=0;
	F(j,0,n){
		int x=0,y=0;
		F(i,0,n)x+=r[j][i],y+=c[j][i];
		// check if we can overlap in this row.
		mn+=max(x,y);mx+=x*y;
	}
	cout<<mx<<" "<<mn<<"\n";

}

int32_t main(){int t;cin>>t;while(t--)solve();}
