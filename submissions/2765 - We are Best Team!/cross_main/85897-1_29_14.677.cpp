#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cout << (i + 2 * j) % 5;
                if (j != M - 1) cout << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}