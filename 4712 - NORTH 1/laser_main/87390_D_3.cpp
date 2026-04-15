#include<bits/stdc++.h>
#define randint rand()*rand()+rand()*rand()
#define lowbit(x) (x&(-x))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef __int128 i128;
typedef unsigned __int128 u128;
struct node{
	int x,y,idx;
}a[114514];
map<pair<int,int>,int>mp;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		mp.clear();
		int k,n,m,p,q;
		cin>>k>>n>>m>>p>>q;
		
		for(int i=1;i<=k;i++)cin>>a[i].x>>a[i].y,a[i].idx=i-1;
		int laserx=a[1].x,lasery=a[1].y;
		
		bool f=true;
		for(int i=1;i<=k;i++)
			if(!mp[make_pair(a[i].x,a[i].y)])mp[make_pair(a[i].x,a[i].y)]=i;
		
		for(int steps=1;steps<=n*m&&f;steps++){
			laserx+=q,lasery+=p;
			laserx%=n,lasery%=m;
			if(mp[make_pair(laserx,lasery)]>0)
				f=false,cout<<a[mp[make_pair(laserx,lasery)]].idx<<'\n';
		}
	}
	return 0;
}

