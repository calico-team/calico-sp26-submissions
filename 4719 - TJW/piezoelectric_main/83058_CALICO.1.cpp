#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int l,w,e,r;
		cin>>l>>w>>e>>r;
		int per=2*(l+w);
		int need=e/r;
		int laps=0;
		while(need>0)
		{
			need-=per;
			laps++;
		}
		cout<<laps<<endl;
	}
	return 0;
}