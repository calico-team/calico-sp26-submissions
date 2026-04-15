#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,m;
ll a[5]={4,2,0,3,1};
void szzakioi()
{
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		ll k=a[i%5];
		for(int j=1;j<=m;j++)
		{
			printf("%lld ",k);
			k=(k+1)%5;
		}
		printf("\n");
	}
}
int main()
{
	scanf("%lld",&t);
	while(t--) szzakioi();
	return 0;
}
