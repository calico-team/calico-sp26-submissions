#include <iostream>
typedef long long ll;
using namespace std;

int solve(int L, int W, int E, int R) {

    ll triangle_perimeter = 2LL * (L + W);
    ll electricity_per_lap = triangle_perimeter * R;

    return E / electricity_per_lap;
}

int main() {
    int T; 
    cin >> T;

    while (T--) {
        int L, W, E, R;
        cin >> L >> W >> E >> R;

        cout << solve(L, W, E, R) << endl;
    }

    return 0;
}