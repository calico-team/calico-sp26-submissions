#include <iostream>
#include <algorithm>

#define int int

using namespace std;

int floor_div(int a, int b) {
    int res = a / b;
    int rem = a % b;
    if (rem != 0 && ((a < 0) ^ (b < 0))) {
        res--;
    }
    return res;
}

int floor_sum(int a, int b, int c, int n) {
    if (n < 0) return 0;
    int res = 0;
    if (a >= c) {
        res += (a / c) * n * (n + 1) / 2;
        a %= c;
    }
    if (b >= c) {
        res += (b / c) * (n + 1);
        b %= c;
    }
    int m = (a * n + b) / c;
    if (m == 0) return res;
    res += floor_sum(c, c - b - 1, a, m - 1);
    return res;
}

int count_line(int A, int B, int C) {
    int N = floor_div(C, A);
    if (N < 1) return 0;
    return N + floor_sum(A, C - A * N, B, N - 1);
}

/**
 * Return the total number of tiles mycelium will ever occupy.
 *
 * X_G: x-coordinate of grass starting position
 * Y_G: y-coordinate of grass starting position
 * X_M: x-coordinate of mycelium starting position
 * Y_M: y-coordinate of mycelium starting position
 */
int solve(int X_G, int Y_G, int X_M, int Y_M) {
    int X = abs(X_G - X_M);
    int Y = abs(Y_G - Y_M);
    int D = X + Y;

    if (D == 0) return 0;

    int ans = 0;

    int Lx = floor_div(2 * D - 1, 5);
    int Ly = floor_div(2 * D - 1, 5);
    int Rx = max(floor_div(2 * D - 1, 9), floor_div(2 * (Y - X) - 1, 5));
    int Ry = max(floor_div(2 * D - 1, 9), floor_div(2 * (X - Y) - 1, 5));

    // Quadrant 1 (x >= 0, y >= 0)
    int K1 = floor_div(2 * D - 1, 9);
    if (K1 >= 0) {
        ans += (K1 + 1) * (K1 + 2) / 2;
    }

    // Quadrant 2 (x <= -1, y >= 0)
    if (Y > Ry) {
        ans += count_line(5, 9, 2 * D - 1);
    } else {
        ans += count_line(5, 9, 2 * (X - Y) + 4 * Ry + 3);
    }

    // Quadrant 4 (x >= 0, y <= -1)
    if (X > Rx) {
        ans += count_line(5, 9, 2 * D - 1);
    } else {
        ans += count_line(5, 9, 2 * (Y - X) + 4 * Rx + 3);
    }

    // Quadrant 3 (x <= -1, y <= -1)
    int yc = max(Y, Ry + 1);
    int xc = max(X, Rx + 1);
    int C_TL = 2 * (X - Y + 2 * Lx + 2 * yc) + 3;
    int C_BR = 2 * (Y - X + 2 * Ly + 2 * xc) + 3;

    int N_BR = floor_div(C_BR - 9, 5);
    int N_TL = floor_div(C_TL - 5, 9);
    int max_W = min(N_BR, N_TL);

    if (max_W >= 1) {
        int W = floor_div(9 * C_TL - 5 * C_BR, 56);
        int split = max(0, min(W, max_W));

        // For 1 <= w <= split
        if (split >= 1) {
            ans += split + floor_sum(5, C_BR - 5 * split, 9, split - 1);
        }

        // For split < w <= max_W
        if (max_W > split) {
            int count = max_W - split;
            ans += count + floor_sum(9, C_TL - 9 * max_W, 5, count - 1);
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    if (cin >> T) {
        for (int i = 0; i < T; i++) {
            int X_G, Y_G, X_M, Y_M;
            cin >> X_G >> Y_G >> X_M >> Y_M;
            cout << solve(X_G, Y_G, X_M, Y_M) << '\n';
        }
    }
    return 0;
}
