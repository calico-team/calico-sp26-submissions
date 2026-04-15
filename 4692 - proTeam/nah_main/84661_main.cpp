#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int N, P, R, K;
        cin >> N >> P >> R >> K;

        vector<int> E(N);
        for (int i = 0; i < N; i++) {
                cin >> E[i];
        }

        long long dylan_power = P;
        int since_last = 0;
        bool can = true;

        for (int i = 0; i < N; i++) {
            dylan_power -= E[i];
            if (dylan_power < 0) {
                can = false;
                break;
            }

            since_last++;

            if (since_last == K) {
                dylan_power += R;
                since_last = 0;
            }
        }

        if (can){
            cout << "nah i�d win"<<endl;
        }
        else {
            cout << "nah i�d lose"<<endl;
        }
    }

    return 0;
}
