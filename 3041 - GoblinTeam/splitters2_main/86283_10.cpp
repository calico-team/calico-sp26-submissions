#include <bits/stdc++.h>
using namespace std;

using uint64 = unsigned long long;
const uint64 INF = 1e13;
const int MAXC = 500;

char grid[3][MAXC];
int max_col;
int cur_col;
int A_global, B_global;

uint64 calc_unit(int p2, int p3) {
    uint64 res = 1;
    for (int i = 0; i < p2; ++i) {
        if (res > INF / 2) return INF;
        res *= 2;
    }
    for (int i = 0; i < p3; ++i) {
        if (res > INF / 3) return INF;
        res *= 3;
    }
    return res;
}

void place_collect(int row, int col) {
    for (int c = col; c < MAXC; ++c) {
        grid[row][c] = '>';
    }
    max_col = max(max_col, MAXC - 1);
    cur_col = MAXC - 1;
}

void build(int a, int b, uint64 rem) {
    uint64 unit = calc_unit(A_global - a, B_global - b);
    if (rem == 0) {
        ++cur_col;
        grid[1][cur_col] = 'X';
        max_col = max(max_col, cur_col);
        return;
    }
    if (unit != INF && rem == unit) {
        place_collect(1, cur_col + 1);
        return;
    }
    if (a < A_global) {
        int s_col = cur_col + 1;
        grid[1][s_col] = 'S';
        grid[1][s_col + 1] = '>';
        cur_col = s_col + 1;
        max_col = max(max_col, cur_col);
        uint64 half = (unit == INF ? INF : unit / 2);
        if (half == INF || rem >= half) {
            grid[0][s_col] = '^';
            if (half != INF) rem -= half;
        } else {
            grid[0][s_col] = 'X';
        }
        grid[2][s_col] = '.';
        build(a + 1, b, rem);
    } else if (b < B_global) {
        int s_col = cur_col + 1;
        grid[1][s_col] = 'S';
        grid[1][s_col + 1] = '>';
        cur_col = s_col + 1;
        max_col = max(max_col, cur_col);
        uint64 third = (unit == INF ? INF : unit / 3);
        if (third == INF || rem >= third) {
            grid[0][s_col] = '^';
            if (third != INF) rem -= third;
        } else {
            grid[0][s_col] = 'X';
        }
        if (third == INF || rem >= third) {
            grid[2][s_col] = 'v';
            if (third != INF) rem -= third;
        } else {
            grid[2][s_col] = 'X';
        }
        build(a, b + 1, rem);
    }
}

void solve() {
    int T;
    cin >> T;
    while (T--) {
        uint64 P;
        int A, B;
        cin >> P >> A >> B;
        A_global = A;
        B_global = B;
        memset(grid, '.', sizeof(grid));
        grid[1][0] = '>';
        cur_col = 0;
        max_col = 0;
        build(0, 0, P);
        int N = 3, M = max_col + 1;
        cout << N << " " << M << "\n";
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                cout << grid[i][j];
            }
            cout << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}