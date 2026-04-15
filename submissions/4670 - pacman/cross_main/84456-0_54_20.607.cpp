/*
Telebe of Adicto && Mamedov yani AzeTurk810
I see humans but no humanity
*/
#include <cassert>
#include <iostream>
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

int _n, _m;
vector<vector<int>> ans;

inline void systemd() {
    ans.assign(_n, vector<int>(_m, -1));
}

char solve() {
    if (!(cin >> _n >> _m))
        return 1;
    systemd();
    ans[0][0] = 0;
    ans.back().back() = 0;
    ans[0].back() = 0;
    ans.back()[0] = 0;
    int nxt = 0;
    for (int i = 0; i < _n; i++) {
        for (int j = 0; j < _m; j++) {
            ans[i][j] = (i * 2 + j) % 5;
            assert(ans[i][j] != -1);
            cout << ans[i][j] << ' ';
        }
        cout << ln;
    }
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
