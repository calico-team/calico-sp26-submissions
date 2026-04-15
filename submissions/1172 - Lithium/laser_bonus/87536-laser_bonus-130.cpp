#include <bits/stdc++.h>
using namespace std;

long inf = 3000000000000000000;

pair<long,long> f(long a, long b, long c) { // ax+by = c
    long g = gcd(a,gcd(b,c));
    a /= g;
    b /= g;
    c /= g;
    if (gcd(a,b) > 1) {
        return {inf,inf};
    }
    vector<long> x,y,r;
    x = {1,0};
    y = {0,1};
    r = {a,b};
    for (long i = 1; r[i] != 1 && r[i] != -1; i++) {
        long q = r[i-1] / r[i];
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

long inverse(long a, long b, long c) { // ax = c mod b, ax-by = c
    return f(a,-b,c).first%b;
}

long g(long a, long b, long m, long n) { // x = a mod m, x = b mod n, a+cm = b+dn, cm-dn=b-a, x = a+cm
    if (f(m,-n,b-a).first == inf) {
        return inf;
    }
    return ((f(m,-n,b-a).first*m+a)%(m*n)+m*n)%(lcm(m,n));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long t;
    cin >> t;
    while (t--) {
        long k,n,m,p,q;
        cin >> k >> n >> m >> p >> q;
        swap(p,q);
        long ans1 = n*m;
        long ans2 = 0;
        long x0,y0;
        for (long i = 0; i < k; i++) {
            long x,y;
            cin >> x >> y;
            if (i == 0) {
                x0 = x;
                y0 = y;
            }
            x = (x-x0+n)%n;
            y = (y-y0+m)%m;
            long a = g(inverse(p,n,x)%n,inverse(q,m,y)%m,n,m);
            if (((a*p%n)%n != x || (a*q%m)%m != y) && a != inf) {
                // cout << a << "\n";
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
