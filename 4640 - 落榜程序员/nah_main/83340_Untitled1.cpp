#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
	int t ,N,P,R,K;
	int n[10000+10];
int main(){
	cin>>t;
	for(int j=1;j<=t;j++)
	{
		cin>>N>>P>>R>>K;
		int number=0,k=N;
		bool check = true;
	//	cout<<N<<" "<<P<<" "<<R<<" "<<K<<" "<<endl;
		for(int i=1;i<=k;i++)
		{
			//cout<<k<<" ";
			cin>>n[i];
		//	number++;
			
		}
		for(int i=1;i<=N;i++)
		{
		//	cout<<n[i]<<" ";
			if(number==K)
			{
				P+=R;
				number=0;
			}
			if(P>=n[i])
			{
				number++;
				P=P-n[i];
			}
			else
			{
				check=false;
				break;
			}
		}
		if(check==true)cout<<"nah i'd win\n";
		if(check==false) cout<<"nah i'd lose\n";
	}


return 0;
}
/*
6
5 60 5 1
12 6 23 8 10
4 42 10 3
40 10 5 8
3 10 5 2
5 5 5
3 20 50 3
10 10 10
4 5 10 1
4 10 10 10
1 10 100 1
15
*/
