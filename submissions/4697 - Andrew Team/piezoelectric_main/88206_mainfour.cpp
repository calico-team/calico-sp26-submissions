#include <iostream>
typedef long long ll;
using namespace std;

/** 
 * Return the number of laps needed to charge the car (rounded up)
 * 
 * L: Length of car
 * W: Width of car
 * E: Amount of electricity to generate
 * R: Electricity generated per unit distance
 */
int solve(int L, int W, int E, int R) {
    ll perimeter = 2LL * (L + W);
    ll per_lap = perimeter * R;
    // Round up division
    ll laps = (E + per_lap - 1) / per_lap;
    return (int)laps;
}

int main() {
    int T; cin >> T;
    while (T--) {
        int L, W, E, R; 
        cin >> L >> W >> E >> R;
        cout << solve(L, W, E, R) << endl;
    }
    return 0;
}
