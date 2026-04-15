#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    while (T--) {
        long long N, P, R, K;
        cin >> N >> P >> R >> K;
        vector<long long> E(N);
        for (int i = 0; i < N; ++i) {
            cin >> E[i];
        }
        
        bool win = true;
        for (int i = 0; i < N; ++i) {
            if (P < E[i]) {
                win = false;
                break;
            }
            P -= E[i];
            
            if (i >= K - 1) { 
                P += R;
            }
        }
        
        if (win) {
            cout << "nah i'd win\n";
        } else {
            cout << "nah i'd lose\n";
        }
    }
    return 0;
}

