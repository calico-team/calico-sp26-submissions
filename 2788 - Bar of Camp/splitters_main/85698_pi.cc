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

int neigh[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
string ss=">v<^";

int getind(char c)
{
	int i;
	for (i=0;i<ss.length();i++)
		if (c==ss[i]) return i;
	return -1;
}

_int64 gcd(_int64 x,_int64 y)
{
	if (y==0) return x;
	else return gcd(y,x%y);
}

struct fac
{
	_int64 x,y;
};

void norm(fac &x)
{
	_int64 tmp;
	tmp=gcd(x.x,x.y);
	x.x/=tmp;
	x.y/=tmp;
}

fac add(fac x,fac y)
{
	fac z;
	z.y=x.y*y.y;
	z.x=x.x*y.y+x.y*y.x;
	norm(z);
	return z;
}

char a[30][30];
fac d[30][30];
vector<pair<int,int> > out1[30][30];
vector<pair<int,int> > in1[30][30];
int rem1[30][30];

int main()
{
	int i,j,k,n,l,t,m,x,y,o,b1,xx,yy,ind,sz;
	vector<pair<int,int> > q;
	scanf("%d",&t);
	for (l=0;l<t;l++)
	{
		scanf("%d%d",&m,&n);
		for (i=0;i<m;i++)
			scanf("%s",a[i]);
		q.clear();
		for (i=0;i<m;i++)
			for (j=0;j<n;j++)
			{
				out1[i][j].clear();
				in1[i][j].clear();
				rem1[i][j]=0;
			}
		for (i=0;i<m;i++)
			for (j=0;j<n;j++)
			{
				if (a[i][j]=='.') continue;
				if (a[i][j]=='S')
				{
					for (k=0;k<4;k++)
					{
						x=i+neigh[k][0];
						y=j+neigh[k][1];
						if ((x<0)||(x>=m)&&(y<0)&&(y>=n)) continue;
						if (a[x][y]=='.') continue;
						if (a[x][y]=='S') continue;
						if (a[x][y]=='X')
						{
							out1[i][j].push_back(make_pair(x,y));
							in1[x][y].push_back(make_pair(i,j));
							rem1[i][j]++;
							continue;
						}
						ind=getind(a[x][y]);
						xx=x+neigh[ind][0];
						yy=y+neigh[ind][1];
						if ((xx!=i)||(yy!=j))
						{
							out1[i][j].push_back(make_pair(x,y));
							in1[x][y].push_back(make_pair(i,j));
							rem1[i][j]++;
							continue;
						}
					}
					continue;
				}
				if (a[i][j]=='X')
				{
					d[i][j]={0,1};
					q.push_back(make_pair(i,j));
					continue;
				}
				ind=getind(a[i][j]);
				x=i+neigh[ind][0];
				y=j+neigh[ind][1];
				if ((x>=0)&&(x<m)&&(y>=0)&&(y<n))
				{
					out1[i][j].push_back(make_pair(x,y));
					in1[x][y].push_back(make_pair(i,j));
					rem1[i][j]++;
				}
				else
				{
					d[i][j]={1,1};
					q.push_back(make_pair(i,j));
				}
			}
		sz=q.size();
		// cerr<<"rem1:"<<rem1[2][8]<<endl;
		for (i=0;i<q.size();i++)
		{
			x=q[i].first;
			y=q[i].second;
			if (i>=sz)
			{
				d[x][y]={0,1};
				// cerr<<"out1:"<<out1[x][y].size()<<endl;
				for (j=0;j<out1[x][y].size();j++)
				{
					xx=out1[x][y][j].first;
					yy=out1[x][y][j].second;
					// cerr<<"xx,yy:"<<xx<<" "<<yy<<endl;
					d[x][y]=add(d[x][y],d[xx][yy]);
				}
				d[x][y].y*=(int)out1[x][y].size();
			}
			// cerr<<"x,y,d:"<<x<<" "<<y<<" "<<d[x][y].x<<" "<<d[x][y].y<<endl;
			norm(d[x][y]);
			for (j=0;j<in1[x][y].size();j++)
			{
				xx=in1[x][y][j].first;
				yy=in1[x][y][j].second;
				rem1[xx][yy]--;
				if (rem1[xx][yy]==0) q.push_back(make_pair(xx,yy));
			}
		}
		printf("%lld %lld\n",d[0][0].x,d[0][0].y);
	}
}