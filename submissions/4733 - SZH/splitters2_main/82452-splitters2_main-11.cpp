#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,p,r,k,x;
	cin >> n >> p >> r >> k;
	for(int i = 1; i<=n; i++)
	{
		cin >> x;
		p-=x;
		if(p < 0)
		{
			cout << "nah i'd lose";
			return 0;
		}
		if(i%k==0) p+=r; 
	}
	cout << "nah i'd win";
	return 0;
} 
