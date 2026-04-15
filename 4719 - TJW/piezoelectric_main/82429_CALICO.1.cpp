
#include<iostream>
using namespace std;
using ll = long long;
ll solve_case(int l,int w,int e,int r)
{
	ll triangle_area=2 * (l+w);
	ll x = triangle_area * r;
	return e / x;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int l,w,e,r;
		cin>>l>>w>>e>>r;
		cout<<solve_case(l,w,e,r)<<endl;
	}
	return 0;
}










































//67