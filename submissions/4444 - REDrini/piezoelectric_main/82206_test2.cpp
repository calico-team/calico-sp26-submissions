#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while (T--) {
        int L, W, E, R;
        cin >> L >> W >> E >> R;
        cout << E / ((L + W) * R * 2) << '\n';
    }
}