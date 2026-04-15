#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i: a) cin >> i;
    
    // solve
    vector<int> l(n), r(n);
    l[0] = r[0] = a[0];

    for (int i = 1; i < n; i++) {
        if (a[i] < l[i-1]) {
            l[i] = a[i];
            r[i] = l[i-1];
        } else if (a[i] > r[i-1]) {
            l[i] = r[i-1];
            r[i] = a[i];
        } else {
            l[i] = r[i] = a[i];
        }
    }

    vector<int> b(n);
    b[n-1] = l[n-1];
    for (int i = n-2; i >= 0; i--) {
        b[i] = max(l[i], min(b[i+1], r[i]));
    }

    // ans
    for (int i : b) cout << i << ' ';
    cout << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}