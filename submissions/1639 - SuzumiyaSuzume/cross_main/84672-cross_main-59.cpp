#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T,n,m;
	cin>>T;
	while(T--)
	{
		cin>>n>>m;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
				cout<<(i*2+j)%5<<" ";
			puts("");
		}
	}
	return 0;
}