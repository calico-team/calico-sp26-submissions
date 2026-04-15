#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

ll a[100000];
ll v[100000][3];
ll dp[100000][3];

int b[100000];

void solve() {
    int n;
    cin>>n;

    for (int i = 0; i < n; i++) {
        cin>>a[i];
    }

    v[0][0] = v[0][1] = v[0][2] = a[0];
    dp[0][0] = dp[0][1] = dp[0][2] = 0;

    for (int i = 1; i < n - 1; i++) {
        v[i][0] = a[i], v[i][1] = a[i - 1], v[i][2] = a[i + 1];

        dp[i][0] = min(min(dp[i - 1][0] + abs(v[i][0] - v[i - 1][0]), dp[i - 1][1] + abs(v[i][0] - v[i - 1][1])), dp[i - 1][2] + abs(v[i][0] - v[i - 1][2])) + abs(v[i][0] - a[i]);
        dp[i][1] = min(min(dp[i - 1][0] + abs(v[i][1] - v[i - 1][0]), dp[i - 1][1] + abs(v[i][1] - v[i - 1][1])), dp[i - 1][2] + abs(v[i][1] - v[i - 1][2])) + abs(v[i][1] - a[i]);
        dp[i][2] = min(min(dp[i - 1][0] + abs(v[i][2] - v[i - 1][0]), dp[i - 1][1] + abs(v[i][2] - v[i - 1][1])), dp[i - 1][2] + abs(v[i][2] - v[i - 1][2])) + abs(v[i][2] - a[i]);
    }

    v[n - 1][0] = v[n - 1][1] = v[n - 1][2] = a[n - 1];
    dp[n - 1][0] = dp[n - 1][1] = dp[n - 1][2] = min(min(dp[n - 2][0] + abs(v[n - 1][0] - v[n - 2][0]), dp[n - 2][1] + abs(v[n - 1][0] - v[n - 2][1])), dp[n - 2][2] + abs(v[n - 1][0] - v[n - 2][2])) + abs(v[n - 1][0] - a[n - 1]);

    int p = n - 1;
    int c = 0;
    if (dp[p][1] < dp[p][c]) c = 1;
    if (dp[p][2] < dp[p][c]) c = 2;
    while(p > 0) {
        b[p] = v[p][c];
        if (dp[p][c] == dp[p - 1][0] + abs(a[p] - v[p][c]) + abs(v[p][c] - v[p - 1][0])) {
            c = 0;
        } else if (dp[p][c] == dp[p - 1][1] + abs(a[p] - v[p][c]) + abs(v[p][c] - v[p - 1][1])) {
            c = 1;
        } else {
            c = 2;
        }
        p--;
    }
    b[p] = v[p][c];

    for (int i = 0; i < n; i++) {
        cout << b[i] << " ";
    }
    cout << "\n";
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int T;
    cin>>T;
    while(T--) {
        solve();
    }
    
    return 0;
}