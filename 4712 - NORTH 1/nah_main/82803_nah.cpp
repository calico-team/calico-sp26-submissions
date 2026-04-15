#include<bits/stdc++.h>
using namespace std;
#define fst ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define int long long
const int N=1e6+10,M=2e6+10;
const int INF=0x3f3f3f3f3f3f3f3f;
const int P=998244353;//3221225477
int t,n,p,r,k;
int a[N];
void solve()
{
	cin>>n>>p>>r>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int x=a[i];
		if(p-x>=0)
		{
			p-=x;
		}
		else
		{
			cout<<"nah i'd lose\n";
			return;
		}
		if(i%k==0)
		{
			p+=r;
		}
	}
	cout<<"nah i'd win\n";
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
