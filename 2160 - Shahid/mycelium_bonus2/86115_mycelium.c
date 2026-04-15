#include <stdio.h>
#include <stdlib.h>

/*
 * Problem 8: mycelium
 *
 * Grass at (xg,yg) spreads every 2 ticks => reaches (x,y) at tick 2*dg
 * Mycelium at (xm,ym) spreads every 7 ticks => reaches (x,y) at tick 7*dm
 * where dg = |x-xg|+|y-yg|, dm = |x-xm|+|y-ym|
 *
 * Tile becomes mycelium iff 7*dm < 2*dg (ties go to grass).
 *
 * Triangle inequality: dg >= D - dm where D = manhattan(grass, mycelium)
 * => 7*dm < 2*(D - dm) => 9*dm < 2*D => dm < 2D/9
 *
 * For each x, we iterate over valid y analytically.
 * f(y) = 7|y| - 2|y - gy| is piecewise linear, convex, minimum at y=0.
 * We need f(y) < R where R = 2|x-gx| - 7|x|.
 */

static long long myabs(long long x) { return x < 0 ? -x : x; }

/* Floor division: floor(a/b) for b > 0 */
static long long floordiv(long long a, long long b) {
    return a / b - (a % b != 0 && (a ^ b) < 0);
}

/* Largest y such that a*y < c (a > 0), i.e. y < c/a, y <= ceil(c/a) - 1 = floor((c-1)/a) */
static long long max_y_lt(long long a, long long c) {
    /* a*y < c => y <= floor((c-1)/a) */
    return floordiv(c - 1, a);
}

/* Smallest y such that a*y < c (a < 0, so -|a|*y < c => y > -c/|a|)
 * i.e. y > c/a (a<0 flips), y >= floor(c/a) + 1
 * Actually: a*y < c, a < 0 => y > c/a => y >= floor(c/a) + 1 */
static long long min_y_lt_neg(long long a, long long c) {
    /* a*y < c with a < 0 => y > c/a => smallest int y = floor(c/a) + 1 */
    return floordiv(c, a) + 1;
}

long long solve(long long xg, long long yg, long long xm, long long ym) {
    /* Shift so mycelium is at origin */
    long long gx = xg - xm;
    long long gy = yg - ym;
    long long D = myabs(gx) + myabs(gy);

    if (D == 0) return 1;

    /* dm < 2D/9, so max dm = floor((2D-1)/9) */
    long long max_dm = (2 * D - 1) / 9;

    long long count = 0;

    for (long long x = -max_dm; x <= max_dm; x++) {
        long long R = 2 * myabs(x - gx) - 7 * myabs(x);

        /* f(y) = 7|y| - 2|y - gy| < R
         * f is convex piecewise linear with breakpoints at y=0 and y=gy.
         * Minimum at y=0: f(0) = -2|gy|
         * If f(0) >= R, no solution for this x. */
        if (-2 * myabs(gy) >= R) continue;

        /* f is convex => solution set is an interval [y_lo, y_hi].
         *
         * Pieces (assuming gy >= 0):
         *   y < 0:       f = -5y - 2gy  (slope -5, decreasing leftward)
         *   0 <= y < gy: f = 9y - 2gy   (slope +9)
         *   y >= gy:     f = 5y + 2gy   (slope +5, increasing rightward)
         *
         * Pieces (assuming gy < 0):
         *   y <= gy:     f = -5y - 2gy  (slope -5)
         *   gy < y < 0:  f = -9y + 2gy  (slope -9)
         *   y >= 0:      f = 5y + 2gy   (slope +5)
         *
         * For the upper bound (y_hi): find largest y with f(y) < R
         *   going from min upward, last valid region determines bound.
         * For the lower bound (y_lo): find smallest y with f(y) < R.
         */

        long long y_lo, y_hi;

        if (gy >= 0) {
            /* Upper bound:
             * In y >= gy region: 5y + 2gy < R => y < (R - 2gy)/5
             * Largest y: floor((R - 2gy - 1)/5) */
            long long ub_outer = max_y_lt(5, R - 2 * gy);
            if (ub_outer >= gy) {
                y_hi = ub_outer;
            } else {
                /* In 0 <= y < gy region: 9y - 2gy < R => y < (R + 2gy)/9 */
                long long ub_mid = max_y_lt(9, R + 2 * gy);
                y_hi = (ub_mid < gy - 1) ? ub_mid : gy - 1;
                /* if ub_mid < 0, no positive y solutions on this side */
            }

            /* Lower bound:
             * In y < 0 region: -5y - 2gy < R => -5y < R + 2gy => y > -(R+2gy)/5
             * Smallest y: using min_y_lt_neg with a=-5, c = R + 2gy */
            y_lo = min_y_lt_neg(-5, R + 2 * gy);
            /* y_lo should be < 0 if there are negative solutions */
            if (y_lo >= 0) y_lo = 0;
        } else {
            /* gy < 0 */
            /* Upper bound:
             * In y >= 0 region: 5y + 2gy < R => y < (R - 2gy)/5 */
            y_hi = max_y_lt(5, R - 2 * gy);
            if (y_hi < 0) y_hi = -1; /* no non-negative solutions */

            /* Lower bound:
             * In y <= gy region: -5y - 2gy < R => y > -(R+2gy)/5 */
            long long lb_outer = min_y_lt_neg(-5, R + 2 * gy);
            if (lb_outer <= gy) {
                y_lo = lb_outer;
            } else {
                /* In gy < y < 0 region: -9y + 2gy < R => -9y < R - 2gy => y > -(R-2gy)/9 */
                long long lb_mid = min_y_lt_neg(-9, R - 2 * gy);
                y_lo = (lb_mid > gy + 1) ? lb_mid : gy + 1;
                if (y_lo >= 0) y_lo = 0;
            }
        }

        if (y_lo > y_hi) continue;
        count += y_hi - y_lo + 1;
    }

    return count;
}

int main(void) {
    int T;
    scanf("%d", &T);
    while (T--) {
        long long xg, yg, xm, ym;
        scanf("%lld %lld %lld %lld", &xg, &yg, &xm, &ym);
        printf("%lld\n", solve(xg, yg, xm, ym));
    }
    return 0;
}
