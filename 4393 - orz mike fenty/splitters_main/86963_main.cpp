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
vector<pi> adj[MM][MM];
int in[MM][MM];
pll dp[MM][MM];
int n, m;

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
            in[i][j] = 0;
            adj[i][j].clear();
            auto [ci, cj] = dir[g[i][j]];
            if (i+ci < 0 || i+ci > n-1 || j+cj < 0 || j+cj > m-1)
                g[i][j] = 'E';
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (g[i][j] == 'S')
            {
                for (int d = 0; d < 4; d++)
                {
                    auto [ci, cj] = dir[dirs[d]];
                    int ni=i+ci, nj=j+cj;
                    if (g[ni][nj] == '.') continue;
                    auto [ci2, cj2] = dir[g[ni][nj]];
                    if (ni+ci2 == i && nj+cj2 == j) continue;
                    else
                    {
                        adj[i][j].push_back({ ni, nj });
                        in[ni][nj]++;
                    }
                }
            }
            else if (g[i][j] != 'X' && g[i][j] != 'E' && g[i][j] != '.')
            {
                auto [ci, cj] = dir[g[i][j]];
                adj[i][j].push_back({ i+ci, j+cj });
                in[i+ci][j+cj]++;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            dp[i][j] = { 0, 1 };
    }
    dp[0][0] = { 1, 1 };
    queue<pi> q; q.push({ 0, 0 });
    while (!q.empty())
    {
        auto [i, j] = q.front(); q.pop();
        for (auto [i2, j2] : adj[i][j])
        {
            dp[i2][j2] = add(dp[i2][j2], mul(dp[i][j], { 1, adj[i][j].size() }));
            in[i2][j2]--;
            if (in[i2][j2] == 0) q.push({ i2, j2 });
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (g[i][j] == 'E')
            {
                cout << dp[i][j].first << " " << dp[i][j].second << "\n";
                return;
            }
        }
    }
    cout << "0 1\n";
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    int T; cin >> T;
    while (T-- > 0)
        solve();

    return 0;
}