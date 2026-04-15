
/*
Telebe of Adicto && Mamedov yani AzeTurk810
I see humans but no humanity
*/
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
#define int ll

int _n, _p, _r, _k;
vector<int> E;

inline void systemd() {
    E.resize(_n);
}

char solve() {
    if (!(cin >> _n >> _p >> _r >> _k))
        return 1;
    systemd();
    for (size_t i = 0; i < _n; i++) {
        cin >> E[i];
    }
    int cnt = 0;
    for (int i = 0; i < _n; i++) {
        if (_p < E[i] && cnt >= _k)  {
            _p += _r;
            cnt = 0;
        }
        _p -= E[i];
        if (_p < 0) {
            cout << "nah i’d lose\n";
            return 0;
        }
        cnt++;
    }
    cout << "nah i’d win\n";
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
