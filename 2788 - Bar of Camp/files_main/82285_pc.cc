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

char s1[110];
char s2[110];
// int d[110][110];

int main()
{
	int i,j,k,n,l,t,m,x,y,o,b1,len1,len2,ind;
	scanf("%d",&t);
	for (l=0;l<t;l++)
	{
		scanf("%s%s",s1,s2);
		len1=strlen(s1);
		len2=strlen(s2);
		ind=0;
		for (i=0;i<len2;i++)
		{
			while ((ind<len1)&&(s1[ind]!=s2[i]))
			{
				s1[ind]='#';
				ind++;
			}
			ind++;
		}
		while (ind<len1)
		{
			s1[ind]='#';
			ind++;
		}
		printf("%s\n",s1);
	}
}