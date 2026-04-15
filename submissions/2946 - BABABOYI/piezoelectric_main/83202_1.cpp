#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long L, W, E, R;
    cin >> L >> W >> E >> R;

    long long perimeter = 2 * (L + W);
    
    long long electricity_per_lap = perimeter * R;
    
    long long laps = E / electricity_per_lap;
    cout << laps << "\n";
}

int main() {
    int T;
    cin >> T;
    while (T--){
        solve();
    }
    return 0;
}