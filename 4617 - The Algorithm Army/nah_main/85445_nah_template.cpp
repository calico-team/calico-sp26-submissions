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
	// YOUR CODE HERE
	long long current_power = P;
    int curses_defeated_since_last_rct = 0;

    for (int i = 0; i < N; i++) {
        // Gojo must have power strictly greater than the curse to win
        if (current_power <= E[i]) {
            return "Gojo has been defeated!";
        }

        // Defeat the curse and lose power
        current_power -= E[i];
        curses_defeated_since_last_rct++;

        // Check if RCT can be used (every K curses)
        if (curses_defeated_since_last_rct == K) {
            current_power += R;
            curses_defeated_since_last_rct = 0; // Reset cooldown counter
        }
    }

    return "Gojo can win!";
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
