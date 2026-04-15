#include <bits/stdc++.h>
using namespace std;

void solve() {
    int T;
    cin >> T;
    while (T--) {
        int N, P, R, K;
        cin >> N >> P >> R >> K;
        vector<int> E(N);
        for (int i = 0; i < N; i++) cin >> E[i];

        int dylan_power = P;
        int charges = 0;

        for (int i = 0; i < N; i++) {
            // Use RCT if needed before taking damage
            while (dylan_power - E[i] < 0 && charges > 0) {
                dylan_power += R;
                charges--;
            }

            if (dylan_power - E[i] < 0) {
                cout << "nah i'd lose\n";
                goto next_case;
            }

            dylan_power -= E[i];

            // After defeating this curse, check if we gain a charge
            if ((i + 1) % K == 0) {
                charges++;
            }
        }

        cout << "nah i'd win\n";
        next_case:;
    }
}

void read_your_input() {
    solve();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    read_your_input();
    return 0;
}