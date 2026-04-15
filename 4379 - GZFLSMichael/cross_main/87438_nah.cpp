#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                int val = (i + 2 * j) % 5;
                if (j > 0) cout << ' ';
                cout << val;
            }
            cout << '\n';
        }
    }
    return 0;
}