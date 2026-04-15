#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll x[100015],y[100015];

ll eg(ll a,ll b,ll &x,ll &y)
{
	if(!b)
	{x=1; y=0; return a;}
	ll d=eg(b,a%b,y,x);
	y-=a/b*x;
	return d;
}

ll inv(ll a,ll m)
{
	ll x,y;
	eg(a,m,x,y);
	return (x%m+m)%m;
}
ll gcd(ll a,ll b)
{ 
	if(b)
		return gcd(b,a%b);
	else
    	return a;
}
void solve()
{
	ll k,n,m,p,q;
	cin>>k>>n>>m>>p>>q;
	for(int i=0;i<k;i++)
		cin>>x[i]>>y[i];
	ll ans=0,mt=-1;
	for(int i=0;i<k;i++)
	{
		ll dx=(x[i]-x[0]%n+n)%n;
		ll dy=(y[i]-y[0]%m+m)%m;
		ll g1=gcd(q,n),g2=gcd(p,m);
		if(dx%g1 or dy%g2)
			continue;
		ll n1=n/g1,m1=m/g2;
		ll a=(dx/g1)%n1*inv(q/g1,n1)%n1;
		ll b=(dy/g2)%m1*inv(p/g2,m1)%m1;
		ll g3=gcd(n1,m1);
		if((b-a)%g3)
			continue;
		ll n2=n1/g3,m2=m1/g3,df=(b-a)/g3;
		ll u,v;
		eg(n2,m2,u,v);
		ll t=a+(u%m2+m2)%m2*((df%m2+m2)%m2)%m2*n1;
		if(t==0)
			t=n1*m2;
		if(mt==-1 or t<mt)
		{
			mt=t;
			ans=i;
		}
	}
	cout<<ans<<"\n";
}
int main()
{
	int T;
	cin>>T;
	while(T--)
		solve();
	return 0;
}