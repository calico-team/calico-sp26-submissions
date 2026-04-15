#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,b[100005],a[100005];
int main()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		for(int i=1;i<=n;i++) b[i]=a[i];
		sort(b+1,b+n+1);
		if(n==1) printf("%lld\n",a[1]);
		else if(n==2) printf("%lld %lld\n",a[1],a[2]);
		else printf("%lld %lld %lld\n",a[1],b[2],a[3]);
	}
	return 0;
}
