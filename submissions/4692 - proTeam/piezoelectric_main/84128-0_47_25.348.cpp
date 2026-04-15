#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--) {
        int L, W, E, R;
        cin >> L >> W >> E >> R;

        int perimeter = 2 * (L + W);
        int energyPerLap = perimeter * R;

        cout << E / energyPerLap << endl;
    }

    return 0;
}
