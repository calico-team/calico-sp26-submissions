#include <iostream>
#include <vector>

using namespace std;

/**
 * Output whether Gojo will win the fight.
 *
 * N: Number of curses
 * P: Gojo's starting power
 * R: Amount of power Gojo can restore with Reverse Cursed Technique
 * K: The cooldown of Reverse Cursed Technique
 * E: List of power levels of curses
 */
string solve(int N, int P, int R, int K, vector<int> E) {
    bool ableToRestore = false;
    
    int sum = 0;
    for (auto i : E) {
        sum +=i;
    }
    if (sum <= P) {
        return "nah i'd win";
    }

    // YOUR CODE HERE
    for (int i = 0; i < N; i++) {
        ableToRestore = ((i % K) == 0 && i != 0) ? true : ableToRestore;
        
        start:

        if (P >= E[i]) {
            P -= E[i];
        } else {
            if (ableToRestore) {
                P += R;
                ableToRestore = false;
                goto start;
            } else {
                return "nah i'd lose";
            }
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
}
