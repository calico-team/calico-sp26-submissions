#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
    {
        long long L, W, E, R;
        cin >> L >> W >> E >> R;

        long long energyPerLap = 2LL * (L + W) * R;
        cout << (E / energyPerLap) << "\n";
    }

    return 0;
}
