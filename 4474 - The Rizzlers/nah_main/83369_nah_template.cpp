#include <iostream>
#include <vector>

using namespace std;

string solve(int N, int P, int R, int K, vector<int> E) {
    for (int i = 0; i < N; i++) {
        if (i % K == 0 && i != 0) {
            P += R;
        }
        if (P >= E[i]) {
            P -= E[i];
        } else {
            return "nah, i'd lose";
        }
        
    }
    return "nah, i'd win";
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
}
