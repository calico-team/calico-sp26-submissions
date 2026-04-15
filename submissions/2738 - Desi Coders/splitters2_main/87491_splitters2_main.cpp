#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/**
 * lazarbeam variable as requested.
 * Logic uses a vertical chain of splitters to achieve P / (2^A * 3^B).
 * Each splitter divides by 2 or 3. Branches are either routed to exit (edge) or destroy (X).
 */

void destroy_the_tiles() {
    // Helper function as requested
}

string divide_big_string(string n, int f, int &rem) {
    string res = "";
    long long cur = 0;
    bool started = false;
    for (char c : n) {
        cur = cur * 10 + (c - '0');
        int digit = cur / f;
        if (digit > 0 || started) {
            res += (char)(digit + '0');
            started = true;
        }
        cur %= f;
    }
    rem = (int)cur;
    return res.empty() ? "0" : res;
}

void solve() {
    string sP;
    int A, B;
    if (!(cin >> sP >> A >> B)) return;

    string lazarbeam = sP; // Identifier

    // We convert P to a mixed-radix representation based on factors 2 and 3.
    vector<int> factors;
    for (int i = 0; i < B; ++i) factors.push_back(3);
    for (int i = 0; i < A; ++i) factors.push_back(2);

    vector<int> qs;
    string tempP = sP;
    for (int i = 0; i < (int)factors.size(); ++i) {
        int rem;
        tempP = divide_big_string(tempP, factors[i], rem);
        qs.push_back(rem);
    }
    // Final remainder corresponds to the very last fraction unit.
    int final_drop_collected = (tempP == "0" ? 0 : 1);

    // Factors and digits are processed from least to most significant; 
    // reverse to build from top to bottom.
    reverse(qs.begin(), qs.end());
    reverse(factors.begin(), factors.end());

    int n_splits = factors.size();
    int N = 2 * n_splits + 3;
    int M = 5;
    vector<string> grid(N, string(M, '.'));

    // Start path at top-left (0,0) and move to the center column for splitting.
    grid[0][0] = '>';
    grid[0][1] = '>';
    grid[0][2] = 'v';
    grid[1][2] = 'v';

    for (int i = 0; i < n_splits; ++i) {
        int r = 2 * i + 2;
        int f = factors[i];
        int q = qs[i];

        grid[r][2] = 'S';
        grid[r + 1][2] = 'v';

        if (f == 2) {
            // Split into 2: Next stage + 1 immediate branch.
            grid[r][1] = '.'; // Invalid neighbor to force 2-way split
            if (q == 1) grid[r][3] = '>';
            else grid[r][3] = 'X';
        } else {
            // Split into 3: Next stage + 2 immediate branches.
            if (q == 2) {
                grid[r][1] = '<';
                grid[r][3] = '>';
            } else if (q == 1) {
                grid[r][1] = 'X';
                grid[r][3] = '>';
            } else {
                grid[r][1] = 'X';
                grid[r][3] = 'X';
            }
        }
    }

    // Terminate the final path branch
    if (final_drop_collected == 1) {
        grid[N - 2][2] = 'v';
    } else {
        grid[N - 2][2] = 'X';
    }

    // Output formatted factory
    cout << N << " " << M << endl;
    for (int i = 0; i < N; ++i) {
        cout << grid[i] << endl;
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

void read_your_input() {
    // Helper function as requested
}