#include <bits/stdc++.h>

using namespace std;

signed main() { 
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long t; cin >> t;
    while (t --) {
        long long n; cin >> n;
        long long most = n * n * n;
        long long least = 0;
        vector<string> lf (n, ""), rf (n, "");
        vector<long long> lw (n, 0), rw (n, 0); 
        vector<long long> lm (n, 0);
        for (long long i = 0; i < n; i ++) {
            cin >> lf[i];
            for (int j = 0; j < n; j ++) {
                if (lf[i][j] == '.') lw[i] ++;
            }
            most -= lw[i] * n;
            lm[i] = n - lw[i];
        } 
        for (long long i = 0; i < n; i ++) {
            cin >> rf[i];
            for (int j = 0; j < n; j ++) {
                if (rf[i][j] == '.') rw[i] ++;
            }
            most -= rw[i] * n;
            lm[i] = max(lm[i], n - rw[i]);
            most += lw[i] * rw[i];
            least += lm[i];
        }
        cout << most << " " << least << "\n";
    }
    return 0;
}