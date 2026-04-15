#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int T,n;
	cin>>T;
	while(T--)
	{
		cin>>n;
		int a[1015]={0};
		char s[1015];
		for(int i=0;i<n;i++)
		{
			cin>>s;
			for(int j=0;j<n;j++)
				if(s[j]=='#')
					a[i]++;
		}
		ll mx=0,mn=0;
		for(int i=0;i<n;i++)
		{
			int b=0;
			cin>>s;
			for(int j=0;j<n;j++)
				if(s[j]=='#')
					b++;
			mx+=a[i]*b;
			if(a[i]>b) mn+=a[i];
			else mn+=b;
		}
		cout<<mx<<" "<<mn<<"\n";
	}
	return 0;
}