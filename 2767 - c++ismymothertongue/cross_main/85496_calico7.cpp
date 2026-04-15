#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int N, M;
    if (!(cin >> N >> M)) return;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            
            int val = (i + 2 * j) % 5;
            cout << val << (j == M - 1 ? "" : " ");
        }
        cout << "\n";
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    if (cin >> T) {
        while (T--) solve();
    }
    return 0;
}