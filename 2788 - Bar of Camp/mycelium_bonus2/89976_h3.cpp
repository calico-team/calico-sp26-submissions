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

bitset<70001> a[70010];
vector<int> xr1[15001];
vector<int> yr1[15001];
vector<int> xr2[5001];
vector<int> yr2[5001];

int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};

int main()
{
    int t,p;
    scanf("%d",&t);
    for (p=1;p<=t;p++) {
        int n,m;
        int i,j,k;
        int xxr1,yyr1,xxr2,yyr2;
        scanf("%d%d%d%d",&xxr1,&yyr1,&xxr2,&yyr2);
        xxr1+=35000;
        yyr1+=35000;
        xxr2+=35000;
        yyr2+=35000;
        //memset(a,0,sizeof(a));
        for (int i=0;i<70000;i++)
            a[i]=0;
        a[xxr1].set(yyr1);
        a[xxr2].set(yyr2);
        xr1[0].clear();
        yr1[0].clear();
        xr2[0].clear();
        yr2[0].clear();
        xr1[0].push_back(xxr1);
        yr1[0].push_back(yyr1);
        xr2[0].push_back(xxr2);
        yr2[0].push_back(yyr2);
        int res=1;
        for (i=1;i<=30000;i++) {
            //printf("%d\n",i);
            if (i%2==0) {
                j=i/2;
                xr1[j].clear();
                yr1[j].clear();
                for (k=0;k<xr1[j-1].size();k++) {
                    for (int r=0;r<4;r++) {
                        int xx=xr1[j-1][k]+dx[r];
                        int yy=yr1[j-1][k]+dy[r];
                        if (!a[xx].test(yy)) {
                            a[xx].set(yy);//[yy]=1;
                            xr1[j].push_back(xx);
                            yr1[j].push_back(yy);
                        }
                    }
                }
            }
            if (i%7==0) {
                j=i/7;
                xr2[j].clear();
                yr2[j].clear();
                for (k=0;k<xr2[j-1].size();k++) {
                    for (int r=0;r<4;r++) {
                        int xx=xr2[j-1][k]+dx[r];
                        int yy=yr2[j-1][k]+dy[r];
                        if (!a[xx].test(yy)){//a[xx][yy]==0) {
                            //a[xx][yy]=2;
                            a[xx].set(yy);
                            res++;
                            xr2[j].push_back(xx);
                            yr2[j].push_back(yy);
                        }
                    }
                }
                if (xr2[j].size()==0) break;
            }
        }
        printf("%d\n",res);
    }
    return 0;
}
