#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=100015;
int a[N];
ll l[N],r[N],ans[N];
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>a[i];
		l[0]=r[0]=a[0];
		for(int i=1;i<n;i++)
		{
			if(a[i]>r[i-1])
			{
				l[i]=r[i-1];
				r[i]=a[i];}
			else if(a[i]<l[i-1])
			{
				l[i]=a[i];
				r[i]=l[i-1];
			}
			else
				l[i]=r[i]=a[i];
		}
		ll b=l[n-1];
		ans[n-1]=b;
		for(int i=n-2;i>=0;i--)
		{
			b=max(l[i],min(r[i],b));
			ans[i]=b;
		}
		for(int i=0;i<n;i++)
		{
			cout<<ans[i]<<" ";
		}
		puts("");
	}
	return 0;
}