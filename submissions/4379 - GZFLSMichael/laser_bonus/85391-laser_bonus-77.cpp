#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int K, N, M, P, Q;
        cin >> K >> N >> M >> P >> Q;
        int x[100], y[100];
        for (int i = 0; i < K; i++) {
            cin >> x[i] >> y[i];
        }
        int curX = x[0], curY = y[0];
        int ans = -1;
        while (true) {
            curX = (curX + Q) % N;
            curY = (curY + P) % M;
            for (int i = 1; i < K; i++) {
                if (curX == x[i] && curY == y[i]) {
                    ans = i;
                    break;
                }
            }
            if (ans != -1) break;
            if (curX == x[0] && curY == y[0]) {
                ans = 0;
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}