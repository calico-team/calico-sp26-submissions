#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    ll a[n + 5], b[n + 5];
    ll dp[n + 5][5], prv[n + 5][5];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            dp[i][j] = 1e18;
            prv[i][j] = -1;
        }
    }
    dp[0][0] = dp[0][1] = dp[0][2] = 0;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    a[0] = a[1];
    a[n + 1] = a[n];

    for (int i = 1; i <= n; i++) {
        for (int j = -1; j <= 1; j++) {
            for (int k = -1; k <= 1; k++) {
                ll bef = a[i - 1 + k];
                ll cur = a[i + j];
                ll newscore = dp[i-1][k+1] + (ll) abs(cur - bef) + abs(cur - a[i]) + abs(a[i] - a[i-1]);
                /*
                if (i == 2) {
                    cout << "j: " << j << " k: " << k << " score: " << newscore << " " << cur << " " << bef << endl;
                }
                */
                if (newscore < dp[i][j+1]) {
                    dp[i][j+1] = newscore;
                    prv[i][j+1] = k+1;
                }
            }
        }
        /*
        for (int j = 0; j < 3; j++) {
            cout << dp[i][j] << "," << prv[i][j] << " ";
        }
        cout << endl;
        */
    }

    ll argmin = 0;
    for (int i = 1; i < 3; i++) {
        if (dp[n][i] < dp[n][argmin]) {
            argmin = i;
        }
    }

    for (int i = n; i >= 1; i--) {
        b[i] = a[i + argmin - 1];
        argmin = prv[i][argmin];
    }

    for (int i = 2; i < n; i++) {
        vector<ll> c = {a[i], b[i-1], b[i+1]};
        sort(c.begin(), c.end());
        b[i] = c[1];
    }

    for (int i = 1; i <= n; i++) {
        cout << b[i] << " \n" [i == n];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc = 1;
    cin >> tc;

    while (tc--) {
        solve();
    }

    return 0;
}
