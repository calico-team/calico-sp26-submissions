#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, P, R, K;
        cin >> N >> P >> R >> K;

        int dylan_power = P;

        bool lose = false;

        for (int i = 1; i <= N; i++) {
            int Ei;
            cin >> Ei;

            if (dylan_power < Ei) {
                cout << "nah i'd lose" << endl;
                lose = true;
                for (int j = i + 1; j <= N; j++) cin >> Ei;
                break;
            }

            dylan_power -= Ei;

            if (i % K == 0) {
                dylan_power += R;
            }
        }

        if (!lose) {
            cout << "nah i'd win" << endl;
        }
    }

    return 0;
}

void read_your_input() {
}