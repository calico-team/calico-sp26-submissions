#include<bits/stdc++.h>
//#include<windows.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
ll testcases,n,m,k,p,q;
ll d[100005],dt;
pii a[100005];
ll num[1005][1005];
//y*q - p*x = y0*q - p*x0
//ax=c-by
// x+p*t>=n
void szzakioi()
{
	memset(num,0,sizeof(num));
	//s.clear();
	scanf("%lld%lld%lld%lld%lld",&k,&n,&m,&q,&p);
	for(int i=1;i<=k;i++)
	{
		scanf("%lld%lld",&a[i].first,&a[i].second);
		num[a[i].first][a[i].second]=i;
		//d[i]=a[i].second*q-a[i].first*p;
		//if(s.count(d[i])) s[d[i]]=min(s[d[i]],d[i]);
		//else s[d[i]]=d[i];
	}
	//dt=a[1].second*q-a[1].first*p;
	ll posx=a[1].first,posy=a[1].second;
	posx+=p,posy+=q;
	posx%=n,posy%=m;
	//ll ansposx=0,ansposy=0;
//	for(int i=1;i<=k;i++)
//	{
//		(p[i].second-posy)*
//	}
//	// k*q=y-y0 mod m
//	
//	
//	
//	return;
	while(true)
	{
		//printf("%lld-%lld\n",posx,posy); 
		//printf("%lld,%lld\n",posx,posy);
		if(num[posx][posy])
		{
			printf("%lld\n",num[posx][posy]-1);
			return;
		}
		posx+=p;
		posy+=q;
		posx%=n;
		posy%=m;
		//Sleep(300); 
	}
//	printf("---\n"); 
//	for(int i=1;i<=k;i++)
//		if(a[i].first==ansposx&&q*a[i].second-p*a[i].first==ansposy)
//		{
//			printf("%d\n",i-1);
//			return;
//		}
}
int main()
{
	scanf("%lld",&testcases);
	while(testcases--) szzakioi();
	return 0;
}
