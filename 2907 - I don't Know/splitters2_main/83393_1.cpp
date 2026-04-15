#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        long long p;
        int n, r, k, e, c = 0;
        cin >> n >> p >> r >> k;
        
        bool ok = true;
        for (int i = 0; i < n; i++) {
            cin >> e;
            if (!ok) continue;
            
            p -= e;
            if (p < 0) {
                ok = false;
            } else {
                c++;
                if (c == k) {
                    p += r;
                    c = 0;
                }
            }
        }
        
        if (ok) cout << "nah i'd win\n";
        else cout << "nah i'd lose\n";
    }
    return 0;
}