#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    while (T--) {
        long long N, P, R, K;
        cin >> N >> P >> R >> K;
        
        vector<long long> E(N);
        for (int i = 0; i < N; i++) cin >> E[i];
        
        long long power = P;
        bool defeated = false;
        int curses_defeated = 0;
        
        for (int i = 0; i < N; i++) {
            power -= E[i];
            if (power < 0) {
                defeated = true;
                break;
            }
            curses_defeated++;
            if (curses_defeated % K == 0) {
                power += R;
            }
        }
        
        cout << (defeated ? "nah i'd lose" : "nah i'd win") << "\n";
    }
    
    return 0;
}