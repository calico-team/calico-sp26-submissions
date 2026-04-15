#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#include <chrono>
#include <functional>

namespace hashing {
using namespace std;

#define _ull unsigned long long

template<typename T>
static _ull splitmix64(T x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        _ull y = hash<T>{}(x);
        y += 0x9e3779b97f4a7c15;
        y = (y ^ (y >> 30)) * 0xbf58476d1ce4e5b9;
        y = (y ^ (y >> 27)) * 0x94d049bb133111eb;
        return y ^ (y >> 31);
}

template<typename T>
struct splitmix {
        _ull operator()(_ull x) const {
                static const _ull FIXED_RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
                return splitmix64(x + FIXED_RANDOM);
        }
};

_ull hash_combine(_ull a, _ull b) {
        a ^= b + 0x517cc1b727220a95 + (a << 6) + (a >> 2);
        return a;
}

struct pair_hash {
        template<typename T, typename U>
        _ull operator() (const pair<T,U>& p) const {
                return hash_combine(splitmix<T>{}(p.first), splitmix<T>{}(p.second));
        }
};

struct array_hash {
        template<typename T, unsigned long int N>
        _ull operator() (const array<T,N>& a) const {
                _ull hsh = splitmix<T>{}(a[0]);
                for(unsigned long int i=1; i<N; i++) {
                        hsh = hash_combine(hsh, splitmix<T>{}(a[i]));
                }
                return hsh;
        }
};

}
using namespace hashing;


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

// {{{1 chinese io, passes magnus input test in 639 ms https://codeforces.com/contestInvitation/8f3946bc166635d678cce970d902f5f837eb83df
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define ll long long
#include <stdio.h>
#include <stdlib.h>

// china io template
#define BUFSZ (1<<22)
char ibuf[BUFSZ],obuf[BUFSZ];
char* ip=ibuf+BUFSZ, * op=obuf;
#define gc() (ip<ibuf+BUFSZ?*ip++:(fread(ip=ibuf,1,BUFSZ,stdin),*ip++))

ll read() {
        char c;
        int sgn=0;
        while((c=gc())<'0')sgn|=c=='-';
        ll x=-(c-'0');
        while((c=gc())>' ')x=x*10-(c-'0');
        return sgn?x:-x;
}
char* read_str(char* x) { // note no null termination; returns past-end pointer
        char c;
        while((c=gc())<=' ');
        *x++=c;
        while((c=gc())>' ')*x++=c;
        return x;
}
void write_(ll x) {
        if(x<-9) write_(x/10);
        *op++=-(x%10)+'0';
}
void write(ll x) {
        if(x<0) return *op++='-',write_(x);
        write_(-x);
}
void write_str(const char* x) {
        while((*op++=*x++));
        op--;
}

void flush() {
        fwrite(obuf,1,op-obuf,stdout), op=obuf;
}

struct intype { operator ll() { return read(); } };
#define scanf nonsense

#ifdef CHINAIO_TEST
int main() {
        ll x=read();write(x);
        *op++='\n';
        flush();
        char buf[20];
        char* e=read_str(buf);
        *e++=0;
        write_str(buf);
        *op++='\n';
        flush();
}
#endif
// 1}}}
intype in;
void solve() {
        int k=in, n=in,m=in,q=in,p=in;

        vector<array<ll,3>> ast(k);for(ll i=0;i<k;i++)ast[i]={in,in,i};

        ll x0=ast[0][0],y0=ast[0][1];
        for(int i=0;i<k;i++) {
                ast[i][0] = (ast[i][0]-x0+n)%n;
                ast[i][1] = (ast[i][1]-y0+m)%m;
        }

        vector<ll> hs;
        gp_hash_table<ll,array<ll,3>> rep;
        for(int i=1;i<k;i++) {
                ll id = ast[i][0]*q-ast[i][1]*p;
                if(rep.find(id)!=rep.end())rep[id]=min(rep[id],ast[i]);
                else rep[id]=ast[i];
                hs.push_back(id);
                //printf("%d %d %d | %lld\n", ast[i][2],ast[i][0],ast[i][1],id);
        }
        sort(all(hs));hs.resize(unique(all(hs))-hs.begin());

        ll x=ast[0][0],y=ast[0][1];
        ll id0 = x*q-y*p;
        do {
                //printf("%d %d | id %lld\n",x,y,x*q-y*p);
                if(auto it=lower_bound(all(hs),x*q-y*p);it!=hs.end()&&*it==x*q-y*p) {
                        printf("%d\n", rep[x*q-y*p][2]);
                        return;
                }
                //ll l=0,r=1e9;
                //while(l<r) {
                        //ll mid=l+(r-l)/2;
                        
                        //ll xx = x+p*mid, yy=y+q*mid;
                        //if(xx>=n||yy>=m) r=mid;
                        //else l=mid+1;
                //}
                ll l = min((n-x+p-1)/p, (m-y+q-1)/q);
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
