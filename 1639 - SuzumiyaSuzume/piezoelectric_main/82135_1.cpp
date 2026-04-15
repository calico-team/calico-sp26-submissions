#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T,l,w,e,r;
	cin>>T;
	while(T--)
	{
		cin>>l>>w>>e>>r;
		cout<<e/(2*(l+w)*r)<<"\n";
	}
	return 0;
}