#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        for (int r = 0; r < N; ++r) {
            for (int c = 0; c < M; ++c) {
                cout << (2 * r + c) % 5;
                if (c != M - 1) {
                    cout << " ";
                }
            }
            cout << "\n";
        }
    }
    return 0;
}