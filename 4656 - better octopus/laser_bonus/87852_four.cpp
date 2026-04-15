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
        int k=in, n=in,m=in,q=in,p=in;

        vector<array<ll,3>> ast(k);for(ll i=0;i<k;i++)ast[i]={in,in,i};

        map<ll,array<ll,3>> rep;
        for(int i=1;i<k;i++) {
                ll id = ast[i][0]*q-ast[i][1]*p;
                if(rep.find(id)!=rep.end())rep[id]=min(rep[id],ast[i]);
                else rep[id]=ast[i];
                //printf("%d %d %d | %lld\n", ast[i][2],ast[i][0],ast[i][1],id);
        }

        ll x=ast[0][0],y=ast[0][1];
        ll id0 = x*q-y*p;
        do {
                //printf("%d %d | id %lld\n",x,y,x*q-y*p);
                if(rep.find(x*q-y*p) != rep.end()) {
                        printf("%d\n", rep[x*q-y*p][2]);
                        return;
                }
                ll l=0,r=1e9;
                while(l<r) {
                        ll mid=l+(r-l)/2;
                        
                        ll xx = x+p*mid, yy=y+q*mid;
                        if(xx>=n||yy>=m) r=mid;
                        else l=mid+1;
                }
                x=x+p*l;
                y=y+q*l;
                //printf("%d %d | id %lld\n",x,y,x*q-y*p);
                x%=n, y%=m;
        } while(x*q-y*p != id0);
        printf("%d\n",0);
}

int main()
{
        int tt=in;
        for(int ttn=0;ttn<tt;ttn++)
        {
        solve();
        }
}
