#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
using ll = long long;

int main() {
    FASTIO;
    ll t, k, n, m, p, q, a, b, x, y;
    cin >> t;

    while (t--)
    {
        cin >> k >> n >> m >> p >> q;
        
        vector<vector<ll>> field(n, vector<ll>(m, 0));
        for (int i = 0; i < k; i++)
        {
            cin >> a >> b;
            if (i == 0)
            {
                x = a;
                y = b;
            }
            field[a][b] = i + 1;
        }

        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < m; j++)
        //     {
        //         cout << field[i][j] << " ";
        //     }
        //     cout << "\n";
        // }

        while (true)
        {
            x += q;
            y += p;
            if (x >= n)
            {
                x -= n;
            }
            if (y >= m)
            {
                y -= m;
            }
            if (x < 0)
            {
                x += n;
            }
            if (y < 0)
            {
                y += m;
            }
            //cout << x << " " << y << endl;
            if (field[x][y] != 0)
            {
                break;
            }
            field[x][y] = -1;
        }

        cout << field[x][y] - 1 << "\n";
    }


    return 0;
}

