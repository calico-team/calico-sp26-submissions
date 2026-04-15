#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <queue>

using namespace std;
#define int long long

int powMod(int base, int exp, int mod) {
    if (exp == 1) return base;
    else if (exp == 0) return 1;
    else if (base < 2) return base;

    int ans = 1;

    while (exp > 0) {
        if (exp % 2) {
            ans *= base;
        }

        base = base * base % mod;
        exp /= 2;
        ans %= mod;
    }
    return ans;
}

void solve() {
    int p, a, b; cin >> p >> a >> b;
    float dig = a * log10(2) + b * log10(3);
    int n = 2 * (a + b) + 1;
    cout << "3 " << n << endl;

    vector<vector<char> > grid(3, vector<char> (n, '.'));

    grid[0][0] = 'v'; grid[1][0] = '>';

    for (int i = 1; i < n; i++) {
        if (i % 2) grid[1][i] = 'S';
        else grid[1][i] = '>';
    }
    
    int count = 1;

    if (dig > 14) {
        while (dig > 14 && b > 0) {
            dig -= log10(3);
            b--;

            grid[0][count] = 'X';
            grid[2][count] = 'X';

            count += 2;
        }

        while (dig > 14 && a > 0) {
            dig -= log10(2);
            a--;

            grid[0][count] = 'X';
            
            count += 2;
        }
    }

    int q = 1;
    for (int i = 0; i < a; i++) q *= 2;
    for (int i = 0; i < b; i++) q *= 3;

    while (count < n) {
        if (b > 0) {
            q /= 3; b--;
            if (p > 2 * q) {
                grid[0][count] = '^';
                grid[2][count] = 'v';
                p -= 2 * q;
            } else if (p > q) {
                grid[0][count] = '^';
                grid[2][count] = 'X';
                p -= q;
            } else {
                grid[0][count] = 'X';
                grid[2][count] = 'X';
            }
        } else if (a > 0) {
            q /= 2; a--;
            if (p > q) {
                grid[0][count] = '^';
                p -= q;
            } else {
                grid[0][count] = 'X';
            }
        }

        count += 2;
    }

    for (auto i: grid) {
        for (auto j: i) {
            cout << j;
        }
        cout << endl;
    }
}


signed main() {
    int t; cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}