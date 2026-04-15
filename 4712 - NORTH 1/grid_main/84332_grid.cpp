#include<bits/stdc++.h>
using namespace std;
#define fst ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define int long long
const int N=1e6+10,M=2e6+10;
const int INF=0x3f3f3f3f3f3f3f3f;
const int P=998244353;//3221225477
int t;
int n;
int a[N];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	cout<<a[1]<<' ';
	for(int i=2;i<n;i++)
	{
		if((a[i-1]<=a[i]&&a[i]<=a[i+1])||(a[i-1]>=a[i]&&a[i]>=a[i+1]))
		{
			cout<<a[i]<<' ';
		}
		else if(a[i-1]<=a[i]&&a[i+1]<=a[i])
		{
			cout<<max(a[i-1],a[i+1])<<' ';
			a[i]=max(a[i-1],a[i+1]);
		}
		else if(a[i-1]>=a[i]&&a[i+1]>=a[i])
		{
			cout<<min(a[i-1],a[i+1])<<' ';
			a[i]=min(a[i-1],a[i+1]);
		}
	}
	cout<<a[n];
}
signed main()
{
	fst
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}
