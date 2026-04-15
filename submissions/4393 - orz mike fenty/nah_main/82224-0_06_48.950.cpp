#include <iostream>
using namespace std;

#pragma GCC optimize("Ofast,unroll-loops")

#define ll long long

ll T, N, P, R, K;

void solve() {
    cin >> N >> P >> R >> K;
    for (int i = 1; i <= N; i++) {
        ll t;
        cin >> t;
        P -= t;
        if (P < 0) {
            cout << "nah i'd lose" << '\n';
            return;
        }
        if (i % K == 0) {
            P += R;
        }
    }
    if (P < 0) {
        cout << "nah i'd lose" << '\n';
    }
    else {
        cout << "nah i'd win" << '\n';
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}