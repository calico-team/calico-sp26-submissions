#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <random>
#include <chrono>
 
using namespace std;
 
#define _int64 long long
#define mo 998244353

char a[1100][1100];
int d[2100][2100];

int main()
{
	int i,j,k,n,l,t,m,x,y,o,b1,mm,nn,n1,ll,rr,mid,tot,ansx,ansy;
	vector<pair<int,int> > ans;
	scanf("%d",&t);
	for (l=0;l<t;l++)
	{
		scanf("%d%d%d",&m,&n,&n1);
		for (i=0;i<m;i++)
			scanf("%s",a[i]);
		memset(d,0,sizeof(d));
		for (i=0;i<m;i++)
			for (j=0;j<n;j++)
			{
				if (a[i][j]!='-') continue;
				d[i-j+n][i+j]++;
			}
		mm=m+n;nn=m+n;
		for (i=0;i<mm;i++)
			for (j=0;j<nn;j++)
			{
				if (i-1>=0) d[i][j]+=d[i-1][j];
				if (j-1>=0) d[i][j]+=d[i][j-1];
				if ((i-1>=0)&&(j-1>=0)) d[i][j]-=d[i-1][j-1];
			}
		ll=-1;rr=m+n;
		while (rr-ll>1)
		{
			mid=(ll+rr)/2;
			b1=0;
			for (i=0;i<mm;i++)
				for (j=0;j<nn;j++)
				{
					x=min(i+mid,mm-1);
					y=min(j+mid,nn-1);
					tot=d[x][y];
					if (i-1>=0) tot-=d[i-1][y];
					if (j-1>=0) tot-=d[x][j-1];
					if ((i-1>=0)&&(j-1>=0)) tot+=d[i-1][j-1];
					if (tot>=n1) b1=1;
				}
			if (b1==1) rr=mid;
			else ll=mid;
		}
		mid=rr;
		b1=0;
		ansx=-1;ansy=-1;
		for (i=0;i<mm;i++)
		{
			for (j=0;j<nn;j++)
			{
				x=min(i+mid,mm-1);
				y=min(j+mid,nn-1);
				tot=d[x][y];
				if (i-1>=0) tot-=d[i-1][y];
				if (j-1>=0) tot-=d[x][j-1];
				if ((i-1>=0)&&(j-1>=0)) tot+=d[i-1][j-1];
				if (tot>=n1)
				{
					ansx=i;ansy=j;
					b1=1;
					break;
				}
			}
			if (b1==1) break;
		}
		ans.clear();
		for (i=0;i<m;i++)
			for (j=0;j<n;j++)
			{
				if (a[i][j]!='-') continue;
				x=i-j+n;
				y=i+j;
				if ((x>=ansx)&&(x<=ansx+mid)&&(y>=ansy)&&(y<=ansy+mid))
				{
					ans.push_back(make_pair(i,j));
				}
			}
		while (ans.size()>n1) ans.pop_back();
		for (i=0;i<ans.size();i++)
			printf("%d %d\n",ans[i].first,ans[i].second);
	}
}