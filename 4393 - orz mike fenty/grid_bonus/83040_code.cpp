#include <iostream>
using namespace std;

#pragma GCC optimize("Ofast,unroll-loops")

#define ll long long
#define MAXN (ll)(1e5)

ll T, N, a[MAXN + 1];

void solve() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }
    for (int i = 2; i < N; i++) {
        if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
            a[i] = max(a[i - 1], a[i + 1]);
        }
        else if (a[i] < a[i - 1] && a[i] < a[i + 1]) {
            a[i] = min(a[i - 1], a[i + 1]);
        }
    }
    for (int i = 1; i <= N; i++) {
        cout << a[i] << " ";
    }
    cout << '\n';
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