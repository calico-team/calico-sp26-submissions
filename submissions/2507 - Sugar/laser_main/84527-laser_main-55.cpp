#include <bits/stdc++.h>
using namespace std;

using board = unordered_map<int, unordered_map<int, int>>;

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        board plane;
        int k, n, m, p, q, x, y;
        cin >> k >> n >> m >> p >> q;
        for (int j = 1; j <= k; j++)
        {
            int tmpx, tmpy;
            cin >> tmpx >> tmpy;
            if (j == 1)
            {
                x = tmpx;
                y = tmpy;
            }
            plane[tmpx][tmpy] = j;
        }
        while (true)
        {
            x += q, y += p;
            if (x >= n)
                x -= n;
            if (y >= m)
                y -= m;
            if (plane[x][y] != 0)
                break;
        }
        cout << plane[x][y] - 1 << endl;
    }
    return 0;
}