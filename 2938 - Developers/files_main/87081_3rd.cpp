#include <iostream>
#include <string>

using namespace std;

void solve() {
    int t;
    if (!(cin >> t)) return;
    
    while (t--) {
        string a, b;
        cin >> a >> b;
        
        string result = "";
        int j = 0;
        
        // Iterate through every character in string a
        for (int i = 0; i < (int)a.length(); i++) {
            // Check if we still need to match characters in b
            if (j < (int)b.length() && a[i] == b[j]) {
                result += a[i];  // Keep the character
                j++;             // Move pointer for b
            } else {
                result += '#';   // Mask out the character
            }
        }
        
        cout << result << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
    
    return 0;
}
