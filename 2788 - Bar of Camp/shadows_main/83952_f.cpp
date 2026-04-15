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

#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define vi vector<int>
#define pi pair<int, int>
#define vp vector<pair<int, int>>
#define um unordered_map<int, int>
#define us unordered_set<int>
#define mod 1000000007
#define SORT(x) sort(x.begin(), x.end())
#define SUM(x) accumulate(x.begin(), x.end(), 0LL)

char s1[2001][2001];
char s2[2001][2001];

int main()
{
    int t,p;
    scanf("%d",&t);
    for (p=1;p<=t;p++) {
        int n,m;
        int i,j,k;
        scanf("%d",&n);
        for (i=0;i<n;i++)
            scanf("%s",s1[i]);
        for (i=0;i<n;i++)
            scanf("%s",s2[i]);
        int res=0;
        for (i=0;i<n;i++) {
            int tot=0;
            for (j=0;j<n;j++) {
                if (s2[i][j]=='#') tot++;
            }
            for (j=0;j<n;j++)
                if (s1[i][j]=='#') res+=tot;
        }
        printf("%d ",res);
        res=0;
        for (i=0;i<n;i++) {
            int tot=0;
            for (j=0;j<n;j++) {
                if (s2[i][j]=='#') tot++;
            }
            int tot2=0;
            for (j=0;j<n;j++)
                if (s1[i][j]=='#') tot2++;
            res+=max(tot,tot2);
        }
        printf("%d\n",res);
    }
    return 0;
}
