/*
 * O(log D) closed-form solution using floor-sum identities.
 *
 * By D4 symmetry, reduce to G at origin, M at (p, q) with p >= q >= 0.
 * The mycelium region is a convex polygon whose row-by-row widths have
 * closed-form floor expressions. Summing these analytically using the
 * Hermite / Stern-Brocot reciprocal identity gives O(log D) per query.
 *
 * The constants 5 = 7 - 2 (delay difference) and 9 = 7 + 2 (delay sum)
 * appear throughout the boundary formulas.
 */
#include <algorithm>
#include <iostream>

using namespace std;
typedef long long ll;

const int GRASS_DELAY = 2;
const int MYCELIUM_DELAY = 7;

/**
 * Compute sum_{k=0}^{n} floor((a*k + b) / d) in O(log max(a, d)) time
 * using the Hermite / Stern-Brocot reciprocal identity.
 */
ll floor_sum(ll a, ll b, ll d, ll n) {
    if (n < 0) return 0;
    if (a == 0) return (b / d) * (n + 1);

    ll result = 0;

    // Handle negative b by shifting upward.
    if (b < 0) {
        ll shift = (-b + d - 1) / d;
        b += shift * d;
        result -= shift * (n + 1);
    }

    // Pull out full multiples of d from a and b.
    if (a >= d) {
        result += (a / d) * n * (n + 1) / 2;
        a %= d;
    }
    if (b >= d) {
        result += (b / d) * (n + 1);
        b %= d;
    }

    if (a == 0) return result;

    // Reciprocal identity: 0 < a < d, 0 <= b < d.
    ll m = (a * n + b) / d;
    if (m == 0) return result;

    result += n * m - floor_sum(d, d - b - 1, a, m - 1);
    return result;
}

/**
 * Return the total number of tiles mycelium will ever occupy.
 *
 * X_G: x-coordinate of grass starting position
 * Y_G: y-coordinate of grass starting position
 * X_M: x-coordinate of mycelium starting position
 * Y_M: y-coordinate of mycelium starting position
 */
ll solve(int X_G, int Y_G, int X_M, int Y_M) {
    ll dx = abs(X_M - X_G);
    ll dy = abs(Y_M - Y_G);
    ll p = max(dx, dy);
    ll q = min(dx, dy);
    ll D = p + q;   // Manhattan distance
    ll A = p - q;   // Asymmetry parameter

    if (D == 0) return 1;

    // Vertical extent of the mycelium region.
    ll y_top = (2 * D - 1) / 5;
    ll y_bot_s1 = min(q, (2 * D - 1) / 9);
    ll y_bot_s2 = A > 0 ? (2 * A - 1) / 5 : 0;
    ll y_bot = max(y_bot_s1, y_bot_s2);

    // Constants for the bypass formulas.
    ll C_top = 2 * D + 4 * (y_top + 1) - 1;
    ll C_bot = 2 * A + 4 * (y_bot + 1) - 1;
    ll C_bot_eff = max(C_bot, 2 * D - 1);
    ll R_peak = C_bot_eff / 5;
    ll C_mid = C_bot_eff + 4 * (R_peak + 1);

    // === sum_xmin: three sectors ===

    // Sector 1: yr = 0..y_top
    ll B1 = 2 * D - 1 - 5 * y_top;
    ll sum_xmin_s1 = -floor_sum(5, B1, 9, y_top);

    // Sector 2: yr = -1..-n2 where n2 = min(y_bot, q)
    ll n2 = min(y_bot, q);
    ll W2 = (2 * D - 1) / 9;
    ll sum_xmin_s2 = -n2 * W2 + n2 * (n2 + 1) / 2;

    // Sector 3: yr below -q
    ll n3 = max(0LL, y_bot - q);
    ll sum_xmin_s3 = 0;
    if (n3 > 0) {
        ll B3 = A > 0 ? (2 * A - 1) % 5 : 0;
        sum_xmin_s3 = -floor_sum(5, B3, 9, n3 - 1);
    }

    ll sum_xmin = sum_xmin_s1 + sum_xmin_s2 + sum_xmin_s3;

    // === sum_xmax: positive and negative yr ===

    // yr >= 0: xmax = min(TOP_pos, MID), binary search for crossover.
    ll sum_xmax_pos = 0;
    if (y_top >= 0) {
        ll MID_0 = C_mid / 9;
        ll TOP_0 = C_top / 5;
        ll MID_yt = (C_mid - 5 * y_top) / 9;
        ll TOP_yt = (C_top - 9 * y_top) / 5;

        ll yr_cross;
        if (MID_0 > TOP_0) {
            yr_cross = -1;
        } else if (MID_yt <= TOP_yt) {
            yr_cross = y_top;
        } else {
            ll lo = 0, hi = y_top;
            while (lo < hi) {
                ll m = (lo + hi + 1) / 2;
                if ((C_mid - 5 * m) / 9 <= (C_top - 9 * m) / 5) lo = m;
                else hi = m - 1;
            }
            yr_cross = lo;
        }

        if (yr_cross >= 0) {
            ll B_mid = C_mid - 5 * yr_cross;
            sum_xmax_pos += floor_sum(5, B_mid, 9, yr_cross);
        }

        ll n_top = y_top - yr_cross;
        if (n_top > 0) {
            ll B_top = C_top - 9 * y_top;
            sum_xmax_pos += floor_sum(9, B_top, 5, n_top - 1);
        }
    }

    // yr < 0: xmax = floor((C_bot_eff + 9*yr) / 5)
    ll sum_xmax_neg = 0;
    if (y_bot > 0) {
        ll B_bot = C_bot_eff - 9 * y_bot;
        sum_xmax_neg = floor_sum(9, B_bot, 5, y_bot - 1);
    }

    ll sum_xmax = sum_xmax_pos + sum_xmax_neg;

    // Total = sum of (xmax - xmin + 1) over all rows.
    ll num_rows = y_top + y_bot + 1;
    return sum_xmax - sum_xmin + num_rows;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int X_G, Y_G, X_M, Y_M;
        cin >> X_G >> Y_G >> X_M >> Y_M;
        cout << solve(X_G, Y_G, X_M, Y_M) << '\n';
    }
}

