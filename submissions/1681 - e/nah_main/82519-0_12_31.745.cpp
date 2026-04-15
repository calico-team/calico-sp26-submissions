#include <iostream>
#include <vector>

using namespace std;

/**
 * Output whether Gojo will win the fight.
 * * N: Number of curses
 * P: Gojo's starting power
 * R: Amount of power Gojo can restore with Reverse Cursed Technique
 * K: The cooldown of Reverse Cursed Technique
 * E: List of power levels of curses
 */
string solve(int N, int P, int R, int K, vector<int> E) {
    long long power = P;
    
    for (int i = 0; i < N; i++) {
        power -= E[i];
        
        if (power < 0) {
            return "nah i'd lose";
        }
        
        int curses_defeated = i + 1;
        if (curses_defeated % K == 0) {
            power += R;
        }
    }
    
    return "nah i'd win";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
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