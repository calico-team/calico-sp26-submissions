#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string a,b;
		cin>>a>>b;
		int j=0;
		for(int i=0;i<(int)a.size();i++)
		{
			if(j<(int)b.size()&&a[i]==b[j])
			{
				j++;
			}
			else
			{
				a[i]='#';
			}
		}
		cout<<a<<endl;
	}
	return 0;
}
