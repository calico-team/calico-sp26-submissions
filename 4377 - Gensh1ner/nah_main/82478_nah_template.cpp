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
    bool used = false;
    for (int i = 0; i < N; i++) {
        if(i%K==0){
            used=false;
        }
        if (P - E[i] < 0) {
            if(i<K){
                return "nah i'd lose";
            }
            if (used == true) {
                return "nah i'd lose";
            }
            used = true;
            P = P - E[i] + R;
            if (P < 0) {
                return "nah i'd lose";
            }
        } else {
            P -= E[i];
            if (P < 0) {
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
