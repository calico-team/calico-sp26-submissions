#include<iostream>
using namespace std;
int main()
{
	int T;
	int a[100][100];
	int e[100][100];
	int sum1=0;
	int sum2=0;
	
	cin>>T;
	for(int i=0;i<T;i++)
	{
		for(int j=0;j<3;j++)
		{
			cin>>a[i][j];
		}
		for(int k=0;k<a[i][0];i++)
		{
			cin>>e[i][k];
		}
	}
	for(int i=0;i<T;i++)
	{
		for(int j=0;j<a[i][3];j++)
		{
			sum1+=e[i][j];
		}
		for(int k=a[i][3];k<a[i][0];k++)
		{
			sum2+=e[i][k];
		}
		if(a[i][1]-sum1<0)
		{
			cout<<"nah i' d lose"<<endl;
		}
		else
		{
			if(a[i][1]-sum1+a[i][2]>=sum2)
			{
				cout<<"nah i' d win"<<endl;
			}
			else
			{
				cout<<"nah i' d lose"<<endl;
			}
		}
	}
}
