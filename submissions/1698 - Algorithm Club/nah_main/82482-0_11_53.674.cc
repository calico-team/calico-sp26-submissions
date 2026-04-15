#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, p, r, k;
        cin >> n >> p >> r >> k;
        
        bool win = true;
        for (int i = 1; i <= n; i++) {
            int e;
            cin >> e;
            
            if (!win) continue;
            
            p -= e;
            if (p < 0) {
                win = false;
            } else {
                if (i % k == 0) {
                    p += r;
                }
            }
        }
        
        if (win) cout << "nah i'd win\n";
        else cout << "nah i'd lose\n";
    }
    
    return 0;
}