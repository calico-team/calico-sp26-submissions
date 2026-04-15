#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * Problem 8: mycelium
 *
 * Grass at (xg,yg) spreads every 2 ticks => reaches (x,y) at tick 2*dg
 * Mycelium at (xm,ym) spreads every 7 ticks => reaches (x,y) at tick 7*dm
 * where dg = |x-xg|+|y-yg|, dm = |x-xm|+|y-ym|
 *
 * Tile becomes mycelium iff 7*dm < 2*dg (ties go to grass).
 * Count all such tiles.
 *
 * Observation: 7*dm < 2*dg
 *   => 7*dm < 2*dg
 *   => dm < (2/7)*dg
 *
 * The set of mycelium tiles forms a bounded region around (xm,ym).
 * We can bound the search: if dm >= some max, 7*dm >= 2*dg can't hold.
 *
 * Let D = |xg-xm|+|yg-ym| (Manhattan distance between sources).
 * dg >= D - dm (triangle inequality), so 7*dm < 2*(D - dm) => 9*dm < 2*D => dm < 2D/9.
 * So we only need to check tiles within Manhattan distance floor(2*D/9) of mycelium.
 * But also dg <= D + dm, we need 7*dm < 2*dg which is always satisfiable for small dm.
 *
 * For large coordinates (bonus 3, up to 4e8), D can be ~1.6e9, dm up to ~3.5e8.
 * Direct enumeration won't work. We need a smarter approach for that.
 *
 * For bonus sets 1-2 (coords up to 3000), D up to 12000, dm up to 2666,
 * search area ~dm^2 ~ 7M tiles. Feasible.
 *
 * For bonus 3, we need analytical counting.
 */

static long long abs_ll(long long x) { return x < 0 ? -x : x; }

/* Analytical approach for counting tiles where 7*dm < 2*dg.
 *
 * Let's place mycelium at origin by shifting coordinates.
 * Then grass is at (gx, gy) where gx = xg - xm, gy = yg - ym.
 *
 * We need to count integer points (x,y) such that:
 *   7*(|x| + |y|) < 2*(|x - gx| + |y - gy|)
 *
 * Expand by quadrants of (x,y) and quadrants of (x-gx, y-gy).
 * This is complex but we can iterate over x and find range of y analytically.
 *
 * 7*(|x|+|y|) < 2*(|x-gx|+|y-gy|)
 *
 * For a fixed x, this defines a range of valid y values.
 * dm = |x|+|y|, dg = |x-gx|+|y-gy|
 *
 * We know dm < 2*D/9 where D = |gx|+|gy|.
 * So |x| <= 2*D/9, meaning x ranges from -(2D/9) to (2D/9).
 *
 * For each x, we solve for y: 7|x|+7|y| < 2|x-gx|+2|y-gy|
 *   => 7|y| - 2|y-gy| < 2|x-gx| - 7|x|
 *
 * Let R = 2*|x-gx| - 7*|x| (known for fixed x)
 * Need: 7|y| - 2|y-gy| < R
 *
 * f(y) = 7|y| - 2|y-gy| is piecewise linear with breakpoints at y=0 and y=gy.
 *
 * Case analysis for f(y) = 7|y| - 2|y - gy|:
 *   If gy >= 0:
 *     y < 0:       f(y) = -7y - 2(gy - y) = -5y - 2gy
 *     0 <= y < gy: f(y) =  7y - 2(gy - y) =  9y - 2gy
 *     y >= gy:     f(y) =  7y - 2(y - gy) =  5y + 2gy
 *   If gy < 0:
 *     y <= gy:     f(y) = -7y - 2(gy - y) = -5y - 2gy
 *     gy < y < 0:  f(y) = -7y - 2(y - gy) = -9y + 2gy
 *     y >= 0:      f(y) =  7y - 2(y - gy) =  5y + 2gy
 *
 * In each piece, f is linear. We need f(y) < R.
 * We find the range of y in each piece satisfying this, then union them.
 */

