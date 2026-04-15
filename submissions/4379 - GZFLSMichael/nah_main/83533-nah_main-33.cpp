#include <bits/stdc++.h>
using namespace std;
int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, P, R, K;
        cin >> N >> P >> R >> K;
        bool win = true;
        for (int i = 0; i < N; i++) {
            int e;
            cin >> e;
            if (!win) continue;
            P -= e;
            if (P < 0) {
                win = false;
                continue;
            }
            if (i % K == 0) {
                P += R;
            }
        }
        if(win) cout << "nah i'd win";
        else cout << "nah i'd lose";
    }
    return 0;
}