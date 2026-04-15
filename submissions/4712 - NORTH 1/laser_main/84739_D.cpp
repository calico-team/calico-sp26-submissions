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
map<pair<int,int>,vector<int> >mp;
bool cmp(node a,node b){
	return a.x==b.x?a.y<b.y:a.x<b.x;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		int k,n,m,p,q;
		cin>>k>>n>>m>>p>>q;
		
		for(int i=1;i<=k;i++)cin>>a[i].x>>a[i].y,a[i].idx=i-1;
		int laserx=a[1].x,lasery=a[1].y;
		sort(a+1,a+1+k,cmp);
		
		bool f=true;
		for(int i=1;i<=k&&f;i++){
			if(a[i].x>laserx&&a[i].y>lasery&&(a[i].x-laserx)%q==0&&(a[i].y-lasery)%p==0)
				f=false,cout<<a[i].idx<<'\n';
			ll dx=a[i].x/q,dy=a[i].y/p;
			mp[make_pair(a[i].x-min(dx,dy)*q,a[i].y-min(dx,dy)*p)].push_back(i);
		}
		while(f){
			ll dx=ceil(1.0*(n-laserx)/q),dy=ceil(1.0*(m-lasery)/p);
			laserx=(laserx+min(dx,dy)*q)%n;
			lasery=(lasery+min(dx,dy)*p)%m;
//			printf("x:%d y:%d\n",laserx,lasery);
			if(mp[make_pair(laserx,lasery)].size()>0)
				f=false,cout<<a[mp[make_pair(laserx,lasery)][0]].idx<<'\n';
		}
	}
	return 0;
}

