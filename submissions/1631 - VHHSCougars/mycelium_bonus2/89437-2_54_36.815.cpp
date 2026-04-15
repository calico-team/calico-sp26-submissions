#include <bits/stdc++.h>

using namespace std;

void triggerGrass(queue<pair<long long, long long>> &q, vector<vector<char>> &grid)
{
    // every grass cell adjacent to a grass cell becomes grass that's not already grass or mycelium
    long long size = q.size();
    vector<pair<long long, long long>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    for (long long i = 0; i < size; ++i)
    {
        auto [x, y] = q.front();
        q.pop();

        for (long long d = 0; d < 4; ++d)
        {
            long long nx = x + directions[d].first;
            long long ny = y + directions[d].second;

            if (nx < 0 || ny < 0 || nx >= (long long)grid.size() || ny >= (long long)grid[0].size())
                continue;

            if (grid[nx][ny] == 'G' || grid[nx][ny] == 'M')
                continue;

            grid[nx][ny] = 'G';
            q.push({nx, ny});
        }
    }
}

void triggerMycelium(queue<pair<long long, long long>> &q, vector<vector<char>> &grid)
{
    // every mycelium cell adjacent to a mycelium cell becomes mycelium that's not already grass or mycelium
    long long size = q.size();
    vector<pair<long long, long long>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    for (long long i = 0; i < size; i++)
    {
        auto [x, y] = q.front();
        q.pop();

        for (long long d = 0; d < 4; d++)
        {
            long long nx = x + directions[d].first;
            long long ny = y + directions[d].second;

            if (nx < 0 || ny < 0 || nx >= (long long)grid.size() || ny >= (long long)grid[0].size())
                continue;

            if (grid[nx][ny] == 'G' || grid[nx][ny] == 'M')
                continue;

            grid[nx][ny] = 'M';
            q.push({nx, ny});
        }
    }
}

void solve()
{
    long long xg, yg, xm, ym;
    cin >> xg >> yg >> xm >> ym;
    // long long buffer = max((min(xg, xm) - max(xg, xm)), (min(yg, ym) - max(yg, ym))) * 5 + 100;
    xg += 6500;
    yg += 6500;
    xm += 6500;
    ym += 6500;
    // long long upper = max({xg, yg, xm, ym}) + buffer;
    vector<vector<char>> grid(14500, vector<char>(14500, '.'));
    grid[xg][yg] = 'G';
    grid[xm][ym] = 'M';
    queue<pair<long long, long long>> qG;
    queue<pair<long long, long long>> qM;
    qG.push({xg, yg});
    qM.push({xm, ym});
    vector<int> tickcycle = {2, 4, 6, 7, 8, 10, 12, 14};
    int ptr = 0;
    while (!qM.empty())
    {
        if (ticks[ptr] % 2 == 0)
        {
            triggerGrass(qG, grid);
        }
        if (ticks[ptr] % 7 == 0)
        {
            triggerMycelium(qM, grid);
        }
        ptr = (ptr + 1) % tickcycle.size();
    }
    long long totalMycelium = 0;
    for (auto &row : grid)
    {
        for (char cell : row)
        {
            if (cell == 'M')
                totalMycelium++;
        }
    }
    cout << totalMycelium;
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
