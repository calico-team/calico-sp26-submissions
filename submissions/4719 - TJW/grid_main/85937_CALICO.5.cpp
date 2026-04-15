#include<iostream>
#include<vector>
#include<algorithm>
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
		vector<ll> a(n);
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		vector<ll> b = a;
		sort(b.begin(),b.end());
		ll x = b[n/2];
		for(int i=0;i<n;i++)
		{
			if(i)
			{
				cout<<" ";
			}
			cout<<x;
		}
		cout<<endl;
	}
	return 0;
}
