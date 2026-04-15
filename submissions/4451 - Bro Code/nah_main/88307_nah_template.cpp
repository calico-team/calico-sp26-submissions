#include <iostream>
#include <vector>
using namespace std;

string solve(int N, int P, int R, int K, vector<int> E) {
    int count = 0;
    for (int i = 0; i < N; i++) {
        P -= E[i];
        count++;
        if (P < 0) {
            return "nah i'd lose";
        }
        if (count % K == 0) {
            P += R;
        }
    }
    return "nah i'd win";
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int N, P, R, K;
        cin >> N >> P >> R >> K;
        vector<int> E(N);
        for (int j = 0; j < N; j++) {
            cin >> E[j];
        }
        cout << solve(N, P, R, K, E) << '\n';
    }
    return 0;
}
