#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (j) cout << ' ';
                cout << (i + 2 * j) % 5;
            }
            cout << '\n';
        }
    }

    return 0;
}
