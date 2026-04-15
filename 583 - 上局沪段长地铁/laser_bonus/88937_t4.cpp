#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll k,n,m,p,q,x[1000001],y[1000001],jz[1000001],js[1000001];
ll ksm(ll ja,ll jb){
	if(jb<0)return 0;
	ll jans=1;
	while(jb){
		if(jb&1)jans=(jans*ja)%m;
		ja=(ja*ja)%m;
		jb>>=1;
	}
	return jans;
}
ll exgcd(ll a,ll b,ll &x,ll &y)
{
	if(b==0)
	{
		x=1,y=0;
		return a;
	}
	ll xx,yy;
	ll g=exgcd(b,a%b,xx,yy);
	x=yy;y=xx-(a/b)*yy;
	return g;
}
 
ll calc(ll a,ll b,ll c)
{
	ll x,y;
	ll g=exgcd(a,b,x,y);
	if(c%g!=0) return -1 ;
	x*=c/g;
	b=abs(b/g);
	return (x%b+b)%b;
}
int main(){
	//ios::sync_with_stdio(0);
	//cin.tie(0);cout.tie(0);
	ll t;
	cin>>t;
	while(t--){
		cin>>k>>n>>m>>p>>q;
		for(int i=1;i<=k;i++){
			cin>>x[i]>>y[i];
		}
		vector<int>vx,vy;
		ll jx=(x[1]+q)%n,jy=(y[1]+p)%m,ns=1;
		while(jx!=x[1]){
			vx.push_back(jx);
			vy.push_back(jy);
			jz[jx]=(jy-y[1]+m)%m;js[jx]=ns;
			jx=(jx+q)%n;jy=(jy+p)%m;ns++;
		}
		vx.push_back(jx);vy.push_back(jy);
		jz[jx]=(jy-y[1]+m)%m;js[jx]=ns;
		ll ans=1000000000000000000,jans=1;
		for(int i=2;i<=k;i++){
			//(jz[x[i]]*aa)%m=y[i]
			//aa=y[i]/jz[x[i]]
			//a=n*aa+js[x[i]]
			//solution: https://www.codeleading.com/article/32922471485/
			y[i]=(y[i]-y[1]-jz[x[i]]+m*2)%m;
			ll jx=calc(jz[x[1]],m,y[i]);
			if(jz[x[1]]==y[i]||y[i]==0)jx=0;
			if(jx==-1)continue;
			ll a=n*jx+js[x[i]];
			//cout<<a<<" "<<jz[x[i]]<<endl;
			if(a<ans){
				ans=a;
				jans=i;
			}
		}
		cout<<jans-1<<endl;
	}
	return 0;
}
