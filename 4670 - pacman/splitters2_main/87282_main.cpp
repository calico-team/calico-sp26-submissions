/*
Telebe of Adicto && Mamedov yani AzeTurk810
I see humans but no humanity
*/
#include <iostream>
#include <string>
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

ll _p;
int _a, _b, _n;
vector<int> facs;
vector<vector<char>> g;

inline void systemd() {
    _n = _a + _b;
    g.assign(5, vector<char>(((_n << 1) | 1), '.'));
}

char solve() {
    cin >> _p >> _a >> _b;
    systemd();

    for (int _ = 0; _ < _a; _++) {
        facs.push_back(2);
    }
    for (int _ = 0; _ < _b; _++) {
        facs.push_back(3);
    }

    vector<int> digs(_n, 0);
    ll x = _p;
    for (int i = _n - 1; i >= 0; --i) {
        digs[i] = (int)(x % facs[i]);
        x /= facs[i];
    }

    if (x > 0) {
        cout << 1 << ' ' << 1 << '\n';
        cout << '>' << '\n';
        return 0;
    }
    g[0][0] = 'v';
    g[2][0] = '>';
    g[1][0] = 'v';

    for (int i = 0; i < _n; ++i) {
        int c = 1 + 2 * i;
        int f = facs[i];
        int d = digs[i];

        g[2][c] = 'S';
        g[2][c + 1] = (i + 1 < _n ? '>' : 'X');

        if (f == 2) {
            if (d == 0) {
                g[1][c] = 'X';
            } else {
                g[1][c] = '^';
                g[0][c] = '^';
            }
        } else {
            if (d == 0) {
                g[1][c] = 'X';
                g[3][c] = 'X';
            } else if (d == 1) {
                g[1][c] = '^';
                g[0][c] = '^';
                g[3][c] = 'X';
            } else {
                g[1][c] = '^';
                g[0][c] = '^';
                g[3][c] = 'v';
                g[4][c] = 'v';
            }
        }
    }

    cout << 5 << ' ' << 2 * _n + 1 << ln;
    for (const auto &i : g) {
        for (const char &j : i) {
            cout << j;
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
