#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <numeric>   // for gcd
#include <algorithm> // for abs

using namespace std;

using ll = long long;

struct Frac {
    ll num, den;
    Frac(ll n=0, ll d=1) {
        ll g = gcd(abs(n), abs(d));
        num = n / g;
        den = d / g;
        if (den < 0) num = -num, den = -den;
    }
};

Frac add(const Frac &a, const Frac &b) {
    return Frac(a.num*b.den + b.num*a.den, a.den*b.den);
}

Frac divide(const Frac &a, ll k) {
    return Frac(a.num, a.den * k);
}

int n, m;
vector<string> grid;
vector<vector<bool>> vis;
vector<vector<Frac>> dp;

map<char, pair<int,int>> dirs = {
    {'^', {-1, 0}},
    {'v', {1, 0}},
    {'<', {0, -1}},
    {'>', {0, 1}}
};

bool valid(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m;
}

Frac dfs(int i, int j) {
    if (!valid(i, j)) return Frac(1,1);
    if (grid[i][j] == 'X') return Frac(0,1);

    if (vis[i][j]) return dp[i][j];
    vis[i][j] = true;

    char c = grid[i][j];

    if (dirs.count(c)) {
        auto d = dirs[c];
        return dp[i][j] = dfs(i + d.first, j + d.second);
    }

    if (c == 'S') {
        vector<pair<int,int>> ways;

        for (auto &it : dirs) {
            int ni = i + it.second.first;
            int nj = j + it.second.second;

            if (!valid(ni, nj)) continue;

            if (grid[ni][nj] == 'X') {
                ways.push_back({ni, nj});
            }
            else if (dirs.count(grid[ni][nj])) {
                auto back = dirs[grid[ni][nj]];
                if (ni + back.first == i && nj + back.second == j)
                    continue;
                ways.push_back({ni, nj});
            }
        }

        Frac total(0,1);
        for (auto &p : ways) {
            total = add(total, dfs(p.first, p.second));
        }

        return dp[i][j] = divide(total, ways.size());
    }

    return dp[i][j] = Frac(0,1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        cin >> n >> m;
        grid.resize(n);
        for (int i = 0; i < n; i++) cin >> grid[i];

        dp.assign(n, vector<Frac>(m));
        vis.assign(n, vector<bool>(m, false));

        Frac ans = dfs(0, 0);
        cout << ans.num << " " << ans.den << "\n";
    }

    return 0;
}