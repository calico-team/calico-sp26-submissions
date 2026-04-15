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

__int128 gcd(__int128 x,__int128 y)
{
	if (y==0) return x;
	else return gcd(y,x%y);
}

pair<__int128,__int128> exgcd(_int64 a,_int64 b,_int64 c)
{
    __int128 x,y;
    if (a==0) return make_pair(0LL,c/b);
    if (b==0) return make_pair(c/a,0LL);
    pair<__int128,__int128> ret;
    ret=exgcd(b,a%b,c);
    x=ret.first;
    y=ret.second;
    return make_pair(y,-y*(a/b)+x);
}

__int128 abs(__int128 x)
{
	if (x<0) return -x;
	return x;
}

int main()
{
	int i,j,k,l,t,x,y,o,b1,nn,ans;
	_int64 aa,bb,cc,m,n,p,q,tmp;
	pair<pair<__int128,__int128>,pair<int,int> > ansv;
	pair<pair<__int128,__int128>,pair<int,int> > tmpv;
	pair<pair<__int128,__int128>,pair<int,int> > base;
	scanf("%d",&t);
	for (l=0;l<t;l++)
	{
		scanf("%d%lld%lld%lld%lld",&nn,&m,&n,&q,&p);
		for (i=0;i<nn;i++)
		{
			scanf("%d%d",&xx[i],&yy[i]);
		}
		base=make_pair(make_pair(0,0),make_pair(xx[0],yy[0]));
		ans=0;
		for (i=0;i<nn;i++)
		{
			aa=m*q;
			bb=-p*n;
			cc=p*yy[i]-p*yy[0]-q*xx[i]+q*xx[0];
			tmp=gcd(abs(aa),abs(bb));
			if (cc%tmp!=0) continue;
			aa/=tmp;
			bb/=tmp;
			cc/=tmp;
			pair<__int128,__int128> sol=exgcd(aa,bb,cc);
			// cerr<<"aa,bb:"<<aa<<" "<<bb<<endl;
			if (sol.second>0)
			{
				tmp=sol.second/abs(aa);
				sol.first-=tmp*abs(bb);
				sol.second-=tmp*abs(aa);
			}
			if (sol.second<0)
			{
				tmp=abs(sol.second)/abs(aa);
				sol.first+=tmp*abs(bb);
				sol.second+=tmp*abs(aa);
			}

			tmpv=make_pair(sol,make_pair(xx[i],yy[i]));
			while (tmpv<=base)
			{
				sol.first+=abs(bb);
				sol.second+=abs(aa);
				tmpv=make_pair(sol,make_pair(xx[i],yy[i]));
			}
			// cerr<<"sol:"<<i<<" "<<(_int64)sol.first<<" "<<(_int64)sol.second<<endl;
			if (i==0)
			{
				ansv=tmpv;
				ans=0;
				continue;
			}

			if (tmpv<ansv)
			{
				ansv=tmpv;
				ans=i;
			}
		}
		printf("%d\n",ans);
	}
}