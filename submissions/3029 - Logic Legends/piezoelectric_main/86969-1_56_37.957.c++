#include <bits/stdc++.h>
using namespace std;

int solve(int L, int W, int E, int R) {
    int perimeter = 2 * (L + W);
    int energy_per_lap = perimeter * R;
    return E / energy_per_lap;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    while (T--) {
        int L, W, E, R;
        cin >> L >> W >> E >> R;
        cout << solve(L, W, E, R) << "\n";
    }
    
    return 0;
}