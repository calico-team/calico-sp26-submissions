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
// #define
#define lim 5000

int neigh[4][2]={{0,1},{1,0},{0,-1},{-1,0}};

bitset<lim+lim+1> a[lim+lim+1];
vector<pair<pair<int,int>,int> > q[110000];
int ans[110000];

int main()
{
	int i,j,k,n,l,t,m,x,y,o,b1,c,x1,y1,x2,y2,xx,yy,max_diff,v1,v2;
	_int64 tot;
	scanf("%d",&t);
	for (l=0;l<t;l++)
	{
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		x1-=x2;
		y1-=y2;
		x2=0;y2=0;
		xx=max(min(x1,lim),-lim);
		yy=max(min(y1,lim),-lim);
		x1+=lim;y1+=lim;
		x2+=lim;y2+=lim;
		xx+=lim;yy+=lim;
		for (i=0;i<110000;i++)
			q[i].clear();
		q[0].push_back(make_pair(make_pair(x2,y2),7));
		q[(abs(xx-x1)+abs(yy-y1))*2].push_back(make_pair(make_pair(xx,yy),2));
		for (i=0;i<=lim+lim;i++)
			a[i]=0;
		ans[0]=0;
		max_diff=0;
		tot=0;
		for (o=0;;o++)
		{
			if (o-1>=0) ans[o]=ans[o-1];
			tot+=q[o].size();
			// reverse(q[o].begin(),q[o].end());
			for (i=(int)q[o].size()-1;i>=0;i--)
			{
				x=q[o][i].first.first;
				y=q[o][i].first.second;
				c=q[o][i].second;
				// cerr<<"x,y,c:"<<x<<" "<<y<<" "<<c<<endl;
				if (a[x].test(y)) continue;
				if (c==7)
				{
					ans[o]++;
					// v1=abs(x-x1)+abs(y-y1);
					// v1*=2;
					// v2=abs(x-x2)+abs(y-y2);
					// v2*=7;
					// max_diff=max(max_diff,v2-v1);
				}
				a[x].set(y);
				for (k=0;k<4;k++)
				{
					xx=x+neigh[k][0];
					yy=y+neigh[k][1];
					if ((xx>=0)&&(xx<=lim+lim)&&(yy>=0)&&(yy<=lim+lim)&&(!a[xx].test(yy)))
						q[o+c].push_back(make_pair(make_pair(xx,yy),c));
				}
			}
			if ((o-7>=0)&&(ans[o]==ans[o-7])) break;
			q[o].clear();
			q[o].shrink_to_fit();
		}
		// cerr<<"max_diff:"<<max_diff<<endl;
		// cerr<<"o:"<<o<<endl;
		// cerr<<"tot:"<<tot<<endl;
		printf("%d\n",ans[o]);

	}
}