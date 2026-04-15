#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int n, m;
int a[N][N];
int dx[5] = {1, 2, 0, 1, 1};
int dy[5] = {0, 1, 1, 2, 1};

// void dfs(int now)
// {
//     if (now > n)
//     {
//     }
//     for (int i = mini; i <= maxi; i++)
//     {
//         b[i]=
//     }
// }

inline bool check(int x, int y, int j)
{
    if (x == 1 || x == n || y == 1 || y == m)
        return true;
    if (x >= 2 && a[x - 2][y] == j || a[x - 1][y - 1] == j || a[x - 1][y] == j || a[x - 1][y + 1] == j || y >= 2 && a[x][y - 2] == j || a[x][y - 1] == j || a[x][y + 1] == j || a[x][y + 2] == j || a[x + 1][y - 1] == j || a[x + 1][y] == j || a[x + 1][y + 1] == j || a[x + 1][y] == j)
        return false;
    return true;
}

void con(int x, int y)
{
    int vis[5] = {0, 0, 0, 0, 0};
    for (int i = 0; i < 5; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (0 <= a[nx][ny] && a[nx][ny] <= 4)
            vis[a[nx][ny]]++;
    }

    // if (x == 2 && y == 1)
    // {
    //     cout << "#######vis########" << endl;
    //     for (int i = 0; i < 5; i++)
    //         cout << vis[i];
    //     cout << endl;
    // }

    for (int i = 0; i < 5; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        // if (nx == 3 && ny == 1)
        //     cout << x << ' ' << y << ' ' << i << endl;
        if (a[nx][ny] > 4)
        {
            // if (x == 1 && y == 3)
            // {
            //     for (int i = 1; i <= n; i++)
            //     {
            //         for (int j = 1; j <= m; j++)
            //         {
            //             if (a[i][j] == 0x3f3f3f3f)
            //                 cout << 0 << ' ';
            //             else
            //                 cout << a[i][j] << ' ';
            //         }
            //         cout << endl;
            //     }
            //     cout << endl;
            // }
            for (int j = 0; j <= 4; j++)
            {
                if (vis[j] == 0 && check(nx, ny, j))
                {
                    vis[j]++, a[nx][ny] = j;
                    break;
                }
            }
        }
    }
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        memset(a, 0x3f, sizeof(a));
        cin >> n >> m;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (i % 2 == 0)
                {
                    if (i == 2)
                        a[i][j] = j - 1;
                    else
                    {
                        a[i][j] = (a[i - 2][j] + 1) % 5;
                    }
                }
                else
                {
                    a[i][j] = ((i / 2 + 2) + (j - 1)) % 5;
                }
            }
        }
        // for (int i = 2; i <= n; i += 2)
        // {
        //     for (int j = 1; j <= m; j++)
        //     {
        //         if (i == 2)
        //             a[i][j] = j - 1;
        //         else
        //         {
        //             a[i][j] = (a[i - 2][j] + 1) % 5;
        //         }
        //     }
        // }

        // for (int i = 1; i <= n - 2; i++)
        // {
        //     for (int j = 1; j <= m - 2; j++)
        //     {
        //         con(i, j);
        //     }
        // }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (a[i][j] == 0x3f3f3f3f)
                    cout << 0 << ' ';
                else
                    cout << a[i][j] << ' ';
            }
            cout << endl;
        }
    }

    return 0;
}
/*
1
4
1 2 3 4
*/