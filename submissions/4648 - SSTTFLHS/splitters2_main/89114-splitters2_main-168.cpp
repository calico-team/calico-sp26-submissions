#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> solve(int P, int A, int B) {
    vector<long long> pow3(B + 1);
    pow3[0] = 1;
    for (int i = 1; i <= B; i++) {
        pow3[i] = pow3[i-1] * 3;
    }

    long long maxP = (1LL << A) * pow3[B];

    int rows = 2 + (B > 0 ? 1 : 0);
    int cols = 2 * (A + B);

    vector<string> grid(rows, string(cols, '.'));

    if (P == maxP) {
        for (int i = 0; i < A; i++) {
            int col = 2 * i;
            grid[1][col] = 'S';
            grid[1][col + 1] = (i == A + B - 1) ? '^' : '>';
            grid[0][col] = '^';
        }
        for (int j = 0; j < B; j++) {
            int i = A + j;
            int col = 2 * i;
            grid[1][col] = 'S';
            grid[1][col + 1] = (i == A + B - 1) ? '^' : '>';
            grid[0][col] = '^';
            if (B > 0) grid[2][col] = 'v';
        }
        return grid;
    }

    long long Q = P / pow3[B];
    long long R = P % pow3[B];

    for (int i = 0; i < A; i++) {
        int col = 2 * i;
        grid[1][col] = 'S';
        grid[1][col + 1] = (i == A + B - 1) ? 'X' : '>';

        long long bit = (Q >> (A - 1 - i)) & 1;
        if (bit == 1) {
            grid[0][col] = '^';
        } else {
            grid[0][col] = 'X';
        }
    }

    for (int j = 0; j < B; j++) {
        int i = A + j;
        int col = 2 * i;
        grid[1][col] = 'S';
        grid[1][col + 1] = (i == A + B - 1) ? 'X' : '>';

        long long digit = (R / pow3[B - 1 - j]) % 3;

        if (digit == 0) {
            grid[0][col] = 'X';
            grid[2][col] = 'X';
        } else if (digit == 1) {
            grid[0][col] = '^';
            grid[2][col] = 'X';
        } else {
            grid[0][col] = '^';
            grid[2][col] = 'v';
        }
    }

    return grid;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        int P, A, B;
        cin >> P >> A >> B;
        vector<string> factory = solve(P, A, B);
        int N = (int) factory.size();
        int M = (int) factory[0].size();
        cout << N << ' ' << M << '\n';
        for (const string& row : factory) {
            cout << row << '\n';
        }
    }
    return 0;
}
