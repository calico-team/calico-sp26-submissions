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
    int counter = N;
    int gojoPower = P;
    while (counter < N) {
        if (counter % K == 0 && counter != N && counter != 0) {
            gojoPower += R;
        }
        gojoPower -= E[counter];
        counter--;
    }
    if (gojoPower > 0) {
        return "nah i'd win";
    }
    else {
        return "nah i'd lose";
    }
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
