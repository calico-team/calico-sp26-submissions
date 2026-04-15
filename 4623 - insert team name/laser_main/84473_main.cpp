#include <bits/stdc++.h>

using namespace std;

signed main() { 
    long long t; cin >> t;
    while (t --) {
        long long k, n, m, p, q; cin >> k >> n >> m >> p >> q;
        long long lx, ly, fx, fy;
        map<pair<long long, long long>, long long> a;
        for (long long i = 0; i < k; i ++) {
            long long f, s;
            cin >> f >> s;
            a[{f,s}] = i;
            if (i == 0) {
                fx = f; fy = s;
            }
        }
        lx = fx + q; ly = fy + p;
        while (lx != fx || ly != fy) {
            lx += n; ly += m;
            lx %= n; ly %= m;
            // cerr << lx << " " << ly << "\n";
            if (a.find({lx, ly}) != a.end()) {
                cout << a[{lx, ly}] << "\n";
                break;
            }
            lx += q; ly += p;
        }
    }
    return 0;
}