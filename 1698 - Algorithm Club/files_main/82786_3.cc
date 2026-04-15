#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        string a, b;
        cin >> a >> b;
        
        int b_idx = 0;
        string ans = "";
        
        for (int i = 0; i < a.length(); i++) {
            if (b_idx != b.length() && a[i] == b[b_idx]) {
                ans += a[i];
                b_idx++;
            } else {
                ans += '#';
            }
        }
        
        cout << ans << "\n";
    }
    
    return 0;
}