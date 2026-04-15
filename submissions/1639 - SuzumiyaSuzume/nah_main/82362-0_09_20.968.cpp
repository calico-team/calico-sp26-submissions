#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int T;
	ll n,p,r,k,e,w;
	cin>>T;
	while(T--)
	{
		cin>>n>>p>>r>>k;
		w=1;
		for(int i=1;i<=n;i++)
		{
			cin>>e;
			if(w)
			{
				p-=e;
				if(p<0)
					w=0;
				else if(i%k==0)
					p+=r;
			}
		}
		if(w)
			cout<<"nah i'd win\n";
		else
			cout<<"nah i'd lose\n";
	}
	return 0;
}