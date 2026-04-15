#include <bits/stdc++.h>

using namespace std;

int main() { 
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int t; cin >> t;
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
        lx = fx; ly = fy;
        int t = 0;
        while (true){
            if (a.find({lx, ly}) != a.end()) {
                ++t;
                if(t == 2){
                    cout << a[{lx, ly}] << "\n";
                    break;
                }
            }
            lx += q; ly += p;
            lx %= n; ly %= m;
        }
    }
    return 0;
}