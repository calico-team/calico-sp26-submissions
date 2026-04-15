#include<iostream>
using namespace std;
int main()
{
	int T,a[10][4];
	
	cin>>T;
	for(int i=0;i<T;i++)
	{
		for(int j=0;j<4;j++)
		{
			cin>>a[i][j];
		}	
	}
	
	for(int i=0;i<T;i++)
	{
		cout<<a[i][2]/(2*(a[i][0]+a[i][1])*a[i][3])<<endl;
	}
} 
