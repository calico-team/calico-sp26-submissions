#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int t;
    if (!(cin >> t)) return;
    
    while (t--) {
        int n, k;
        long long p, r; 
        cin >> n >> p >> r >> k;
        
        vector<long long> curses(n);
        for(int i = 0; i < n; i++) {
            cin >> curses[i];
        }
        
        bool win = true;
        
        for(int i = 0; i < n; i++) {
            p -= curses[i]; // Fight the curse
            
            if(p < 0) { // Check if defeated
                win = false;
                break;
            }
            
            if((i + 1) % k == 0) { // Heal if K curses defeated
                p += r;
            }
        }
        
        if(win) cout << "nah i'd win\n";
        else cout << "nah i'd lose\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
    
    return 0;
}
