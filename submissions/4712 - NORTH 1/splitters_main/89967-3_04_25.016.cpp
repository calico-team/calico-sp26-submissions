#include<bits/stdc++.h>
#define randint rand()*rand()+rand()*rand()
#define lowbit(x) (x&(-x))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef __int128 i128;
typedef unsigned __int128 u128;
ll gcd(ll a,ll b){
	return b==0?a:gcd(b,a%b);
}
struct frac{
	ll num,den;
	frac(ll a,ll b){
		num=a,den=b;
	}
};
frac operator+(const frac &a,const frac &b){
	frac ans(0,1);
	ans.den=a.den/gcd(a.den,b.den)*b.den;
	ans.num=a.num*(ans.den/a.den)+b.num*(ans.den/b.den);
	ll g=gcd(ans.den,ans.num);
	ans.den/=g;ans.num/=g;
	return ans;
}
frac operator*(const frac &a,const frac &b){
	frac ans(0,0);
	ans.num=a.num*b.num;
	ans.den=a.den*b.den;
	ll g=gcd(ans.den,ans.num);
	ans.den/=g;ans.num/=g;
	return ans;
}
frac fr(ll a,ll b){
	frac ans(a,b);
	return ans;
}
struct node{
	ll x,y;frac p;
};
char mp[1145][1419];int n,m;
frac bfs(){
	frac ans(1,1);
	queue<node> q;
	q.push({1,1,ans});
	ans.num=0;
	while(q.size()){
		node f=q.front();
		q.pop();
		if(f.x<1||n<f.x||f.y<1||m<f.y){
			ans=ans+f.p;continue;
		}
		if(mp[f.x][f.y]=='S'){
			int cnt=0;
			if(mp[f.x-1][f.y]!='v'&&mp[f.x-1][f.y]!='.')cnt++;
			if(mp[f.x][f.y-1]!='>'&&mp[f.x][f.y-1]!='.')cnt++;
			if(mp[f.x][f.y+1]!='<'&&mp[f.x][f.y+1]!='.')cnt++;
			if(mp[f.x+1][f.y]!='^'&&mp[f.x+1][f.y]!='.')cnt++;
			
			frac tmp=f.p*fr(1,cnt);
			if(mp[f.x-1][f.y]!='v')q.push({f.x-1,f.y,tmp});
			if(mp[f.x][f.y-1]!='>')q.push({f.x,f.y-1,tmp});
			if(mp[f.x][f.y+1]!='<')q.push({f.x,f.y+1,tmp});
			if(mp[f.x+1][f.y]!='^')q.push({f.x+1,f.y,tmp});
			continue;
		}
		if(mp[f.x][f.y]=='v')q.push({f.x+1,f.y,f.p});
		if(mp[f.x][f.y]=='^')q.push({f.x-1,f.y,f.p});
		if(mp[f.x][f.y]=='>')q.push({f.x,f.y+1,f.p});
		if(mp[f.x][f.y]=='<')q.push({f.x,f.y-1,f.p});
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		cin>>n>>m;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				cin>>mp[i][j];
		frac ans=bfs();
		cout<<ans.num<<' '<<ans.den<<'\n';
	}
	return 0;
}

