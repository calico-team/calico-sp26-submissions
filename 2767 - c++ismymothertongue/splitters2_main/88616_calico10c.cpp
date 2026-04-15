#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef long long ll;

void solve() {
    ll P;
    int A, B;
    if (!(cin >> P >> A >> B)) return;

    int n = (A + B) * 2 + 2;
    int m = 3;
    vector<string> g(n, string(m, '.'));

    g[0][1] = 'v';

    for (int i = 0; i < A + B; i++) {
        int r = i * 2 + 1;
        int base = (i < A) ? 2 : 3;
        int rem = P % base;
        P /= base;

        g[r][1] = 'S';
        g[r + 1][1] = 'v';

        if (base == 2) {
            g[r][2] = (rem == 1) ? '>' : 'X';
        } else {
            g[r][2] = (rem >= 1) ? '>' : 'X';
            g[r][0] = (rem == 2) ? '<' : 'X';
        }
    }

    int last_r = (A + B) * 2 + 1;
    if (P > 0) g[last_r][1] = 'v';
    else g[last_r][1] = 'X';

    cout << n << " " << m << "\n";
    for (int i = 0; i < n; i++) {
        cout << g[i] << "\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    if (!(cin >> t)) return 0;
    while (t--) solve();
    return 0;
}