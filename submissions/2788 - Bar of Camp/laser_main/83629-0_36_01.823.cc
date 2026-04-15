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

int xx[110000];
int yy[110000];

int main()
{
	int i,j,k,n,l,t,m,x,y,o,b1,p,q,nn,ans;
	scanf("%d",&t);
	for (l=0;l<t;l++)
	{
		scanf("%d%d%d%d%d",&nn,&m,&n,&q,&p);
		vector<vector<int> > used=vector<vector<int> >(m,vector<int>(n,0));
		vector<vector<int> > ind=vector<vector<int> >(m,vector<int>(n,-1));
		for (i=0;i<nn;i++)
		{
			scanf("%d%d",&xx[i],&yy[i]);
			ind[xx[i]][yy[i]]=i;
		}
		x=xx[0];y=yy[0];
		ans=-1;
		do
		{
			x+=p;y+=q;
			x%=m;y%=n;
			// cerr<<"x,y:"<<x<<" "<<y<<endl;
			if (used[x][y]==1) break;
			if (ind[x][y]!=-1)
			{
				ans=ind[x][y];
				break;
			}
			used[x][y]=1;
		}while (1);
		printf("%d\n",ans);
	}
}