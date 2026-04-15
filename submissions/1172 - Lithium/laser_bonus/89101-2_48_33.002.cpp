#include <bits/stdc++.h>
using namespace std;

long long inf = 3000000000000000000;

pair<long long,long long> f(long long a, long long b, long long c) { // ax+by = c
    long long g = gcd(a,gcd(b,c));
    a /= g;
    b /= g;
    c /= g;
    if (c%gcd(a,b) != 0) {
        return {inf,inf};
    }
    vector<long long> x,y,r;
    x = {1,0};
    y = {0,1};
    r = {a,b};
    for (long long i = 1; r[i] != 1 && r[i] != -1; i++) {
        long long q = r[i-1] / r[i];
        // cout << r[i];
        r.push_back(r[i-1] - q*r[i]);
        x.push_back(x[i-1] - q*x[i]);
        y.push_back(y[i-1] - q*y[i]);
    }
    if (r[r.size()-1] == -1) {
        c *= -1;
    }
    x[x.size()-1] *= c;
    y[y.size()-1] *= c;
    return {x[x.size()-1],y[y.size()-1]};
}

long long inverse(long long a, long long b, long long c) { // ax = c mod b, ax-by = c
    if (f(a,-b,c).first == inf) {
        return inf;
    }
    return (f(a,-b,c).first+b)%b;
}

long long g(long long a, long long b, long long m, long long n) { // x = a mod m, x = b mod n, a+cm = b+dn, cm-dn=b-a, x = a+cm
    if (f(m,-n,b-a).first == inf) {
        return inf;
    }
    return ((f(m,-n,b-a).first*m+a)%(m*n)+m*n)%(lcm(m,n));
}

int main() {
    // cout << inverse(2,1000000,1);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin >> t;
    while (t--) {
        long long k,n,m,p,q;
        cin >> k >> n >> m >> p >> q;
        swap(p,q);
        long long ans1 = n*m;
        long long ans2 = 0;
        long long x0,y0;
        for (long long i = 0; i < k; i++) {
            long long x,y;
            cin >> x >> y;
            if (i == 0) {
                x0 = x;
                y0 = y;
            }
            x = (x-x0+n)%n;
            y = (y-y0+m)%m;
            if (inverse(p,n,x) == inf || inverse(q,m,y) == inf) {
                continue;
            }
            long long a = g(inverse(p,n,x)%n,inverse(q,m,y)%m,n,m);
            if (((a*p%n)%n != x || (a*q%m)%m != y || a < 0 || a >= lcm(n,m)) && a != inf) {
                cout << 1/0;
            }
            if (a != inf) {
                // cout << a << " ";
                if (a == 0) {
                    a += lcm(n,m);
                }
                if (a < ans1) {
                    ans1 = a;
                    ans2 = i;
                }
            }
        }
        cout << ans2 << "\n";
    }
}
