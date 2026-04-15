#include <bits/stdc++.h>
using namespace std;

int main() {
    // ifstream cin("input");
    
    int t;
    cin >> t;
    while (t--) {
        int l, w, e, r;
        cin >> l >> w >> e >> r;
        cout << e / ((2 * l + 2 * w) * r) << '\n';
    }
}