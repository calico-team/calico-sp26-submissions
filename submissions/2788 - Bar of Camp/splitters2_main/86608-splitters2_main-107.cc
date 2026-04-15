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
#define lim 2000

char ans[10][2100];

int main()
{
	int i,j,k,n,l,t,m,x,y,o,b1,a,pos,b;
	_int64 p,rem,v,tmp;
	scanf("%d",&t);
	for (l=0;l<t;l++)
	{
		scanf("%lld%d%d",&p,&a,&b);
		rem=p;
		for (i=0;i<a;i++)
			rem/=2;
		for (i=0;i<b;i++)
			rem/=3;
		if (rem==1)
		{
			printf("1 1\n");
			printf("v\n");
			continue;
		}
		m=5;n=lim/5;
		for (i=0;i<m;i++)
			for (j=0;j<n;j++)
				ans[i][j]='.';
		ans[0][0]='v';
		ans[1][0]='v';
		ans[2][0]='>';
		ans[4][0]='<';
		pos=0;
		x=2;y=0;
		rem=p;
		while (a>0)
		{
			a--;
			v=rem;
			for (i=0;i<a;i++)
				v/=2;
			for (i=0;i<b;i++)
				v/=3;
			ans[x][y+1]='>';
			ans[x][y+2]='S';
			if (v==0) ans[x+1][y+2]='X';
			else
			{
				tmp=1;
				for (i=0;i<a;i++)
					tmp*=2;
				for (i=0;i<b;i++)
					tmp*=3;
				rem-=tmp;
				ans[x+1][y+2]='v';
				while (pos<y+2)
				{
					pos++;
					ans[4][pos]='<';
				}
			}
			ans[x][y+3]='>';
			y+=3;
		}
		while (b>0)
		{
			b--;
			v=rem;
			for (i=0;i<a;i++)
				v/=2;
			for (i=0;i<b;i++)
				v/=3;
			ans[x][y+1]='>';
			ans[x][y+2]='S';
			if (v!=0)
			{
				tmp=1;
				for (i=0;i<a;i++)
					tmp*=2;
				for (i=0;i<b;i++)
					tmp*=3;
			}
			if (v==0)
			{
				ans[x+1][y+2]='X';
				ans[x][y+3]='X';
			}
			else if (v==1)
			{
				ans[x][y+3]='X';
				ans[x+1][y+2]='v';
				while (pos<y+2)
				{
					pos++;
					ans[4][pos]='<';
				}				
				rem-=tmp;
			}
			else
			{
				ans[x][y+3]='v';
				ans[x+1][y+3]='v';
				ans[x+1][y+2]='v';
				while (pos<y+3)
				{
					pos++;
					ans[4][pos]='<';
				}
				rem-=tmp*2;
			}
			ans[x-1][y+2]='>';
			ans[x-1][y+3]='>';
			ans[x-1][y+4]='v';
			ans[x][y+4]='>';
			y+=4;
		}
		ans[x][y+1]='X';
		printf("%d %d\n",m,n);
		for (i=0;i<m;i++)
		{
			ans[i][n]='\0';
			printf("%s\n",ans[i]);
		}
	}
}