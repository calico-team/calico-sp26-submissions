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


int main()
{
	int i,j,k,n,l,t,m,x,y,o,b1,e,r,ans,v;
	scanf("%d",&t);
	for (l=0;l<t;l++)
	{
		scanf("%d%d%d%d",&x,&y,&e,&r);
		v=(x+y)*2*r;
		ans=(e-1)/v+1;
		printf("%d\n",ans);
	}
}