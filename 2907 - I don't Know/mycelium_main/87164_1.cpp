#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

long long floor_sum(long long n, long long m, long long a, long long b) {
    long long ans = 0;
    if (a >= m) {
        ans += (n - 1) * n / 2 * (a / m);
        a %= m;
    }
    if (b >= m) {
        ans += n * (b / m);
        b %= m;
    }
    long long y_max = (a * n + b) / m;
    if (y_max == 0) return ans;
    ans += (n - (m * y_max - b + a - 1) / a) * y_max;
    ans += floor_sum(y_max, a, m, (a - b % a) % a);
    return ans;
}

long long count_linear(long long A, long long B, long long C) {
    if (C <= A + B) return 0;
    long long x_max = (C - B - 1) / A;
    if (x_max <= 0) return 0;
    return floor_sum(x_max, B, A, C - 1 - A * x_max);
}

long long f_count(long long A, long long B, long long C, long long x1, long long y1) {
    long long C_prime = C - A * (x1 - 1) - B * (y1 - 1);
    return count_linear(A, B, C_prime);
}

long long count_box(long long A, long long B, long long C, long long x1, long long x2, long long y1, long long y2) {
    if (x1 > x2 || y1 > y2) return 0;
    return f_count(A, B, C, x1, y1) - f_count(A, B, C, x2 + 1, y1) - f_count(A, B, C, x1, y2 + 1) + f_count(A, B, C, x2 + 1, y2 + 1);
}

long long calc_R_forward(long long G_par, long long G_perp) {
    long long D = G_par + G_perp;
    long long max_le = (2 * D - 1) / 9;
    if (max_le < G_par) {
        return max(0LL, max_le);
    } else {
        long long num = 2 * (G_perp - G_par) - 1;
        if (num < 0) return G_par;
        return max(G_par, num / 5);
    }
}

void solve() {
    long long X_G, Y_G, X_M, Y_M;
    cin >> X_G >> Y_G >> X_M >> Y_M;

    long long X = abs(X_G - X_M);
    long long Y = abs(Y_G - Y_M);
    long long INF = 2000000000LL;

    long long R_Xp = calc_R_forward(X, Y);
    long long R_Yp = calc_R_forward(Y, X);
    long long X_pass = R_Xp + 1;
    long long Y_pass = R_Yp + 1;

    long long C_X = X + abs(Y - Y_pass) + Y_pass;
    long long C_Y = abs(X - X_pass) + Y + X_pass;

    long long R_Xm = (2 * C_X - 1) / 5;
    long long R_Ym = (2 * C_Y - 1) / 5;
    long long U_pass = R_Xm + 1;
    long long V_pass = R_Ym + 1;

    long long ans = 1;
    ans += max(0LL, R_Xp);
    ans += max(0LL, R_Yp);
    ans += max(0LL, R_Xm);
    ans += max(0LL, R_Ym);

    ans += count_box(9, 9, 2 * X + 2 * Y, 1, X, 1, Y);
    ans += count_box(5, 9, 2 * Y - 2 * X, X + 1, INF, 1, Y);
    ans += count_box(9, 5, 2 * X - 2 * Y, 1, X, Y + 1, INF);

    ans += count_box(5, 9, 2 * X + 2 * Y, 1, INF, max(1LL, Y_pass), Y);
    ans += count_box(5, 5, 2 * X - 2 * Y, 1, INF, max(Y + 1, Y_pass), INF);
    long long K2 = X + Y_pass + abs(Y - Y_pass);
    ans += count_box(5, 9, 2 * K2, 1, INF, 1, Y_pass - 1);

    ans += count_box(9, 5, 2 * Y + 2 * X, max(1LL, X_pass), X, 1, INF);
    ans += count_box(5, 5, 2 * Y - 2 * X, max(X + 1, X_pass), INF, 1, INF);
    long long K4 = Y + X_pass + abs(X - X_pass);
    ans += count_box(9, 5, 2 * K4, 1, X_pass - 1, 1, INF);

    ans += count_box(5, 5, 2 * min(C_X, C_Y), U_pass, INF, V_pass, INF);

    long long V_split = max(0LL, min(V_pass - 1, (2 * C_Y + 4 * V_pass - 2 * C_X) / 4));
    ans += count_box(5, 9, 2 * C_Y + 4 * V_pass, U_pass, INF, 1, V_split);
    ans += count_box(5, 5, 2 * C_X, U_pass, INF, V_split + 1, V_pass - 1);

    long long U_split = max(0LL, min(U_pass - 1, (2 * C_X + 4 * U_pass - 2 * C_Y) / 4));
    ans += count_box(9, 5, 2 * C_X + 4 * U_pass, 1, U_split, V_pass, INF);
    ans += count_box(5, 5, 2 * C_Y, U_split + 1, U_pass - 1, V_pass, INF);

    long long C1 = 2 * C_Y + 4 * V_pass;
    long long C2 = 2 * C_X + 4 * U_pass;
    long long low = 1, high = V_pass - 1, V_mid = 0;
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if ((C1 - 1 - 9 * mid) / 5 >= (C2 - 1 - 5 * mid) / 9) {
            V_mid = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    ans += count_box(9, 5, C2, 1, U_pass - 1, 1, V_mid);
    ans += count_box(5, 9, C1, 1, U_pass - 1, V_mid + 1, V_pass - 1);

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    if (cin >> T) {
        while (T--) {
            solve();
        }
    }
    return 0;
}