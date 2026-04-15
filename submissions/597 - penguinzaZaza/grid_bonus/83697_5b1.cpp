#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int t, n;

void solve() {
    cin >> n;
    vector<int> a(n);
    for (auto &e: a) cin >> e;
    vector<int> b = a;
    int tt = 500;
    while (tt--) {
        int ch = 0;
        for (int i = 0; i < n; i++) {
            int x = b[i];
            vector<int> c{b[i], (i ? b[i - 1] : b[i]), (i == n - 1 ? b[i] : b[i + 1])};
            sort(c.begin(), c.end());
            b[i] = c[1];
            ch = max(ch, abs(b[i] - x));
        }
        if (!ch) {
            for (auto &e: b) cout << e << ' '; cout << '\n';
            return;
        }
    }
    for (auto &e: b) cout << e << ' '; cout << '\n';
}

int main() {
    cin >> t;
    while (t--) solve();
}