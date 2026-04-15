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
	int n,p,r,k;cin>>n>>p>>r>>k;
	vector<int>e(n);F(i,0,n)cin>>e[i];
	F(i,0,n){if((i%k)==0 and i!=0)p+=r;if(p<e[i]){cout<<"nah i'd lose\n";return;}p-=e[i];}
	cout<<"nah i'd win\n";
}

int32_t main(){int t;cin>>t;while(t--)solve();}
