#include <bits/stdc++.h>
using namespace std;
#define int long long

const int inf = 1e16, sz = 500;

int dd(int a, int b) {
    int r = 1;
    while (a--) {
        r *= 2;
        if (r > inf) return inf;
    }
    while (b--) {
        r *= 3;
        if (r > inf) return inf;
    }
    return r;
}

void solve() {
    int p, a, b;
    cin >> p >> a >> b;

    // solve
    int i = 1;
    string grid[sz];
    grid[0] = "v>.";
    while (p > 0) {
        int d = dd(a, b);
        int r;
        if (a > 0) r = 2;
        else if (b > 0) r = 3;
        else r = 1;
        if (r > 1 && d >= p*r) {
            if (r == 2) grid[i++] = "XS.";
            else grid[i++] = "XSX";
            grid[i++] = ".>.";
            if (r == 2) a--;
            else b--;
            continue;
        }
        p -= d/r;
        if (r == 2) {
            a--;
            grid[i++] = ".Sv";
            grid[i++] = ".>.";
        } else if (r == 3) {
            b--;
            a++;
            grid[i++] = ">Sv";
            grid[i++] = "v>.";
        } else {
            grid[i++] = ".vv";
        }
    }
    for (; i < sz; i++) grid[i] = "...";

    // ans
    cout << "4 " << sz << '\n';
    for (int j = 0; j < 3; j++) {
        for (int k = 0; k < sz; k++) cout << grid[k][j];
        cout << '\n';
    }
    string l(sz, '>');
    cout << l << '\n';
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}