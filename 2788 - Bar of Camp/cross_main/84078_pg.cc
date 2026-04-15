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

int aa[5]={0,4,1,2,3};
int ans[1100][1100];


int main()
{
	int i,j,k,n,l,t,m,x,y,o,b1,off;
	scanf("%d",&t);
	for (l=0;l<t;l++)
	{
		scanf("%d%d",&m,&n);
		off=0;
		for (i=0;i<m;i++)
		{
			for (j=0;j<n;j++)
				ans[i][j]=aa[(off+j)%5];
			off+=3;
			off%=5;
		}
		for (i=0;i<m;i++)
		{
			for (j=0;j<n;j++)
				printf("%d ",ans[i][j]);
			printf("\n");
		}
	}
}