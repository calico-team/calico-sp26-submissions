#include <iostream>

using namespace std;

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int l, w, e, r;
        cin >> l >> w >> e >> r;
        
        // 1. Calculate the perimeter of the car
        int perimeter = 2 * (l + w);
        
        // 2. Calculate how much electricity is generated in a single lap
        int electricity_per_lap = perimeter * r;
        
        // 3. Calculate total laps needed
        int laps = e / electricity_per_lap;
        
        cout << laps << endl;
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
    
    return 0;
}
