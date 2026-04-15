#include <bits/stdc++.h>
using namespace std;

using uint64 = unsigned long long;
const int MAXC = 500;

char grid[3][MAXC];
int max_col, cur_col;
int A_global, B_global;

uint64 calc_half(int e2, int e3) {
    uint64 res = 1;
    for (int i = 0; i < e2 - 1; ++i) res *= 2;
    for (int i = 0; i < e3; ++i) res *= 3;
    return res;
}

uint64 calc_third(int e2, int e3) {
    uint64 res = 1;
    for (int i = 0; i < e2; ++i) res *= 2;
    for (int i = 0; i < e3 - 1; ++i) res *= 3;
    return res;
}

bool ge_half(uint64 rem, int e2, int e3) {
    if (rem == 0) return false;
    if (e2 - 1 + e3 * 1.585 > 40) {
        __int128 val = 1;
        for (int i = 0; i < e2 - 1; ++i) { val *= 2; if (val > rem) return false; }
        for (int i = 0; i < e3; ++i) { val *= 3; if (val > rem) return false; }
        return rem >= (uint64)val;
    }
    uint64 val = 1;
    for (int i = 0; i < e2 - 1; ++i) val *= 2;
    for (int i = 0; i < e3; ++i) val *= 3;
    return rem >= val;
}

bool ge_third(uint64 rem, int e2, int e3) {
    if (rem == 0) return false;
    if (e2 + (e3 - 1) * 1.585 > 40) {
        __int128 val = 1;
        for (int i = 0; i < e2; ++i) { val *= 2; if (val > rem) return false; }
        for (int i = 0; i < e3 - 1; ++i) { val *= 3; if (val > rem) return false; }
        return rem >= (uint64)val;
    }
    uint64 val = 1;
    for (int i = 0; i < e2; ++i) val *= 2;
    for (int i = 0; i < e3 - 1; ++i) val *= 3;
    return rem >= val;
}

void place_collect(int row, int col) {
    for (int c = col; c < MAXC; ++c) grid[row][c] = '>';
    max_col = max(max_col, MAXC - 1);
    cur_col = MAXC - 1;
}

void build(int a, int b, uint64 rem) {
    if (a == A_global && b == B_global) {
        ++cur_col;
        place_collect(1, cur_col);
        return;
    }
    if (rem == 0) {
        ++cur_col;
        grid[1][cur_col] = 'X';
        max_col = max(max_col, cur_col);
        return;
    }
    if (a < A_global) {
        int s_col = cur_col + 1;
        grid[1][s_col] = 'S';
        grid[1][s_col + 1] = '>';
        cur_col = s_col + 1;
        max_col = max(max_col, cur_col);
        int e2 = A_global - a, e3 = B_global - b;
        bool take_up = ge_half(rem, e2, e3);
        if (take_up) {
            grid[0][s_col] = '^';
            rem -= calc_half(e2, e3);
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
        int e2 = A_global - a, e3 = B_global - b;
        uint64 third = calc_third(e2, e3);
        bool take_up = false, take_down = false;
        if (ge_third(rem, e2, e3)) {
            take_up = true;
            rem -= third;
            if (ge_third(rem, e2, e3)) {
                take_down = true;
                rem -= third;
            }
        }
        grid[0][s_col] = take_up ? '^' : 'X';
        grid[2][s_col] = take_down ? 'v' : 'X';
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
            for (int j = 0; j < M; ++j) cout << grid[i][j];
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