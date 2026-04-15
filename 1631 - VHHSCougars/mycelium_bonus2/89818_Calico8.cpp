#include <bits/stdc++.h>

using namespace std;

void triggerGrass(queue<pair<long long, long long>> &q, vector<vector<char>> &grid)
{
    // every grass cell adjacent to a grass cell becomes grass that's not already grass or mycelium
    int size = q.size();
    vector<pair<long long, long long>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    for (int i = 0; i < size; ++i)
    {
        auto [x, y] = q.front();
        q.pop();

        for (int d = 0; d < 4; ++d)
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
    int size = q.size();
    vector<pair<long long, long long>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    for (int i = 0; i < size; i++)
    {
        auto [x, y] = q.front();
        q.pop();

        for (int d = 0; d < 4; d++)
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
    int xg, yg, xm, ym;
    cin >> xg >> yg >> xm >> ym;
    xg += 2870;
    yg += 2870;
    xm += 2870;
    ym += 2870;
    int lowerx = min(xg, xm);
    int upperx = max(xg, xm) + 10670;
    int lowery = min(yg, ym);
    int uppery = max(yg, ym) + 10670;
    vector<vector<char>> grid(10670, vector<char>(10670, '.'));
    grid[xg][yg] = 'G';
    grid[xm][ym] = 'M';
    queue<pair<long long, long long>> qG;
    queue<pair<long long, long long>> qM;
    qG.push({xg, yg});
    qM.push({xm, ym});
    long long ticks = 1;
    while (!qM.empty())
    {
        if (ticks % 2 == 0)
        {
            triggerGrass(qG, grid);
        }
        if (ticks % 7 == 0)
        {
            triggerMycelium(qM, grid);
        }
        ticks++;
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
