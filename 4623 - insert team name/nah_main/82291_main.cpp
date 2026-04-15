#include <bits/stdc++.h>

using namespace std;

signed main() { 
    long long t; cin >> t;
    while (t --) {
        long long n, p, r, k; cin >> n >> p >> r >> k;
        vector<long long> e (n);
        bool ans = true;
        for (long long i = 0; i < n; i ++) {
            cin >> e[i];
            p -= e[i];
            if (p < 0) {
                ans = false;
            }
            if ((i + 1) % k == 0) {
                p += r;
            }
        }
        if (ans) {
            cout << "nah i'd win\n";
        } else {
            cout << "nah i'd lose\n";
        }
    }
    return 0;
}