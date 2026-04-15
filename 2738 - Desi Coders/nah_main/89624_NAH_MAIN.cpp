#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N, P, R, K;
        cin >> N >> P >> R >> K;

        vector<int> E(N);
        for (int i = 0; i < N; i++) cin >> E[i];

        long long dylan_power = P;
        bool ok = true;

        for (int i = 0; i < N; i++) {
            if (dylan_power < E[i]) {
                ok = false;
                break;
            }

            dylan_power -= E[i];

            if ((i + 1) % K == 0) {
                dylan_power += R;
            }
        }

        if (ok) cout << "nah i’d win\n";
        else cout << "nah i’d lose\n";
    }

    return 0;
}