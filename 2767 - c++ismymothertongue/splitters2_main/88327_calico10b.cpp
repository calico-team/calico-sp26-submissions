#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve() {
    long long P;
    int A, B;
    if (!(cin >> P >> A >> B)) return;

    int n = (A + B) * 3 + 2;
    int m = 5;
    vector<string> g(n, string(m, '.'));

    g[0][0] = 'v';

    for (int i = 0; i < A + B; i++) {
        int r = i * 3 + 1;
        int base = (i < A) ? 2 : 3;
        int rem = P % base;
        P /= base;

        g[r][1] = 'S';
        g[r - 1][1] = 'v';
        if (i == 0) g[0][1] = 'v';

        g[r + 1][1] = 'v';

        if (base == 2) {
            g[r][2] = (rem == 1) ? '>' : 'X';
        } else {
            g[r][2] = (rem >= 1) ? '>' : 'X';
            g[r][0] = (rem == 2) ? '<' : 'X';
        }
    }

    int last_r = (A + B) * 3 + 1;
    g[last_r - 1][1] = (P > 0) ? 'v' : 'X';

    cout << n << " " << m << "\n";
    for (const auto& row : g) cout << row << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    if (!(cin >> t)) return 0;
    while (t--) solve();
    return 0;
}