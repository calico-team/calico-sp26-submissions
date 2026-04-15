#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define pi pair<int, int>
#define vpi vector<pi>
#define vvi vector<vi>
#define all(v) v.begin(), v.end()
const int INF = 3e18;
const int mod = 1e9 + 7;

void solve()
{
    int i, j, x, y;
    cin >> i >> j >> x >> y;
    bool ok = true;
    int ans = 1;
    set<pi> vis;
    queue<pair<int, pi>> q1, q2;
    q1.push({1, {i, j}});
    q2.push({1, {x, y}});
    vpi moves = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int gn = 1;
    int gb = 1;
    vis.insert({i, j});
    vis.insert({x, y});
    int t = 1;
    while (ok)
    {
        t++;
        if (t % 2 == 0)
        {
            while (q1.front().first == gn)
            {
                auto p2 = q1.front();
                q1.pop();
                auto [a, b] = p2.second;
                for (auto [m, n] : moves)
                {
                    if (vis.find({a + m, b + n}) != vis.end())
                        continue;
                    q1.push({gn + 1, {a + m, b + n}});
                    vis.insert({a + m, b + n});
                }
            }
            gn++;
        }
        if (t % 7 == 0)
        {
            bool brk = true;
            while (q2.size() && q2.front().first == gb)
            {
                auto p2 = q2.front();
                q2.pop();
                auto [a, b] = p2.second;
                for (auto [m, n] : moves)
                {
                    if (vis.find({a + m, b + n}) != vis.end())
                        continue;
                    brk = false;
                    q2.push({gb + 1, {a + m, b + n}});
                    vis.insert({a + m, b + n});
                    ans++;
                }
            }
            if (brk)
                break;
            gb++;
        }
    }
    cout << ans << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}