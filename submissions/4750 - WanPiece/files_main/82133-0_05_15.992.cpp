#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    string s, t;
    cin >> s >> t;

    int n = (int) s.size();
    int m = (int) t.size();

    int j = 0;
    for (int i = 0; i < n; i++) {
        if (j < m && t[j] == s[i]) {
            j++;
        } else {
            s[i] = '#';
        }
    }

    cout << s << '\n';
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
