#include<bits/stdc++.h>
using namespace std;
using ll = long long;

/**
 * Output whether Gojo will win the fight.
 *
 * N: Number of curses
 * P: Gojo's starting power
 * R: Amount of power Gojo can restore with Reverse Cursed Technique
 * K: The cooldown of Reverse Cursed Technique
 * E: List of power levels of curses
 */

int main() {
    int T;
    cin >> T;
    while(T--) {
        int N, P, R, K;
        cin >> N >> P >> R >> K;
        vector<int> E(N);
        for (int j = 0; j < N; j++) {
                cin >> E[j];
        }

        int curpower = P;
        bool state = false;
        for(int i = 0; i < N; i++) {
            curpower -= E[i];

            if(curpower < 0) { state = true; break; }

            if ((i + 1) % K == 0) {
                curpower += R;
            }
        }
        if(curpower >= 0) cout << "nah i'd win" << '\n';
        else cout << "nah i'd lose" << '\n';
    }
}