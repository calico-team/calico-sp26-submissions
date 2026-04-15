#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<string> s1(n), s2(n);
    for (int i = 0; i < n; i++) cin >> s1[i];
    for (int i = 0; i < n; i++) cin >> s2[i];

    int mx = 0, mn = 0;

    for (int i = 0; i < n; i++) {
        int a = 0, b = 0;
        for (int j = 0; j < n; j++) {
            if (s1[i][j] == '#') a++;
            if (s2[i][j] == '#') b++;
        }
        
        mx += a * b;
        mn += max(a, b);
    }

    cout << mx << " " << mn << "\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    if (cin >> t) {
        while (t--) solve();
    }
    
    return 0;
}