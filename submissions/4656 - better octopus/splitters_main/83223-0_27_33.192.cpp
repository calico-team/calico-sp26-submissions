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


template<class F>
struct y_combinator {
        F f;
        y_combinator(F&& f) : f(f) {}
        template<class ...args>
        decltype(auto) operator() (args&&... a) {
                return f(*this, forward<args>(a)...);
        }
};

struct frac {
        ll n, d;
        frac() : n(0), d(1) {}
        frac(ll n) : n(n), d(1) {}
        frac(ll n_, ll d_) : n(n_), d(d_) {
                assert(d != 0);
                ll g = gcd(n, d);
                n/=g; d/=g;
        }

        frac& operator+=(const frac& o) {
                ll g = gcd(d, o.d);
                ll d2 = o.d / g * d;
                n = o.d / g * n;
                n += d / g * o.n;
                return *this = frac(n, d2);
        }
        frac& operator-=(const frac& o) {
                ll g = gcd(d, o.d);
                ll d2 = o.d / g * d;
                n = o.d / g * n;
                n -= d / g * o.n;
                return *this = frac(n, d2);
        }
        frac& operator*=(const frac& o) {
                n*=o.n;
                d*=o.d;
                return *this = frac(n,d);
        }
        frac& operator/=(const frac& o) {
                assert(o.n != 0);
                n*=o.d;
                d*=o.n;
                return *this = frac(n,d);
        }
        friend frac operator+(frac a, const frac& b) { return a+=b; }
        friend frac operator-(frac a, const frac& b) { return a-=b; }
        friend frac operator*(frac a, const frac& b) { return a*=b; }
        friend frac operator/(frac a, const frac& b) { return a/=b; }

        friend bool operator<(frac a, const frac& b) {
                //a-=b;
                //return a.n<0;
                return a.n*b.d < b.n*a.d;
        }
        friend bool operator==(frac a, const frac& b) {
                return a.n==b.n && a.d==b.d;
                //a-=b;
                //return a.n == 0;
        }
        friend bool operator!=(frac a, const frac& b) { return !(a==b); }
        friend bool operator>(frac a, const frac& b) { return !(a<b) && a!=b; }

        explicit operator double() { return 1.L * n / d; }
};


void solve() {
        int n=in, m=in;

        vector mp(n,vector<char>(m));

        for(auto&r:mp)for(auto&x:r)x=in;

        vector dp(n,vector<frac>(m, -1));

        auto solve = y_combinator([&](auto&& solve, int i, int j) -> frac {
                //printf("solve %d %d\n", i, j);
                if(i<0||i>=n||j<0||j>=m) return 1;
                if(!(dp[i][j]<0)) return dp[i][j];
                dp[i][j] = 0;

                char c = mp[i][j];
                assert(c!='.');

                if(c=='>') return dp[i][j]=solve(i,j+1);
                if(c=='<') return dp[i][j]=solve(i,j-1);
                if(c=='^') return dp[i][j]=solve(i-1,j);
                if(c=='v') return dp[i][j]=solve(i+1,j);

                if(c=='X') return 0;

                if(c=='S') {
                        int nx=0;
                        for(int di=-1;di<=1;di++) for(int dj=-1;dj<=1;dj++) if(abs(di)+abs(dj)==1) {
                                if(mp[i+di][j+dj]=='.') continue;
                                if(mp[i+di][j+dj]=='>' && dj==-1) continue;
                                if(mp[i+di][j+dj]=='<' && dj==1) continue;
                                if(mp[i+di][j+dj]=='^' && di==1) continue;
                                if(mp[i+di][j+dj]=='v' && di==-1) continue;

                                nx++;
                                dp[i][j] += solve(i+di, j+dj);
                        }
                        dp[i][j] /= nx;
                        return dp[i][j];
                }
                //printf("char %d %c\n", c, c);
                assert(0);
        });

        frac ans = solve(0,0);

        printf("%lld %lld\n", ans.n, ans.d);
}

int main()
{
        int tt=in;
        for(int ttn=0;ttn<tt;ttn++)
        {
                solve();
        }
}
