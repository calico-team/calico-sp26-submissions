#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
	int t,a,b,c; 
	int minm=100,A,B,C;
int main(){
	cin>>t;
	while(t--)
	{
		cin>>a>>b>>c;
		int minn=min(min(a,b),c);
		int maxn=max(max(a,b),c);
		for(int i=minn;i<=maxn;i++)
		{
			for(int j=minn;j<=maxn;j++)
			{
				for(int k=minn;k<=maxn;k++)
				{
					int number=abs(i-j)+abs(i-k)+abs(j-k)+abs(a-i)+abs(b-j)+abs(k-c);
					if(minm>number)
					{
						minm=number;
						A=i,B=j,C=k;
					}
				}
			}
		}
		cout<<A<<" "<<B<<" "<<C<<"\n";
		minm=100;
	}


return 0;
}

