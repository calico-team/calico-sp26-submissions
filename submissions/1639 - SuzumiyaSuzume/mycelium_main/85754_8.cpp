#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	ll T,a,b,c,d;
	cin>>T;
	while(T--)
	{
		cin>>a>>b>>c>>d;
		int x=a-c,y=b-d;
		int r=2*(abs(x)+abs(y))/5;
		ll s=0;
		for(int i=-r;i<=r;i++)
		{
			int m=r-abs(i);
			for(int j=-m;j<=m;j++)
				if(7*(abs(i)+abs(j))<2*(abs(i-x)+abs(j-y)))
					s++;
		}
		cout<<s<<"\n";
	}
	return 0;
}