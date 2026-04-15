#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,p,r,k;
		cin>>n>>p>>r>>k;
		vector<int>a(n);
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		int cur=p;
		int cnt=0;
		int use=0;
		bool ok=1;
		for(int i=0;i<n;i++)
		{
			cur=cur-a[i];
			cnt++;
			if(cnt%k==0)
			{
				use++;
			}
			if(cur<0)
			{
				if(use>0)
				{
					cur=cur+r;
					use--;
				}
				if(cur<0)
				{
					ok=0;
					break;
				}
			}
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
}