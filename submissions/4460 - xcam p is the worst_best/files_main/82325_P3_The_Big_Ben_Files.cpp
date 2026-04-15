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

void solve()
{
    string a, b;
    cin >> a >> b;
    string ans = "";
    int j = -1;
    for (int i = 0; i < sz(a); i++)
    {
        if (j == sz(b) - 1)
        {
            ans += '#';
            continue;
        }
        if (a[i] == b[j + 1])
        {
            ans += a[i];
            j++;
        }
        else
            ans += '#';
    }
    cout << ans << '\n';
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