long long solve(long long xg, long long yg, long long xm, long long ym) {
    long long gx = xg - xm;
    long long gy = yg - ym;
    long long D = abs_ll(gx) + abs_ll(gy);

    if (D == 0) return 1; /* same position, but problem says they differ */

    /* dm < 2D/9, so max |x| we check */
    long long max_dm = (2 * D) / 9; /* floor */
    /* Actually dm < 2D/9, so max_dm = floor((2D-1)/9) but let's be safe */
    /* 9*dm < 2*D => dm <= (2D-1)/9 */

    long long count = 0;

    for (long long x = -max_dm; x <= max_dm; x++) {
        long long R = 2 * abs_ll(x - gx) - 7 * abs_ll(x);
        /* Need 7|y| - 2|y - gy| < R */
        /* Also need |x| + |y| >= 0 (always true) */
        /* Also dm = |x|+|y| must satisfy 9*dm < 2*D => |y| < (2*D - 9*|x|)/9 ..
           but that's already handled by the condition */

        /* max |y| from dm constraint: |x|+|y| <= max_dm => |y| <= max_dm - |x| */
        long long max_y_abs = max_dm - abs_ll(x);
        if (max_y_abs < 0) continue;

        /* f(y) = 7|y| - 2|y - gy| < R
         * We need to count integer y in [-max_y_abs - some margin, max_y_abs + some margin]
         * Actually let's just solve f(y) < R properly.
         *
         * The function f(y) has a minimum. We find the y-range where f(y) < R.
         * f is piecewise linear with slopes:
         *   If gy >= 0:
         *     y < 0:       slope = -5  (decreasing as y decreases from 0)
         *     0 <= y < gy: slope = +9
         *     y >= gy:     slope = +5
         *   If gy < 0:
         *     y <= gy:     slope = -5
         *     gy < y < 0:  slope = -9
         *     y >= 0:      slope = +5
         *
         * So minimum of f is at:
         *   gy >= 0: minimum at y=0, f(0) = -2*gy = -2|gy|
         *   gy < 0:  minimum at y=0, f(0) = 2*gy = -2|gy|
         *
         * Actually for gy >= 0: f(0) = 0 - 2*(gy-0) = -2gy. Correct.
         * For gy < 0: f(0) = 0 - 2*(0-gy) = 2gy = -2|gy|. Correct.
         * So f_min = -2*|gy|, always at y=0.
         *
         * If -2|gy| >= R, no solutions.
         */
        long long abs_gy = abs_ll(gy);
        if (-2 * abs_gy >= R) continue;

        /* Now find the range [y_lo, y_hi] where f(y) < R.
         * f is V-shaped-ish with minimum at y=0.
         *
         * For y going negative (y < 0, or y < gy if gy < 0):
         *   Eventually f(y) = -5y - 2gy which increases as y decreases.
         *   -5y - 2gy < R => -5y < R + 2gy => y > -(R + 2gy)/5
         *
         * For y going positive (y > gy if gy >= 0, or y > 0 if gy < 0):
         *   Eventually f(y) = 5y + 2gy which increases as y increases.
         *   5y + 2gy < R => y < (R - 2gy)/5
         *
         * Let's find bounds more carefully.
         */

        long long y_lo, y_hi;

        /* Upper bound: for large positive y (y >= max(0, gy)):
         * f(y) = 5y + 2gy < R => y < (R - 2gy)/5
         * Since R, gy are integers, y <= floor((R - 2gy - 1)/5)
         */
        {
            long long num = R - 2 * gy - 1;
            if (num < 0)
                y_hi = num / 5 - 1; /* careful with negative division */
            else
                y_hi = num / 5;
            /* But this is valid only in the region y >= max(0, gy).
             * If the bound falls below this region, we need to check other pieces. */
        }

        /* Lower bound: for large negative y (y <= min(0, gy)):
         * f(y) = -5y - 2gy < R => -5y < R + 2gy => y > -(R + 2gy)/5
         * y >= floor(-(R + 2gy)/5) + 1 = ceil(-(R + 2gy - 1)/5)
         * Actually: y > -(R+2gy)/5, so y >= floor(-(R+2gy)/5) + 1 if not exact,
         *   or floor(...)+1 if exact (strict inequality).
         * -5y - 2gy < R => -5y < R + 2gy => 5y > -(R+2gy) => y > -(R+2gy)/5
         * Since strict: y >= floor(-(R+2gy)/5) + 1 if 5 divides (R+2gy),
         *   else y >= ceil(-(R+2gy)/5)
         * Simplify: y >= floor(-(R+2gy-1)/5) + 1 ... let's just compute:
         */
        {
            /* y > -(R + 2gy) / 5, strict */
            long long num = -(R + 2 * gy);
            /* y > num/5, so y >= floor(num/5) + 1 */
            long long div;
            if (num >= 0)
                div = num / 5;
            else
                div = (num - 4) / 5; /* floor division for negative */
            y_lo = div + 1;
            /* But check: if num % 5 != 0, ceil(num/5) works too.
             * Actually y > num/5 strictly. If num/5 is integer, y >= num/5 + 1.
             * If not, y >= ceil(num/5).
             * floor(num/5) + 1 >= ceil(num/5) always, and equals it when num%5==0 gives +1.
             * Hmm, let me just be safe: */
            /* y_lo = smallest integer > num/5 */
            /* = floor(num/5) + 1 if num%5 == 0, else ceil(num/5) */
            if (num >= 0) {
                if (num % 5 == 0) y_lo = num / 5 + 1;
                else y_lo = num / 5 + 1;
            } else {
                /* For negative: floor(-7/5) = -2, ceil(-7/5) = -1 */
                /* num = -7, num/5.0 = -1.4, smallest int > -1.4 is -1 */
                long long rem = num % 5;
                if (rem < 0) rem += 5;
                if (rem == 0) y_lo = num / 5 + 1;
                else y_lo = (num - rem) / 5 + 1;
            }
        }

        /* These bounds come from the outermost linear pieces.
         * But in the middle pieces the slope is steeper (9 vs 5),
         * so if f(y) < R in the outer pieces, it's also < R in the middle.
         * Since f has minimum at y=0 with value -2|gy|, and slopes going
         * outward are 5 (outer) > 9 (middle), wait no:
         *
         * For gy >= 0: slopes are -5 (y<0), +9 (0<=y<gy), +5 (y>=gy)
         * So going positive from 0: slope is 9 first, then 5.
         * That means f increases faster in [0,gy] then slower after gy.
         *
         * So the boundary from the outer piece (slope 5) might overestimate.
         * We need to also check the inner boundary.
         *
         * Let me reconsider. The valid y range where f(y) < R is contiguous
         * (since f is convex-like / V-shaped). So I just need the true
         * leftmost and rightmost y satisfying f(y) < R.
         *
         * Let me compute f at a few key points and find exact bounds.
         */

        /* Reset and compute properly */
        /* f(y) = 7|y| - 2|y - gy| */
        /* This is convex (max of linear functions), so {y : f(y) < R} is an interval. */

        /* For the upper bound:
         * If gy >= 0:
         *   Check y >= gy region: 5y + 2gy < R => y < (R - 2gy)/5
         *   Check 0 <= y < gy region: 9y - 2gy < R => y < (R + 2gy)/9
         *   The effective upper bound is the one from whichever region it falls in.
         *   If (R-2gy)/5 >= gy, upper bound is floor((R-2gy-1)/5) [in outer region]
         *   Else if (R+2gy)/9 > 0, upper bound is min(floor((R+2gy-1)/9), gy-1) [in middle region]
         *     But also check if (R-2gy) <= 0, meaning outer region has no solutions,
         *     then upper bound comes from middle region only.
         * If gy < 0:
         *   y >= 0 region: 5y + 2gy < R => y < (R - 2gy)/5, upper bound floor((R-2gy-1)/5)
         *   (no middle region above 0)
         */

        /* Similarly for lower bound. */

        /* Let me just directly compute for both cases. */

        /* I'll compute y_lo and y_hi precisely. */

        /* Upper bound (largest y with f(y) < R): */
        if (gy >= 0) {
            /* Try outer region y >= gy: 5y + 2gy < R */
            long long ub_outer = -1; /* invalid marker */
            if (R - 2 * gy > 0) {
                ub_outer = (R - 2 * gy - 1) / 5;
                if (R - 2*gy - 1 < 0) ub_outer = (R - 2*gy - 1 - 4) / 5;
            }
            if (ub_outer >= gy) {
                y_hi = ub_outer;
            } else {
                /* Upper bound in middle region 0 <= y < gy: 9y - 2gy < R => y < (R+2gy)/9 */
                long long num2 = R + 2 * gy - 1;
                long long ub_mid;
                if (num2 >= 0) ub_mid = num2 / 9;
                else ub_mid = (num2 - 8) / 9;
                if (ub_mid >= gy) ub_mid = gy - 1;
                if (ub_mid >= 0) y_hi = ub_mid;
                else y_hi = -1; /* no positive y */
            }
        } else {
            /* gy < 0, y >= 0 region: 5y + 2gy < R => y < (R - 2gy)/5 */
            long long num2 = R - 2 * gy - 1;
            if (num2 >= 0) y_hi = num2 / 5;
            else y_hi = -1;
        }

        /* Lower bound (smallest y with f(y) < R): */
        if (gy <= 0) {
            /* Try outer region y <= gy: -5y - 2gy < R => y > -(R + 2gy)/5 */
            long long lb_outer_num = -(R + 2 * gy);
            long long lb_outer;
            {
                /* smallest integer > lb_outer_num / 5 */
                if (lb_outer_num % 5 == 0) lb_outer = lb_outer_num / 5 + 1;
                else {
                    if (lb_outer_num > 0) lb_outer = lb_outer_num / 5 + 1;
                    else {
                        long long rem = lb_outer_num % 5;
                        if (rem < 0) rem += 5;
                        if (rem == 0) lb_outer = lb_outer_num / 5 + 1;
                        else lb_outer = (lb_outer_num - rem) / 5 + 1;
                    }
                }
            }
            if (lb_outer <= gy) {
                y_lo = lb_outer;
            } else {
                /* Middle region gy < y < 0: -9y + 2gy < R => -9y < R - 2gy => y > -(R-2gy)/9 */
                long long lb_mid_num = -(R - 2 * gy);
                long long lb_mid;
                {
                    if (lb_mid_num % 9 == 0) lb_mid = lb_mid_num / 9 + 1;
                    else {
                        if (lb_mid_num > 0) lb_mid = lb_mid_num / 9 + 1;
                        else {
                            long long rem = lb_mid_num % 9;
                            if (rem < 0) rem += 9;
                            if (rem == 0) lb_mid = lb_mid_num / 9 + 1;
                            else lb_mid = (lb_mid_num - rem) / 9 + 1;
                        }
                    }
                }
                if (lb_mid < gy) lb_mid = gy + 1;
                if (lb_mid < 0) y_lo = lb_mid;
                else y_lo = 0; /* effectively no negative y */
            }
        } else {
            /* gy > 0, y < 0 region: -5y - 2gy < R => y > -(R+2gy)/5 */
            long long lb_num = -(R + 2 * gy);
            long long lb;
            {
                if (lb_num % 5 == 0) lb = lb_num / 5 + 1;
                else {
                    if (lb_num > 0) lb = lb_num / 5 + 1;
                    else {
                        long long rem = lb_num % 5;
                        if (rem < 0) rem += 5;
                        if (rem == 0) lb = lb_num / 5 + 1;
                        else lb = (lb_num - rem) / 5 + 1;
                    }
                }
            }
            if (lb < 0) y_lo = lb;
            else y_lo = 0;
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
