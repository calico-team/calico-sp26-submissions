#include <bits/stdc++.h>

using namespace std;

signed main() { 
    long long t; cin >> t;
    while (t --) {
        long long n; cin >> n;
        long long most = n * n * n;
        long long least = 0;
        vector<string> lf (n, ""), rf (n, "");
        vector<long long> lw (n, 0), rw (n, 0); 
        vector<long long> lm (n, 0);
        for (long long i = 0; i < n; i ++) {
            for (long long j = 0; j < n; j ++) {
                char c; cin >> c;
                lf[i] += c; 
                if (c == '.') {
                    most -= n;
                    lw[i] ++;
                } 
            }
            lm[i] = n - lw[i];
        }
        for (long long i = 0; i < n; i ++) {
            for (long long j = 0; j < n; j ++) {
                char c; cin >> c;
                rf[i] += c; 
                if (c == '.') {
                    most -= n;
                    rw[i] ++;
                }
            }
            lm[i] = max(lm[i], n - rw[i]);
            most += lw[i] * rw[i];
            least += lm[i];
        }
        cout << most << " " << least << "\n";
    }
    return 0;
}