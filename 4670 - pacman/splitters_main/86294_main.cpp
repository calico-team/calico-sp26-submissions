/*
Telebe of Adicto && Mamedov yani AzeTurk810
I see humans but no humanity
*/
#include <algorithm>
#include <cassert>
#include <iostream>
#include <numeric>
#include <utility>
#include <vector>

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

using ll = long long;
using namespace std;

#define ln '\n'
#define INFi 1e9
#define INFll 1e18

#ifdef ONPC
#include <algo.hpp>
#else
#define dbg(...)
#define dbg_out(...)
#endif
#define int ll

int _n, _m;
vector<vector<char>> g;
vector<int> sub;

inline void systemd() {
    g.assign(_n + 1, vector<char>(_m + 1, '0'));
    sub.clear();
}

char is_valid(int i, int j) {
    return min(i, j) > 0 && i <= _n && j <= _m;
}

void dfs(int i, int j, int q) {
    dbg(make_pair(i, j));
    dbg(q);
    assert(is_valid(i, j));
    if (g[i][j] == 'X') {
        sub.push_back(q);
        return;
    }
    if (g[i][j] == 'S') {
        int cnt = 0;
        if (is_valid(i + 1, j) && g[i + 1][j] != '^' && g[i + 1][j] != '.') {
            cnt++;
        }
        if (is_valid(i, j + 1) && g[i][j + 1] != '<' && g[i][j + 1] != '.') {
            cnt++;
        }
        if (is_valid(i, j - 1) && g[i][j - 1] != '>' && g[i][j - 1] != '.') {
            cnt++;
        }
        if (is_valid(i - 1, j) && g[i - 1][j] != 'v' && g[i - 1][j] != '.') {
            cnt++;
        }
        ll nq = q * cnt;
        if (is_valid(i + 1, j) && g[i + 1][j] != '^' && g[i + 1][j] != '.') {
            dfs(i + 1, j, nq);
        }
        if (is_valid(i, j + 1) && g[i][j + 1] != '<' && g[i][j + 1] != '.') {
            dfs(i, j + 1, nq);
        }
        if (is_valid(i, j - 1) && g[i][j - 1] != '>' && g[i][j - 1] != '.') {
            dfs(i, j - 1, nq);
        }
        if (is_valid(i - 1, j) && g[i - 1][j] != 'v' && g[i - 1][j] != '.') {
            dfs(i - 1, j, nq);
        }
        return;
    }
    ll nq = q * 1;
    if (g[i][j] == 'v' && is_valid(i + 1, j) && g[i + 1][j] != '^' && g[i + 1][j] != '.') {
        dfs(i + 1, j, nq);
    }
    if (g[i][j] == '>' && is_valid(i, j + 1) && g[i][j + 1] != '<' && g[i][j + 1] != '.') {
        dfs(i, j + 1, nq);
    }
    if (g[i][j] == '<' && is_valid(i, j - 1) && g[i][j - 1] != '>' && g[i][j - 1] != '.') {
        dfs(i, j - 1, nq);
    }
    if (g[i][j] == '^' && is_valid(i - 1, j) && g[i - 1][j] != 'V' && g[i - 1][j] != '.') {
        dfs(i - 1, j, nq);
    }
}

char solve() {
    if (!(cin >> _n >> _m))
        return 1;
    systemd();
    for (size_t i = 1; i <= _n; i++) {
        for (size_t j = 1; j <= _m; j++) {
            cin >> g[i][j];
        }
    }
    dbg(g);
    dfs(1, 1, 1);
    dbg(sub);
    ll g = 1;
    for (int x : sub) {
        g = lcm(x, g);
    }
    ll sum = 0;
    for (int x : sub) {
        sum += (g / x);
    }
    sum = g - sum;
    int cg = gcd(sum, g);
    g /= cg;
    sum /= cg;
    if (sum == 0)
        g = 1;
    cout << sum << ' ' << g << ln;
    return 0;
}

// Attack on titan<3

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t = 1e9;
    cin >> t;
    for (int cases = 0; cases < t; cases++) {
        if (solve())
            break;
#ifdef ONPC
        cerr << "__________\n";
#endif
    }
}
// Just Imaginary
/*
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣀⠀⠀⠀⢀⣴⣾⠀⠀⠀⡀⢀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣿⣦⣾⣿⣿⣿⣿⣿⡆⠁⠀⢀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠹⣿⣿⣿⣿⣿⣿⣿⣿⡿⠁⠀⡠⠂⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⠠⠔⠚⣿⣿⣿⣿⣿⣦⡄⠀⠁⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⢀⠠⠐⢂⠉⡀⣀⣤⣄⢻⣿⣿⡟⢈⡹⣿⡀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⡀⠄⠂⠈⠀⣶⣤⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠘⣷⡀⠀⡀⠐⠂⠐⢄
⠀⠀⠀⠀⠀⠀⠀⣿⣿⠟⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⣀⣾⣷⠯⠀⠤⠤⠄⠈
⠀⠀⠀⠀⠀⠀⣼⣿⡟⠀⠀⣹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣄⡀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⣰⣿⠋⠀⠀⢠⣾⣿⣿⣿⣿⣿⣭⠟⢻⣿⣿⣿⣿⡿⠁⠀⠀⠀⠀
⠀⠀⠀⣀⣶⡟⠁⠀⢾⣶⣿⠟⠉⠈⢻⣿⣿⣿⣦⣜⠀⠛⠛⠿⠁⠀⠀⠀⠀⠀
⠚⠻⠿⠿⡿⠁⠀⢠⣿⣿⠁⠀⣠⠖⠋⠉⠻⣿⣿⣿⣶⡀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⣰⣿⡿⠃⠠⠊⠁⠀⠀⠀⠀⠈⢿⣿⣿⠟⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⢀⣴⡿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⣠⣾⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⢀⣴⠾⠟⠛⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
*/
