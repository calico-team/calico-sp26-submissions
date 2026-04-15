#include<bits/stdc++.h>
using namespace std;
int n,m,k,s[2015][2015],u,bi,bj;
char g[1015][1015];
int sum(int r1,int c1,int r2,int c2)
{
	r1=max(1,r1);c1=max(1,c1);
	r2=min(u,r2);c2=min(u,c2);
	if(r1>r2 or c1>c2) return 0;
	return s[r2][c2]-s[r1-1][c2]-s[r2][c1-1]+s[r1-1][c1-1];
}
bool chk(int t)
{
	for(int i=1;i<=u;i++)
		for(int j=1;j<=u;j++)
			if(sum(i,j,i+t,j+t)>=k)
			{
				bi=i;bj=j;
				return 1;
			}
	return 0;
}
void solve()
{
	cin>>n>>m>>k;
	u=n+m;
	for(int i=0;i<=u;i++)
		for(int j=0;j<=u;j++)
			s[i][j]=0;
	for(int i=0;i<n;i++)
	{
		cin>>g[i];
		for(int j=0;j<m;j++)
			if(g[i][j]=='-')
				s[i+j+1][i-j+m]++;
	}
	for(int i=1;i<=u;i++)
		for(int j=1;j<=u;j++)
			s[i][j]+=s[i-1][j]+s[i][j-1]-s[i-1][j-1];
	int l=0,r=2000,ans=2000;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(chk(mid)) ans=mid,r=mid-1;
		else l=mid+1;
	}
	chk(ans);
	for(int i=0,c=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(g[i][j]=='-' and c<k)
			{
				int u=i+j+1,v=i-j+m;
				if(u>=bi and u<=bi+ans and v>=bj and v<=bj+ans)
				{
					cout<<i<<" "<<j<<"\n";
					c++;
				}
			}
}
int main()
{
	int T;
	cin>>T;
	while(T--)
		solve();
/*
人潮仍是漫无目的地向目的地散去

忙碌着无为着继续

等待着谁能够将我的心房轻轻叩击

即使是你也仅仅驻足了片刻便离去

想着或许下个路口会有谁与我相遇

我为什么要来ROCTW呢...如果在内地看着毛毛 在史地政班过上碌碌无为的又两年 不好吗

让历史来评判...
*/
	return 0;
}