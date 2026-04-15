#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
    {
        int N;
        long long P, R, K;
        cin >> N >> P >> R >> K;

        vector<long long> E(static_cast<size_t>(N));
        for (int i = 0; i < N; i++)
        {
            cin >> E[static_cast<size_t>(i)];
        }

        long long power = P;
        long long defeated = 0;
        long long usedHeals = 0;
        bool win = true;

        for (long long e : E)
        {
            long long unlockedHeals = defeated / K;
            long long availableHeals = unlockedHeals - usedHeals;

            if (power < e && availableHeals > 0)
            {
                long long need = e - power;
                long long healsNeeded = (need + R - 1) / R;
                long long useNow = min(availableHeals, healsNeeded);
                power += useNow * R;
                usedHeals += useNow;
            }

            if (power < e)
            {
                win = false;
                break;
            }

            power -= e;
            defeated++;
        }

        if (win)
        {
            cout << "nah i'd win\n";
        }
        else
        {
            cout << "nah i'd lose\n";
        }
    }

    return 0;
}
