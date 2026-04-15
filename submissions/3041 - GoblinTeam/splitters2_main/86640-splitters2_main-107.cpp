#include <bits/stdc++.h>
using namespace std;

using uint64 = unsigned long long;
const uint64 INF = 2000000000000000000ULL;
const int MAXC = 500;

char grid[3][MAXC];
int max_col, cur_col;

uint64 unit(int a, int b) {
    uint64 res = 1;
    for (int i = 0; i < a; ++i) {
        if (res > INF / 2) return INF;
        res *= 2;
    }
    for (int i = 0; i < b; ++i) {
        if (res > INF / 3) return INF;
        res *= 3;
    }
    return res;
}

void build(uint64 rem, int a, int b) {
    if (rem == 0) {
        ++cur_col;
        grid[1][cur_col] = 'X';
        max_col = max(max_col, cur_col);
        return;
    }
    if (a == 0 && b == 0) {
        ++cur_col;
        grid[1][cur_col] = '^';
        max_col = max(max_col, cur_col);
        return;
    }
    if (a > 0) {
        int c = cur_col + 1;
        grid[1][c] = 'S';
        uint64 half = unit(a - 1, b);
        bool take_up = (half <= rem);
        if (take_up) rem -= half;
        grid[0][c] = take_up ? '^' : 'X';
        grid[2][c] = '.';
        grid[1][c + 1] = '>';
        cur_col = c + 1;
        max_col = max(max_col, cur_col);
        build(rem, a - 1, b);
    } else {
        int c = cur_col + 1;
        grid[1][c] = 'S';
        uint64 third = unit(a, b - 1);
        bool take_up = false, take_down = false;
        if (third <= rem) {
            take_up = true;
            rem -= third;
            if (third <= rem) {
                take_down = true;
                rem -= third;
            }
        }
        grid[0][c] = take_up ? '^' : 'X';
        grid[2][c] = take_down ? 'v' : 'X';
        grid[1][c + 1] = '>';
        cur_col = c + 1;
        max_col = max(max_col, cur_col);
        build(rem, a, b - 1);
    }
}

void solve() {
    int T;
    cin >> T;
    while (T--) {
        uint64 P;
        int A, B;
        cin >> P >> A >> B;
        memset(grid, '.', sizeof(grid));
        grid[1][0] = '>';
        cur_col = 0;
        max_col = 0;
        build(P, A, B);
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