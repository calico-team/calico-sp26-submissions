#include<bits/stdc++.h>
#define randint rand()*rand()+rand()*rand()
#define lowbit(x) (x&(-x))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef __int128 i128;
typedef unsigned __int128 u128;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		int l,w,e,r;
		cin>>l>>w>>e>>r;
		int c=2*w+2*l;
		cout<<(int)ceil(e/r/c)<<'\n';
	}
	return 0;
}
/*
3
5 3 128 2
10 5 300 10
2 2 400 5
*/
