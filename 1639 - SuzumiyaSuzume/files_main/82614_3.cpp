#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string a,b;
		cin>>a>>b;
		int j=0;
		for(int i=0;i<a.size();i++)
			if(j<b.size() and a[i]==b[j])
				j++;
			else a[i]='#';
		cout<<a<<"\n";
	}
	return 0;
}