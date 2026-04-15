#include<bits/stdc++.h>
using namespace std;
int a[110],b[110];
int main()
{
	int t;
	bool flag;
	cin >> t;
	int k,n,m,p,q,x,y;
	for(int j = 1; j<=t; j++)
	{
		flag = true;
		cin >> k >> n >> m >> p >> q;
		for(int i = 0; i<k; i++) cin >> a[i] >> b[i];
		x = a[0];
		y = b[0];
		while(flag)
		{
			x += p;
			y += q;
			if(x>n) x-=n;
			if(y>m) y -= m;
			for(int i = 0; i<k; i++) if(a[i] == x && b[i] == y)
			{
				cout << i << endl;
				flag = false;
			}
		}
	}
	return 0;
}
