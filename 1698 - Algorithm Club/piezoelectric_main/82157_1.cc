#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int l, w, e, r;
        cin >> l >> w >> e >> r;
        
        int ans = e / (2 * (l + w) * r);
        cout << ans << "\n";
    }
    
    return 0;
}