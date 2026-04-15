#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		long long p,r;
		cin>>n>>p>>r>>k;
		vector<long long> a(n);
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		long long x=p;
		bool ok=1;
		int c=0;
		for(int i=0;i<n;i++)
		{
			if(c==k)
			{
				x=x+r;
				c=0;
			}
			x=x-a[i];
			if(x<0)
			{
				ok=0;
				break;
			}
			c++;
		}
		if(ok)
		{
			cout<<"nah i'd win"<<endl;
		}
		else
		{
			cout<<"nah i'd lose"<<endl;
		}
	}
	return 0;
}
