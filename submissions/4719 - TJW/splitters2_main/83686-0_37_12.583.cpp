#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		long long P,A,B;
		cin>>P>>A>>B;
		vector<int> ops;
		long long t=P;
		int c2=0,c3=0;
		while(t%2==0)
		{
			c2++;
			t/=2;
		}
		while(t%3==0)
		{
			c3++;
			t/=3;
		}
		for(int i=0;i<A;i++)
		{
			if(c2>0)
			{
				ops.push_back(2);
				c2--;
			}
			else ops.push_back(1);
		}
		for(int i=0;i<B;i++)
		{
			if(c3>0)
			{
				ops.push_back(3);
				c3--;
			}
			else ops.push_back(1);
		}
		int n=ops.size()*3+2;
		int m=5;
		vector<string> g(n,string(m,'.'));
		int r=0,c=2;
		g[r][c]='v';
		r++;
		for(int i=0;i<(int)ops.size();i++)
		{
			g[r][c]='S';
			int k=ops[i];
			vector<pair<int,int>> d = 
			{{0,-1},{0,1},{-1,0},{1,0}};
			int used=0;
			for(int j=0;j<4;j++)
			{
				int nr=r+d[j].first;
				int nc=c+d[j].second;
				if(used<k)
				{
					if(j==0) g[nr][nc]='>';
					if(j==1) g[nr][nc]='<';
					if(j==2) g[nr][nc]='v';
					if(j==3) g[nr][nc]='^';
					used++;
				}
				else g[nr][nc]='X';
			}
			if(i+1<(int)ops.size())
			{
				g[r+1][c]='v';
				g[r+2][c]='v';
				r+=3;
			}
		}
		g[r+1][c]='X';
		cout<<n<<" "<<m<<endl;
		for(auto &s:g)
			cout<<s<<endl;
	}
}
