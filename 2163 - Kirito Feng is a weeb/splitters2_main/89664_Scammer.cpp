// quote from sucram: if you dont think you problem is original just swap the input and output and see what happens p9 and 10 be like
#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long p, tp;
    int a, b;
    cin >> p >> a >> b;

    vector<int> d;
    for (int i = 0; i < a; ++i) d.push_back(2);
    for (int i = 0; i < b; ++i) d.push_back(3);

    int k = a + b;
    vector<int> c(k);
    tp = p;

    for (int i = k - 1; i >= 0; --i) {
        c[i] = tp % d[i];
        tp /= d[i];
    }

    int n = 5;
    int m = 2 + 2 * k + 3;
    vector<string> g(n, string(m, '.'));

    g[0][0] = 'v';
    g[1][0] = 'v';
    g[2][0] = '>';
    g[2][1] = '>';

    bool tb = false;
    bool bb = false;

    for (int i = 0; i < k; ++i) {
        int cl = 2 + 2 * i;
        int di = d[i];
        int ci = c[i];

        g[2][cl] = 'S';
        g[2][cl + 1] = '>';

        if (di == 3) {
            if (ci == 2) {
                g[1][cl] = '^';
                tb = true;
            } else {
                g[1][cl] = 'X';
            }
        } else if (di == 2) {
            g[1][cl] = '.';
        }

        g[0][cl] = tb ? '>' : '.';
        g[0][cl + 1] = tb ? '>' : '.';

        if (di == 3) {
            if (ci >= 1) {
                g[3][cl] = 'v';
                bb = true;
            } else {
                g[3][cl] = 'X';
            }
        } else if (di == 2) {
            if (ci == 1) {
                g[3][cl] = 'v';
                bb = true;
            } else {
                g[3][cl] = 'X';
            }
        }

        g[4][cl] = bb ? '>' : '.';
        g[4][cl + 1] = bb ? '>' : '.';
    }

    int ec = 2 + 2 * k;
    g[2][ec] = 'X';

    if (tb) {
        g[0][ec] = '>';
        g[0][ec + 1] = 'v';
        g[1][ec + 1] = 'v';
        g[2][ec + 1] = 'v';
        g[3][ec + 1] = 'v';
    }

    if (tb || bb) {
        g[4][ec] = bb ? '>' : '.';
        g[4][ec + 1] = '>';
        g[4][ec + 2] = '>';
    }

    cout << n << " " << m << "\n";
    for (int i = 0; i < n; ++i) {
        cout << g[i] << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}