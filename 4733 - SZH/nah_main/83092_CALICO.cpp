#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	bool flag;
	int n,p,r,k,x;
	for(int j = 1; j<=t; j++)
	{
		flag = true;
		cin >> n >> p >> r >> k;
		for(int i = 1; i<=n; i++)
		{
			cin >> x;
			p-=x;
			if(p < 0 && flag)
			{
				cout << "nah i'd lose" << endl;
				flag = false;
			}
			if(i%k==0) p+=r; 
		}
		if(flag)cout << "nah i'd win" << endl;
	}
	return 0;
}
