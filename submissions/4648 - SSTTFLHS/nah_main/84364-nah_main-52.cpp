#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int T;
    cin >> T;

    while (T--) {
        int N, P, R, K;
        cin >> N >> P >> R >> K;
        vector<int> E(N);
        for (int i = 0; i < N; i++) {
            cin >> E[i];
        }
        long long pow = P;
        int count = 0;
        bool win = true;
        for (int e : E) {
            pow -= e;
            if (pow < 0) {
                win = false;
                break;
            }
            count++;
            if (count == K) {
                pow += R;
                count = 0;
            }
        }

        cout << (win ? "nah I'd win" : "nah I'd lose") << endl;
    }
}

int main() {
    solve();
    return 0;
}