#include<bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

using ll = long long;

bool solve() {
    int n, p, r, k;
    cin >> n >> p >> r >> k;

    int e[n];
    for (int i = 0; i < n; i++) {
        cin >> e[i];
    }

    for (int i = 1; i <= n; i++) {
        if (p < e[i - 1]) return false;

        p -= e[i - 1];

        if (i % k == 0) {
            p += r;
        }
    }

    return true;
}

int main() {
    fastio;

    int tc;
    cin >> tc;

    while (tc--) {
        if (solve()) {
            cout << "nah i'd win\n";
        } else {
            cout << "nah i'd lose\n";
        }
    }
}