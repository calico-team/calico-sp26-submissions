#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, P, R, K;
        cin >> N >> P >> R >> K;
        vector<int> E(N);
        for (int i = 0; i < N; ++i) cin >> E[i];

        int power = P;
        int count = 0;
        bool win = true;
        for (int i = 0; i < N; ++i) {
            power -= E[i];
            if (power < 0) {
                win = false;
                break;
            }
            count++;
            if (count == K) {
                power += R;
                count = 0;
            }
        }
        if (win)
            cout << "nah i’d win" << endl;
        else
            cout << "nah i’d lose" << endl;
    }
    return 0;
}
