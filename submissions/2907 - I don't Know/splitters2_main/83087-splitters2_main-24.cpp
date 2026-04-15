#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int n, p, r, k;
        cin >> n >> p >> r >> k;
        
        bool win = true;
        int defeated = 0;
        
        for (int i = 0; i < n; i++) {
            int energy;
            cin >> energy;
            
            if (!win) continue;
            
            p -= energy;
            
            if (p < 0) {
                win = false;
            } else {
                defeated++;
                if (defeated == k) {
                    p += r;
                    defeated = 0;
                }
            }
        }
        
        if (win) {
            cout << "nah i'd win" << endl;
        } else {
            cout << "nah i'd lose" << endl;
        }
    }
    
    return 0;
}