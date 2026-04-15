// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b, long long &x, long long &y) {
    if (!b) {x=1;y=0; return a;}
    long long xr,yr;
    long long g = gcd(b,a%b,xr,yr);
    x=yr;
    y=xr-(a/b)*yr;
    return g;
}

void solve() {
    long long K, N, M, P, Q; cin >> K >> N >> M >> P >> Q;
    long long xo = 0;
    long long yo = 0;
    long long tmp;
    long long tmpp;
    long long xg = gcd(N,Q,tmp,tmpp);
    long long rn = N/xg;
    long long rq = Q/xg;
    long long iq;
    gcd(rn,rq,tmp,iq);
    iq%=rn;
    iq=(iq+rn)%rn;
    long long yg = gcd(M,P);
    long long rp = P/yg;
    long long rm = M/yg;
    long long ip;
    gcd(rm,rp,tmp,ip);
    ip%=rm;
    ip=(ip+rm)%rm;
    long long tg = gcd(rn,rm,tmp,tmpp);
    pair<long long, long long> aa = {1e18,-1};
    for (long long i = 0; i < K; i++) {
        long long a, b; cin >> a >> b;
        if (!i) {xo=a; yo=b;}
        if ((((a-xo)%N+N)%N)%xg) {continue;}
        if ((((b-yo)%M+M)%M)%yg) {continue;}
        long long f = ((((a-xo)%N+N)%N)/xg)*iq%rn;
        long long s = ((((b-yo)%M+M)%M)/yg)*ip%rm;
        if (((s-f+rm)%rm)%tg) {continue;}
        long long in;
        gcd(rn/tg,rm/tg,in,tmp);
        in%=(rm/tg);
        in=(in+rm/tg)%(rm/tg);
        long long k = (((((s-f)%rm+rm)%rm)/tg)*in)%(rm/tg);
        long long t = f+rn*k;
        if (!t) {t=rn*rm/tg;}
        pair<long long, long long> p = {t,i};
        aa=min(aa,p);
    }
    cout << aa.second << endl;
}

int main() {
	long long T; cin >> T;
    while (T--) {solve();}
}
