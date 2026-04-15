#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

ll a[100000];
ll v[100000][2];
ll dp[100000][2];

int b[100000];

void solve() {
    int n;
    cin>>n;

    for (int i = 0; i < n; i++) {
        cin>>a[i];
    }

    v[0][0] = v[0][1] = a[0];
    dp[0][0] = dp[0][1] = 0;

    for (int i = 1; i < n; i++) {
        v[i][0] = a[i], v[i][1] = a[i - 1];

        dp[i][0] = min(dp[i - 1][0] + abs(v[i][0] - v[i - 1][0]), dp[i - 1][1] + abs(v[i][0] - v[i - 1][1]));
        dp[i][1] = min(dp[i - 1][0] + abs(v[i][1] - v[i - 1][0]), dp[i - 1][1] + abs(v[i][1] - v[i - 1][1])) + abs(v[i][1] - a[i]);
    }

    int p = n - 1;
    int c = dp[p][0] < dp[p][1] ? 0 : 1;
    while(p > 0) {
        b[p] = v[p][c];
        if (dp[p][c] == dp[p - 1][0] + abs(a[p] - v[p][c]) + abs(v[p][c] - v[p - 1][0])) {
            c = 0;
        } else {
            c = 1;
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