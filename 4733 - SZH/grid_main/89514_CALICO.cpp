#include<bits/stdc++.h>
using namespace std;
int a[5],b[5];
int main()
{
	int t;
	bool flag;
	cin >> t;
	int n,maxn,minn,mina = 10000;
	cin >> n;
	for(int j = 1; j<=t; j++)
	{
		for(int i = 1; i<=n; i++)
		{
			cin >> a[i];
		}
		minn = min(a[3],min(a[2],a[1]));
		maxn = max(a[3],max(a[2],a[1]));
		
	}
	return 0;
}
