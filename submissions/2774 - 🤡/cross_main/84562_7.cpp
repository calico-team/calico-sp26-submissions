#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int st = (2*i)%5;
        for (int i = 0; i < m; i++) cout << st << ' ', st++, st %= 5;
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T; cin >> T;
    while (T--) solve();
}

