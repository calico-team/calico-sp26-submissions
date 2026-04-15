#include <bits/stdc++.h>

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2")

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

const int inf = 0x3F3F3F3F;
const ll infll = 0x3F3F3F3F3F3F3F3FLL;

const int MM = 1e3+5;

map<char, pi> dir = {
    { '<', { 0, -1 } },
    { '>', { 0, 1 } },
    { '^', { -1, 0 } },
    { 'v', { 1, 0 } }
};
string dirs = "<>^v";
char g[MM][MM];
vector<pi> rev[MM][MM];
int in[MM][MM], in2[MM][MM];
pll dp[MM][MM];
int n, m;

void findNext(int I, int J)
{
    queue<pi> q;
    if (g[I][J] == 'S')
    {
        for (int d = 0; d < 4; d++)
        {
            auto [ci, cj] = dir[dirs[d]];
            int ni=I+ci, nj=J+cj;
            if (g[ni][nj] == '.') continue;
            auto [ci2, cj2] = dir[g[ni][nj]];
            if (ni+ci2 == I && nj+cj2 == J) continue;
            else q.push({ ni, nj });
        }
    }
    else if (g[I][J] != 'X') q.push({ I, J });
    while (!q.empty())
    {
        auto [i, j] = q.front(); q.pop();
        if (g[i][j] == 'S' || g[i][j] == 'X' || g[i][j] == 'E')
        {
            rev[i][j].push_back({ I, J });
            in[I][J]++; in2[I][J]++;
            continue;
        }
        auto [ci, cj] = dir[g[i][j]];
        q.push({ i+ci, j+cj });
    }
}

pll simplify(pll a)
{
    ll f = gcd(a.first, a.second);
    return { a.first/f, a.second/f };
}

pll mul(pll a, pll b)
{
    pll c = { a.first*b.first, a.second*b.second };
    return simplify(c);
}

pll add(pll a, pll b)
{
    ll mi = lcm(a.second, b.second);
    a.first *= mi/a.second; b.first *= mi/b.second;
    return simplify({ a.first+b.first, mi });
}

void solve()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> g[i][j];
            in[i][j] = in2[i][j] = 0;
            rev[i][j].clear();
            auto [ci, cj] = dir[g[i][j]];
            if (i+ci < 0 || i+ci > n-1 || j+cj < 0 || j+cj > m-1)
                g[i][j] = 'E';
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if ((i == 0 && j == 0) || g[i][j] == 'S')
                findNext(i, j);
        }
    }
    queue<pi> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (g[i][j] == 'E')
            {
                dp[i][j] = { 1, 1 };
                q.push({ i, j });
            }
            else if (g[i][j] == 'X')
            {
                dp[i][j] = { 0, 1 };
                q.push({ i, j });
            }
            else dp[i][j] = { 0, 1 };
        }
    }
    while (!q.empty())
    {
        auto [i, j] = q.front(); q.pop();
        for (auto [i2, j2] : rev[i][j])
        {
            dp[i2][j2] = add(dp[i2][j2], mul(dp[i][j], { 1, in2[i2][j2] }));
            in[i2][j2]--;
            if (in[i2][j2] == 0) q.push({ i2, j2 });
        }
    }
    cout << dp[0][0].first << " " << dp[0][0].second << "\n";
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    int T; cin >> T;
    while (T-- > 0)
        solve();

    return 0;
}