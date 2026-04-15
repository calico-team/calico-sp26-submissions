#include <bits/stdc++.h>
#include <csignal>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
using ll = long long;

int main() {
    FASTIO;
    ll t, n, m, x;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        x = 0;
        vector<vector<ll>> grid(n, vector<ll>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                grid[i][j] = (j + x) % 5;
            }

            x += 2;
            if (x == 5)
            {
                x = 0;
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << grid[i][j] << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}

// 0 1 2 3 4 0 1 2 3 4
// 2 3 4 0 1 2 3 4 0 1
// 4 0 1 2 3 4 0 1 2 3
// 1 2 3 4 0 1 2 3 4 0
