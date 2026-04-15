#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int N, M;
    cin >> N >> M;


    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {

            if (j == 0) cout << ' ';
            cout << (i + 2 * j) % 5;
        }

        cout << '\n';
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) solve();

    return 0;
}