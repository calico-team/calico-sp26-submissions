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
		vector<ll> a(n);
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		for(int i=0;i<n;i++)
		{
			if(i)
			{
				cout<<" ";
			}
			cout<<a[i];
		}
		cout<<endl;
	}
	return 0;
}
