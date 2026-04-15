#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=13000;
char g[N][N];
int dx[]={-1,1,0,0},dy[]={0,0,-1,1};
int main()
{
	int T,a,b,c,d;
	cin>>T;
	while(T--)
	{
		cin>>a>>b>>c>>d;
		memset(g,0,sizeof(g));
		queue<int> gxx,gyy,mxx,myy;
		int gx=a-c+6500,gy=b-d+6500;
		int mx=6500,my=6500;
		g[gx][gy]=1;gxx.push(gx);gyy.push(gy);
		g[mx][my]=2;mxx.push(mx);myy.push(my);
		ll ans=1,tk=0;
		while(!mxx.empty())
		{
			tk++;
			if(tk%2==0)
			{
				int sz=gxx.size();
				while(sz--)
				{
					int cx=gxx.front();gxx.pop();
					int cy=gyy.front();gyy.pop();
					for(int i=0;i<4;i++)
					{
						int nx=cx+dx[i],ny=cy+dy[i];
						if(nx>=0 and nx<N and ny>=0 and ny<N and g[nx][ny]==0)
						{
							g[nx][ny]=1;
							gxx.push(nx);gyy.push(ny);
						}
						
					}
				}
			}
			if(tk%7==0)
			{
				int sz=mxx.size();
				while(sz--)
				{
					int cx=mxx.front();mxx.pop();
					int cy=myy.front();myy.pop();
					for(int i=0;i<4;i++)
					{
						int nx=cx+dx[i],ny=cy+dy[i];
						if(nx>=0 and nx<N and ny>=0 and ny<N and g[nx][ny]==0)
						{
							g[nx][ny]=2;
							ans++;
							mxx.push(nx); 
							myy.push(ny);
						}
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}