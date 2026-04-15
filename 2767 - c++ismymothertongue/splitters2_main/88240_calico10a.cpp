#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve() {
    long long P;
    int A, B;
    if (!(cin >> P >> A >> B)) return;

   
    int n = A + B + 1;
    int m = 4;
    vector<string> grid(n, string(m, '.'));

    for (int i = 0; i < A + B; i++) {
        grid[i][0] = 'S';
        int base = (i < A) ? 2 : 3;
        int rem = P % base;
        P /= base;

        if (base == 2) {
            
            if (i + 1 < n) grid[i + 1][0] = 'v';
            grid[i][1] = (rem == 1) ? '>' : 'X';
        } else {
            
            if (i + 1 < n) grid[i + 1][0] = 'v';
            grid[i][1] = (rem >= 1) ? '>' : 'X';
            grid[i][2] = (rem == 2) ? '>' : 'X';
        }
    }

   
    if (P > 0) grid[n - 1][0] = 'v';
    else grid[n - 1][0] = 'X';

    cout << n << " " << m << "\n";
    for (const auto& row : grid) {
        cout << row << "\n";
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