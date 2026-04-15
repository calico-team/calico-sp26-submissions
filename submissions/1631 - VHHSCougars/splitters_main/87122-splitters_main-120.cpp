#include <bits/stdc++.h>

using namespace std;

vector<pair<long long, long long>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

pair<long long, long long> addfrac(long long a, long long b, long long c, long long d)
{
    long long num = a * d + b * c;
    long long den = b * d;
    long long g = gcd(num, den);
    num /= g;
    den /= g;
    return {num, den};
}

pair<long long, long long> multfrac(long long a, long long b, long long c, long long d)
{
    long long num = a * c;
    long long den = b * d;
    long long g = gcd(num, den);
    num /= g;
    den /= g;
    return {num, den};
}

void solve()
{
    long long n, m;
    cin >> n >> m;
    vector<vector<char>> grid(m, vector<char>(n));
    for (long long y = 0; y < n; ++y)
    {
        for (long long x = 0; x < m; ++x)
        {
            cin >> grid[x][y];
        }
    }
    // state is (x, y, fraction of material on spot)
    queue<vector<long long>> q;
    q.push({0, 0, 1, 1});
    pair<long long, long long> collected = {0, 1};
    while (!q.empty())
    {
        auto state = q.front();
        q.pop();
        long long x = state[0];
        long long y = state[1];
        long long num = state[2];
        long long den = state[3];
        if (grid[x][y] == 'S')
        {
            long long numValid = 0;
            vector<pair<long long, long long>> valid;
            if (grid[x - 1][y] != '.' && grid[x - 1][y] != '>')
            {
                numValid++;
                valid.push_back({x - 1, y});
            }
            if (grid[x + 1][y] != '.' && grid[x + 1][y] != '<')
            {
                numValid++;
                valid.push_back({x + 1, y});
            }
            if (grid[x][y - 1] != '.' && grid[x][y - 1] != 'v')
            {
                numValid++;
                valid.push_back({x, y - 1});
            }
            if (grid[x][y + 1] != '.' && grid[x][y + 1] != '^')
            {
                numValid++;
                valid.push_back({x, y + 1});
            }
            for (auto [nx, ny] : valid)
            {
                q.push({nx, ny, num, den * numValid});
            }
        }

        if (grid[x][y] == '>')
        {
            if (x + 1 == m)
            {
                collected = addfrac(collected.first, collected.second, num, den);
            }
            else
            {
                q.push({x + 1, y, num, den});
            }
        }
        if (grid[x][y] == '<')
        {
            if (x - 1 == -1)
            {
                collected = addfrac(collected.first, collected.second, num, den);
            }
            else
            {
                q.push({x - 1, y, num, den});
            }
        }
        if (grid[x][y] == 'v')
        {
            if (y + 1 == n)
            {
                collected = addfrac(collected.first, collected.second, num, den);
            }
            else
            {
                q.push({x, y + 1, num, den});
            }
        }
        if (grid[x][y] == '^')
        {
            if (y - 1 == -1)
            {
                collected = addfrac(collected.first, collected.second, num, den);
            }
            else
            {
                q.push({x, y - 1, num, den});
            }
        }
    }
    cout << collected.first << " " << collected.second;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << "\n";
    }
    return 0;
}