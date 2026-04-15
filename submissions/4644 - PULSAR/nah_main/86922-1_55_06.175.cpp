#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        long long N, P, R, K;
        cin >> N >> P >> R >> K;

        bool win = true;
        long long cnt = 0;
        for (long long i = 0; i < N; ++i) {
            long long e;
            cin >> e;
            if (!win) continue;

            if (P < e) {
                win = false;
                continue;
            }
            P -= e;
            cnt++;
            if (cnt >= K) {
                P += R;
                cnt = 0;
            }
        }

        cout << (win ? "nah i'd win\n" : "nah i'd lose\n");
    }
    return 0;
}

