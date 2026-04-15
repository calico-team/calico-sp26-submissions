#include <iostream>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <unordered_set>
#include <stack>
#include <random>
#include <chrono>
#include <bitset>
#include <complex>
#include <cassert>
#include <functional>
#include <ctime>

#pragma GCC optimize("O3")

using namespace std;

#define ll long long
#define f first
#define s second

//
//
//

int n, m;
vector<vector<char>> a;
pair<ll, ll> ans = {0, 1};
void dfs(int x, int y, ll p, ll q)
{

    if (x < 0 || y < 0 || x >= n || y >= m)
    {
        if (ans == make_pair(0ll, 1ll))
            ans = {p, q};
        else
        {
            ll v = gcd(p, q);
            p /= v, q /= v;
            ans = {ans.f * q + p * ans.s, ans.s * q};
            v = gcd(ans.f, ans.s);
            ans.f /= v, ans.s /= v;
        }
        return;
    }
    if (a[x][y] == '^')
        return dfs(x - 1, y, p, q);
    if (a[x][y] == 'v')
        return dfs(x + 1, y, p, q);
    if (a[x][y] == '<')
        return dfs(x, y - 1, p, q);
    if (a[x][y] == '>')
        return dfs(x, y + 1, p, q);
    if (a[x][y] == 'X')
        return;
    if (a[x][y] == 'S')
    {
        int ct = 0;
        if (x - 1 >= 0 && a[x - 1][y] != 'v' && a[x - 1][y] != '.')
            ct++;
        if (x + 1 < n && a[x + 1][y] != '^' && a[x + 1][y] != '.')
            ct++;
        if (y - 1 >= 0 && a[x][y - 1] != '>' && a[x][y - 1] != '.')
            ct++;
        if (y + 1 < m && a[x][y + 1] != '<' && a[x][y + 1] != '.')
            ct++;

        if (x - 1 >= 0 && a[x - 1][y] != 'v')
            dfs(x - 1, y, p, q * ct);
        if (x + 1 < n && a[x + 1][y] != '^')
            dfs(x + 1, y, p, q * ct);
        if (y - 1 >= 0 && a[x][y - 1] != '>')
            dfs(x, y - 1, p, q * ct);
        if (y + 1 < m && a[x][y + 1] != '<')
            dfs(x, y + 1, p, q * ct);
        return;
    }
}
void solve()
{
    cin >> n >> m;
    ans = {0, 1};
    a = vector<vector<char>>(n, vector<char>(m));
    for (auto &u : a)
        for (auto &l : u)
            cin >> l;
    dfs(0, 0, 1, 1);
    cout << ans.f << " " << ans.s << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
        solve();
}