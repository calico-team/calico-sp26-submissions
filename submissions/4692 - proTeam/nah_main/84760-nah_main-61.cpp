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

        long long Curse = P;
        int since_last = 0;
        bool can = true;

        for (int i = 0; i < N; i++) {
            Curse -= E[i];
            if (Curse < 0) {
                can = false;
                break;
            }

            since_last++;

            if (since_last == K) {
                Curse += R;
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
