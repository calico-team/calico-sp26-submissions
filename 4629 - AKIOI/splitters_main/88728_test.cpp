#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int n, m;
char a[N][N];
int des, col;

inline int gcd(int x, int y) { return !y ? x : gcd(y, x % y); }
inline int lcm(int x, int y) { return x / gcd(x, y) * y; }

struct Fra
{
    int a, b;
};
Fra operator+(Fra x, Fra y)
{
    int mul = lcm(x.b, y.b);
    x.a *= mul / x.b, x.b = mul, y.a *= mul / y.b, y.b = mul;
    Fra ans = {x.a + y.a, x.b};
    mul = gcd(ans.a, ans.b);
    ans.a /= mul, ans.b /= mul;
    return ans;
}

Fra dfs(int x, int y)
{
    while (!(x < 1 || x > n || y < 1 || y > m) && (a[x][y] == '<' || a[x][y] == '>' || a[x][y] == '^' || a[x][y] == 'v'))
    {
        if (a[x][y] == '<')
            y--;
        if (a[x][y] == '>')
            y++;
        if (a[x][y] == '^')
            x--;
        if (a[x][y] == 'v')
            x++;
    }
    if (a[x][y] == 'X')
        return {0, 1};
    if (x < 1 || x > n || y < 1 || y > m)
        return {1, 1};

    int branch = 0;
    Fra ans = {0, 1};
    if (a[x + 1][y] != '.' && a[x + 1][y] != 'S' && a[x + 1][y] != '^')
    {
        branch++;
        ans = ans + dfs(x + 1, y);
    }
    if (a[x - 1][y] != '.' && a[x - 1][y] != 'S' && a[x - 1][y] != 'v')
    {
        branch++;
        ans = ans + dfs(x - 1, y);
    }
    if (a[x][y + 1] != '.' && a[x][y + 1] != 'S' && a[x][y + 1] != '<')
    {
        branch++;
        ans = ans + dfs(x, y + 1);
    }
    if (a[x][y - 1] != '.' && a[x][y - 1] != 'S' && a[x][y - 1] != '>')
    {
        branch++;
        ans = ans + dfs(x, y - 1);
    }
    return {ans.a, ans.b * branch};
}

int main()
{
    int T;
    char c;
    cin >> T;
    while (T--)
    {
        des = col = 0;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> a[i][j];
            }
        }
        Fra ans = dfs(1, 1);
        if (ans.a == 0)
            cout << 0 << ' ' << 1 << endl;
        else
        {
            int mul = gcd(ans.a, ans.b);
            cout << ans.a / mul << ' ' << ans.b / mul << endl;
        }
    }

    return 0;
}
/*
2
6 10
v.>>>>v.^.
v.^...v.^.
>>S>S>>>S.
..X.v...v.
....>>>>X.
..........
3 3
vX.
>SX
.X.
*/