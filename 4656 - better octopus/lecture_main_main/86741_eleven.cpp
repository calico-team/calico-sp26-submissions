// {{{1
extern "C" int __lsan_is_turned_off() { return 1; }
#include <bits/stdc++.h>
using namespace std;

#include <tr2/dynamic_bitset>
using namespace tr2;
#include <ext/pb_ds/assoc_container.hpp>

#define ll long long
#define inf 0x3f3f3f3f
#define infl 0x3f3f3f3f3f3f3f3fll

#include <assert.h>
#ifdef DEBUG
#define dprintf(args...) fprintf(stderr,args)
#endif
#ifndef DEBUG
#define dprintf(args...) 69
#endif
#define all(x) (x).begin(), (x).end()
struct cintype { template<typename T> operator T() { T x; cin>>x; return x; } };
// 1}}}
cintype in;

void solve() {
        int n=in,m=in,k=in;

        vector mp0(n,vector<int>(m));
        vector au(n,vector<int>(m));
        for(auto&r:mp0)for(auto&c:r)c=char(in)=='-';
        for(int i=0;i<n;i++) {
                int c=0;
                for(int j=0;j<m;j++) {
                        if(mp0[i][j])c++;
                        else au[i][j]=min(au[i][j],c);
                }
                c=0;
                for(int j=m-1;~j;j--) {
                        if(mp0[i][j])c++;
                        else au[i][j]=min(au[i][j],c);
                }
        }

        int w = n+m;
        vector o(w,vector<int>(w));
        vector a(w,vector<int>(w));

        for(int i=0;i<n;i++)for(int j=0;j<m;j++)o[i+j][i+m-1-j]=mp0[i][j];
        for(int i=0;i<n;i++)for(int j=0;j<m;j++)a[i+j][i+m-1-j]=au[i][j];

        auto p=o;
        for(int i=1;i<w;i++)for(int j=0;j<w;j++)p[i][j]+=p[i-1][j];
        for(int i=0;i<w;i++)for(int j=1;j<w;j++)p[i][j]+=p[i][j-1];

        //for(int i=0;i<w;i++) {
                //for(int j=0;j<w;j++) {
                        //printf("%d",o[i][j]);
                //}
                //printf("\n");
        //}

        auto ge = [&](int i, int j) {
                if(i<0||j<0) return 0;
                return p[i][j];
        };

        auto check = [&](int d) -> bool {
                for(int i=0;i<w;i++) for(int j=0;j<w;j++) {
                        int s = ge(i,j)-ge(i-d,j)-ge(i,j-d)+ge(i-d,j-d);
                        //printf("%d %d | %d : %d\n", i, j, d, s);
                        if(s>=k) return true;
                }
                return false;
        };

        int l=0, r=n+m;
        while(l<r) {
                int m=l+(r-l)/2;
                if(check(m)) r=m;
                else l=m+1;
        }

        //printf("min dist = %d\n", l-1);

        vector<array<int,2>> ans;
        for(int i=0;i<w;i++) for(int j=0;j<w;j++) {
                int s = ge(i,j)-ge(i-l,j)-ge(i,j-l)+ge(i-l,j-l);
                //printf("%d %d | %d : %d\n", i, j, l, s);
                if(s>=k) {
                        for(int k=i;k>i-l&&k>=0;k--) {
                                for(int r=j;r>j-l&&r>=0;r--) {
                                        //printf("%d %d | %d\n",k,r,o[k][r]);
                                        if(o[k][r])ans.push_back({k,r});
                                }
                        }
                        goto don;
                }
        }don:
        assert(ans.size()>=k);
        for(int i=0;i<k;i++) {
                printf("%d %d\n", (ans[i][0]+ans[i][1]-m+1)/2, (ans[i][0]-ans[i][1]+m-1)/2);
        }
}

int main()
{
        int tt=in;
        for(int ttn=0;ttn<tt;ttn++)
        {
                solve();
        }
}
