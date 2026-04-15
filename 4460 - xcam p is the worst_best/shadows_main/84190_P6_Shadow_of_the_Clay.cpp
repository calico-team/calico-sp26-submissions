#include <bits/stdc++.h>
using namespace std;

#define int long long
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define FOR(i, a, b) for (int i = (a), _b = (b), _s = ((a) <= _b ? 1 : -1); i != _b + _s; i += _s)

inline void fast_io(string name = "")
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if (sz(name))
    {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

const int N = 1e3 + 7;
char a[N][N] = {};
char b[N][N] = {};
int c1[N] = {};
int c2[N] = {}; // this is maximum volume
// hashtags are dark
void solve()
{

    int n;
    cin >> n;

    memset(c1, 0, sizeof c1);
    memset(c2, 0, sizeof c2);
    int Min = 0, Max = 0;

    FOR(i, 0, n - 1)
    FOR(j, 0, n - 1)
    {
        cin >> a[i][j];
        if (a[i][j] == '#')
        {
            c1[i]++;
            Min++;
            c2[i]++;
            Max += n;
        }
    }

    FOR(i, 0, n - 1)
    FOR(j, 0, n - 1)
    {
        cin >> b[i][j];
        if (b[i][j] == '#')
        {
            if (c1[i] > 0)
                c1[i]--;
            else
                Min++;
        }
    }
    FOR(i, 0, n - 1)
    FOR(j, 0, n - 1)
    {
        if (b[i][j] == '.')
        {
            // Subtract 1 from all the cells we see with j == cur_i.
            Max -= c2[i];
        }
    }
    cout << Max << " " << Min << '\n';
}

signed main()
{
    fast_io();

    int tc;
    cin >> tc;

    while (tc--)
    {
        solve();
    }
    return 0;
}