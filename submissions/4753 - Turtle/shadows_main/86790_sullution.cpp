#include <bits/stdc++.h>
using namespace std;

void solve() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<string> s1(n), s2(n);

        for (int i = 0; i < n; i++) cin >> s1[i];
        for (int i = 0; i < n; i++) cin >> s2[i];

        vector<long long> col(n, 0), row(n, 0);

        // count columns from S1
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (s1[i][j] == '#') {
                    col[j]++;
                }
            }
        }

        // count rows from S2
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (s2[i][j] == '#') {
                    row[i]++;
                }
            }
        }

        long long mn = 0, mx = 0;

        for (int i = 0; i < n; i++) {
            mn += max(col[i], row[i]);
            mx += col[i] * row[i];
        }

        cout << mx << " " << mn << "\n";
    }
}

int main() {
    solve();
    return 0;
}