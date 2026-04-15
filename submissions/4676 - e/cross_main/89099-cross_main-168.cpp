#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int j=0; j<t; j++)
	{
		int l,w;
		cin>>l>>w;

		int grid[l][w];

		int count=0;
		for(int i=0; i<l; i++)
		{
			count=i*2;
			for(int k=0; k<w; k++)
			{
				grid[i][k] = count;
				count++;
				if(count>4) count=0;
			}

		}

		for(int i=0; i<l; i++)
		{
			for(int k=0; k<w; k++)
			{
				cout<<grid[i][k]<<" ";
			}
			cout<<endl;
		}

	}


}