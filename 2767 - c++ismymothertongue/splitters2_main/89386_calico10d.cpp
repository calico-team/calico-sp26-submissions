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

    int cur_a = A, cur_b = B;
    ll num = P;

    for (int i = 0; i < A + B; i++) {
        int r = i * 2 + 1;
        int base = (cur_b > 0) ? 3 : 2;
        if (cur_b > 0) cur_b--; else cur_a--;

        __int128 den = 1;
        for(int j = 0; j < cur_a; j++) den *= 2;
        for(int j = 0; j < cur_b; j++) den *= 3;

        int digit = (int)(num / (ll)den);
        num %= (ll)den;

        g[r][1] = 'S';
        g[r + 1][1] = 'v';

        if (base == 2) {
            g[r][0] = '>';
            g[r][2] = (digit == 1) ? '>' : 'X'; 
        } else {
            g[r][0] = (digit == 2) ? '<' : 'X'; 
            g[r][2] = (digit >= 1) ? '>' : 'X';
        }
    }

    g[n - 1][1] = 'X';

    cout << n << " " << m << "\n";
    for (const string& row : g) cout << row << "\n";
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; if (!(cin >> t)) return 0;
    while (t--) solve();
    return 0;
}