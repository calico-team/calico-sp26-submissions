#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
using ll = long long;
void solve() {
    ll P;
    int A, B;
    cin >> P >> A >> B;
    vector<int> divs;
    vector<int> rems;
    ll cur_P = P;
    for (int i = 0; i < A; ++i) {
        divs.push_back(2);
        rems.push_back(cur_P % 2);
        cur_P /= 2;
    }
    for (int i = 0; i < B; ++i) {
        divs.push_back(3);
        rems.push_back(cur_P % 3);
        cur_P /= 3;
    }

    reverse(divs.begin(), divs.end());
    reverse(rems.begin(), rems.end());

    int n = 3;
    int m = 2 * (A + B) + 2;
    vector<string> grid(n, string(m, '.'));

    grid[0][0] = 'v';
    grid[1][0] = '>';

    for (int k = 0; k < A + B; ++k) {
        int d = divs[k];
        int c = rems[k];
        int x = 1 + 2 * k;

        grid[1][x] = 'S';
        grid[1][x + 1] = '>';

        if (d == 2) {
            if (c == 1) grid[0][x] = '^';
            else grid[0][x] = 'X';
        } 
        else if (d == 3) {
            if (c == 2) {
                grid[0][x] = '^';
                grid[2][x] = 'v';
            } else if (c == 1) {
                grid[0][x] = '^';
                grid[2][x] = 'X';
            } else {
                grid[0][x] = 'X';
                grid[2][x] = 'X';
            }
        }
    }
    grid[1][m - 1] = 'X';
    cout << n << " " << m << "\n";
    for (int i = 0; i < n; ++i) {
        cout << grid[i] << "\n";
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    if (cin >> T) {
        while (T--) {
            solve();
        }
    }
    return 0;
}