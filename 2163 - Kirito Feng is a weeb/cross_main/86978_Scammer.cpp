#include <bits/stdc++.h>
using namespace std;
// typedef long long ll;
void solve() {
    int n, m;
    cin >> n >> m;
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < m; ++c) {
            cout << (r +2 * c) % 5;
            if (c < m - 1) {
                cout << " ";
            }
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}