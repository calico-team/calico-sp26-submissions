#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
using ll = long long;

int main() {
    FASTIO;
    ll t, n, p, r, k, a;
    bool lost;
    string event;
    cin >> t;
    while (t--)
    {
        lost = false;
        cin >> n >> p >> r >> k;
        for (int i = 0; i < n; i++)
        {
            if (i != 0 && i % k == 0)
            {
                p += r;
            }
            cin >> a;
            p -= a;
            //cout << n << " " << " " << p << " " << r << " " << k << endl;
            if (p < 0 && !lost)
            {
                cout << "nah i'd lose\n";
                p = -1000000;
                lost = true;
            }
        }
        if (p >= 0)
        {
            cout << "nah i'd win\n";
        }
    }

    return 0;
}

