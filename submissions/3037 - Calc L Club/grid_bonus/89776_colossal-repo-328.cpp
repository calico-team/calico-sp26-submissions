#include <bits/stdc++.h>
using namespace std;

const long long INF = LLONG_MAX;
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n), b(n);
        int mi = INT_MAX, ma = INT_MIN;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            mi = min(mi,a[i]);
            ma = max(ma,a[i]);
        }
        int R = ma-mi+1;
        vector<long long> dp(R, INF), ndp(R, INF);
        vector<vector<int>> p(n, vector<int>(R, -1));
        for (int v = 0; v < R; v++) dp[v] = llabs(a[0]-mi-v);
        for (int i = 1; i < n; i++) {
            for (int v = 0; v < R; v++) {
                long long s = INF;
                int bestp = -1;
                for (int pv = 0; pv < R; pv++) {
                    long long cost = dp[pv] + llabs(v-pv);
                    if (cost < s) {
                        s = cost;
                        bestp = pv;
                    }
                }
                ndp[v] = s+llabs(a[i]-mi-v);
                p[i][v] = bestp;
            }
            auto temp = dp;
            dp = ndp;
            ndp = temp;
        }
        long long s = INF;
        int l = 0;
        for (int v = 0; v < R; v++) {
            if (dp[v] < s) {
                s = dp[v];
                l = v;
            }
        }
        int cur = l;
        for (int i = n-1; i >= 0; i--) {
            b[i] = mi+cur;
            if (i) cur = p[i][cur];
        }
        for (int i = 0; i < n; i++) cout << b[i] << ' ';
        cout << endl;
    }
}