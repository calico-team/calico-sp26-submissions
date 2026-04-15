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

        long long* E = new long long[N];

        for (long long i = 0; i < N; i++) {
            cin >> E[i];
        }

        long long defeated = 0;
        bool ok = true;

        for (long long i = 0; i < N; i++) {
            P -= E[i];
            defeated++;

            if (P < 0) {
                ok = false;
                break;
            }

            if (defeated % K == 0) {
                P += R;
            }
        }

        if (ok) cout << "nah i'd win\n";
        else cout << "nah i'd lose\n";

        delete[] E;
    }

    return 0;
}