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
    int count = 0;

    for (int i = 0; i < N; i++) {

        if (count > 0 && count % K == 0) {
            if (P < E[i]) {
                P += R;
            }
        }

        P -= E[i];
        count++;

        if (P < 0) {
            return "nah i'd lose";
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
