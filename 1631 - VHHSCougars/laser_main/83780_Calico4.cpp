#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int k, n, m, p, q;
    cin >> k >> n >> m >> p >> q;
    vector<pair<int, int>> astroids(k);
    for (int i = 0; i < k; i++)
    {
        cin >> astroids[i].first >> astroids[i].second;
    }
    vector<vector<int>> graph(n, vector<int>(m, k + 1));
    for (int i = 0; i < k; i++)
    {
        int x = astroids[i].first;
        int y = astroids[i].second;
        graph[x][y] = i;
    }
    int px = (astroids[0].first + q) % n;
    int py = (astroids[0].second + p) % m;
    while (graph[px][py] == k + 1)
    {
        px = (px + q) % n;
        py = (py + p) % m;
    }
    cout << graph[px][py] << "\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}