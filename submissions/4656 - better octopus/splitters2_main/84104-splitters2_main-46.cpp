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
        int p=in,a=in,b=in;


        // 2^a 3^b

        vector<string> sol;
        
        sol.push_back(".X.>");
        // divmods by 2 first
        for(int i=0;i<a;i++) {
                int m=p%2;
                p/=2;
                sol.push_back(".>.>");
                if(m==0) {
                        sol.push_back(".SX>");
                }
                else if(m==1) {
                        sol.push_back(".Sv>");
                }
                else assert(0);
        }


        // divmods by 3 next
        for(int i=0;i<b;i++) {
                int m=p%3;
                p/=3;
                sol.push_back("v>.>");
                if(m==0) {
                        sol.push_back(">XX>");
                }
                else if(m==1) {
                        sol.push_back(">Xv>");
                }
                else if(m==2) {
                        sol.push_back(">vv>");
                }
                else assert(0);
                sol.push_back(">S>>");
        }


        //
        sol.push_back("v>.X");
        reverse(all(sol));

        printf("4 %d\n", sol.size());
        for(int i=0;i<4;i++) {
                for(auto x:sol)printf("%c",x[i]);
                printf("\n");
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
