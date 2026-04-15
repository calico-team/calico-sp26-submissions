#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int n, m;
int a[N][N];
int dx[5] = {0, 1, 1, 1, 2};
int dy[5] = {1, 0, 1, 2, 1};

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

void con(int x, int y)
{
    int vis[5] = {0, 0, 0, 0, 0};
    for (int i = 0; i < 5; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (0 <= a[nx][ny] && a[nx][ny] <= 4)
            vis[a[nx][ny]]++;
    }

    for (int i = 0; i < 5; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (a[nx][ny] > 4)
            for (int j = 0; j <= 4; j++)
                if (vis[j] == 0)
                {
                    vis[j]++, a[nx][ny] = j;
                    break;
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
        for (int i = 1; i <= n - 2; i++)
        {
            for (int j = 1; j <= m - 2; j++)
            {
                con(i, j);
            }
        }

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