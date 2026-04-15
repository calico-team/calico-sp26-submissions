#include<iostream>
#include<vector>
using namespace std;
using ll = long long;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<ll> a(n),l(n),r(n),b(n);
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		l[0] = a[0];
		r[0] = a[0];
		for(int i=1;i<n;i++)
		{
			if(a[i]<l[i-1])
			{
				l[i] = a[i];
				r[i] = l[i-1];
			}
			else if(a[i]>r[i-1])
			{
				l[i] = r[i-1];
				r[i] = a[i];
			}
			else
			{
				l[i] = a[i];
				r[i] = a[i];
			}
		}
		b[n-1] = l[n-1];
		for(int i=n-2;i>=0;i--)
		{
			if(b[i+1]<l[i])
			{
				b[i] = l[i];
			}
			else if(b[i+1]>r[i])
			{
				b[i] = r[i];
			}
			else
			{
				b[i] = b[i+1];
			}
		}
		for(int i=0;i<n;i++)
		{
			if(i)
			{
				cout<<" ";
			}
			cout<<b[i];
		}
		cout<<endl;
	}
	return 0;
}
