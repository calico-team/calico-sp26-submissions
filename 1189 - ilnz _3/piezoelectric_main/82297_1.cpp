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
	int l,w,e,r;cin>>l>>w>>e>>r;int x=r*(w+l)*2;
	dbg(x);
	cout<<(e/x+(!!(e%x)))<<"\n";
}
int32_t main(){int t;cin>>t;while(t--)solve();}
