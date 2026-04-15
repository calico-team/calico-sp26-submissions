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
    int defeated = 0;

    for (int i = 0; i < N; i++) {

        if (P < E[i]) {
			// mtlb ye k agr K times defeat kar chuka hai, toh reverse cursed technique use kar sakta hai
            if (defeated > 0 && defeated % K == 0) {
                P += R;
            }
        }

        if (P < E[i]) {
            return "nah i'd lose";
        }

        P -= E[i];
        defeated++;
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