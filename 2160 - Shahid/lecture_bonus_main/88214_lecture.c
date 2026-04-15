/*
 * Problem 11: Average CS186 Class Experience (Main + Bonus)
 * CALICO Spring '26
 *
 * Algorithm:
 *   1. Rotate (r,c) -> (u = r+c, v = r-c+(M-1)).
 *      Manhattan distance |dr|+|dc| becomes Chebyshev max(|du|,|dv|).
 *      Finding K seats with min max-pairwise Manhattan distance = finding
 *      K seats fitting in a D×D box in (u,v) space, minimizing D.
 *
 *   2. Build 2D prefix sums of available seat counts in (u,v) space.
 *
 *   3. Binary search on D. For each candidate D, check all (D+1)×(D+1)
 *      windows in (u,v) space for one containing >= K available seats.
 *      Time: O(sz^2 * log(sz)) where sz = N+M-1.
 *
 *   4. Bonus: For each u-window [u1, u1+D], sweep v1 with a sliding
 *      window, maintaining an aura-value histogram of active seats.
 *      When window has >= K seats, compute sum of K smallest aura
 *      values from the histogram in O(max_aura) time.
 *      Track the global minimum K-smallest-aura-sum across all windows.
 *
 *   5. Output K seats with smallest aura from the optimal window.
 *
 * Aura loss of a seat = min(#occupied strictly left, #occupied strictly right)
 * in the same row.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN    1001
#define MAXUV   2001
#define MAXAURA 501

static int N, M, K;
static char grid[MAXN][MAXN + 1];
static short seat_aura[MAXUV][MAXUV]; /* -1 = no seat, >= 0 = aura value */
static int SZ; /* N + M - 1 */

/* 2D prefix sums for seat count */
static int ps[MAXUV + 1][MAXUV + 1];

static void build_ps(void) {
    for (int u = 0; u <= SZ; u++) ps[u][0] = 0;
    for (int v = 0; v <= SZ; v++) ps[0][v] = 0;
    for (int u = 0; u < SZ; u++)
        for (int v = 0; v < SZ; v++)
            ps[u+1][v+1] = (seat_aura[u][v] >= 0) + ps[u][v+1] + ps[u+1][v] - ps[u][v];
}

static inline int qcnt(int u1, int v1, int u2, int v2) {
    return ps[u2+1][v2+1] - ps[u1][v2+1] - ps[u2+1][v1] + ps[u1][v1];
}

static int check_feasible(int D) {
    for (int u1 = 0; u1 < SZ; u1++) {
        int u2 = u1 + D; if (u2 >= SZ) u2 = SZ - 1;
        for (int v1 = 0; v1 < SZ; v1++) {
            int v2 = v1 + D; if (v2 >= SZ) v2 = SZ - 1;
            if (qcnt(u1, v1, u2, v2) >= K) return 1;
        }
    }
    return 0;
}

typedef struct { int r, c, aura; } Seat;

static int cmp_seat(const void *a, const void *b) {
    return ((const Seat *)a)->aura - ((const Seat *)b)->aura;
}

/* Per-column seat lists for efficient sliding window */
typedef struct { int u; short aura; } ColSeat;
static ColSeat col_seats[MAXUV][MAXN];
static int col_cnt[MAXUV];

static void solve(void) {
    scanf("%d %d %d", &N, &M, &K);
    for (int i = 0; i < N; i++) scanf("%s", grid[i]);
    SZ = N + M - 1;

    /* Initialize seat_aura grid to -1 (no seat) */
    for (int u = 0; u < SZ; u++)
        for (int v = 0; v < SZ; v++)
            seat_aura[u][v] = -1;
    for (int v = 0; v < SZ; v++) col_cnt[v] = 0;

    /* Compute aura loss for each available seat, fill rotated grid */
    for (int i = 0; i < N; i++) {
        int left[MAXN], cnt = 0;
        for (int j = 0; j < M; j++) {
            left[j] = cnt;
            if (grid[i][j] == '#') cnt++;
        }
        cnt = 0;
        for (int j = M - 1; j >= 0; j--) {
            if (grid[i][j] == '#') { cnt++; continue; }
            int a = left[j] < cnt ? left[j] : cnt;
            int u = i + j, v = (i - j) + (M - 1);
            seat_aura[u][v] = (short)a;
            col_seats[v][col_cnt[v]].u = u;
            col_seats[v][col_cnt[v]].aura = (short)a;
            col_cnt[v]++;
        }
    }

    build_ps();

    /* Special case: K = 1, just pick min aura seat */
    if (K == 1) {
        int br = -1, bc = -1, ba = 1 << 20;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) {
                int u = i + j, v = (i - j) + (M - 1);
                if (seat_aura[u][v] >= 0 && seat_aura[u][v] < ba) {
                    ba = seat_aura[u][v]; br = i; bc = j;
                }
            }
        printf("%d %d\n", br, bc);
        return;
    }

    /* Binary search on D (optimal max pairwise Manhattan distance) */
    int lo = 0, hi = 2 * (SZ - 1);
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (check_feasible(mid)) hi = mid; else lo = mid + 1;
    }
    int optD = lo;

    /* Bonus: sliding window with aura histogram to find the window
     * minimizing sum of K smallest aura values */
    long long best_ksum = (long long)2e18;
    int best_u1 = -1, best_v1 = -1;
    int hist[MAXAURA];
    int win_cnt;

    for (int u1 = 0; u1 < SZ; u1++) {
        int u2 = u1 + optD; if (u2 >= SZ) u2 = SZ - 1;

        /* Build initial histogram for v-window [0, min(optD, SZ-1)] */
        memset(hist, 0, sizeof(hist));
        win_cnt = 0;
        int init_v2 = optD < SZ ? optD : SZ - 1;

        for (int v = 0; v <= init_v2; v++) {
            for (int ci = 0; ci < col_cnt[v]; ci++) {
                int su = col_seats[v][ci].u;
                if (su >= u1 && su <= u2) {
                    hist[col_seats[v][ci].aura]++;
                    win_cnt++;
                }
            }
        }

        /* Check initial window */
        if (win_cnt >= K) {
            long long ksum = 0;
            int need = K;
            for (int a = 0; a < MAXAURA && need > 0; a++) {
                int take = hist[a] < need ? hist[a] : need;
                ksum += (long long)a * take;
                need -= take;
            }
            if (ksum < best_ksum) {
                best_ksum = ksum; best_u1 = u1; best_v1 = 0;
            }
        }

        /* Slide v1 from 1 to SZ-1 */
        for (int v1 = 1; v1 < SZ; v1++) {
            /* Remove column (v1 - 1) */
            int rem_v = v1 - 1;
            for (int ci = 0; ci < col_cnt[rem_v]; ci++) {
                int su = col_seats[rem_v][ci].u;
                if (su >= u1 && su <= u2) {
                    hist[col_seats[rem_v][ci].aura]--;
                    win_cnt--;
                }
            }

            /* Add column (v1 + optD) if in range */
            int add_v = v1 + optD;
            if (add_v < SZ) {
                for (int ci = 0; ci < col_cnt[add_v]; ci++) {
                    int su = col_seats[add_v][ci].u;
                    if (su >= u1 && su <= u2) {
                        hist[col_seats[add_v][ci].aura]++;
                        win_cnt++;
                    }
                }
            }

            /* Check this window */
            if (win_cnt >= K) {
                long long ksum = 0;
                int need = K;
                for (int a = 0; a < MAXAURA && need > 0; a++) {
                    int take = hist[a] < need ? hist[a] : need;
                    ksum += (long long)a * take;
                    need -= take;
                }
                if (ksum < best_ksum) {
                    best_ksum = ksum; best_u1 = u1; best_v1 = v1;
                }
            }
        }
    }

    /* Collect seats in the optimal window, sort by aura, output K smallest */
    {
        int u2 = best_u1 + optD; if (u2 >= SZ) u2 = SZ - 1;
        int v2 = best_v1 + optD; if (v2 >= SZ) v2 = SZ - 1;

        static Seat chosen[MAXN * MAXN];
        int nc = 0;

        for (int u = best_u1; u <= u2; u++)
            for (int v = best_v1; v <= v2; v++) {
                if (seat_aura[u][v] < 0) continue;
                int rpv = u, rmv = v - (M - 1);
                if ((rpv + rmv) & 1) continue;
                int r = (rpv + rmv) / 2, c = (rpv - rmv) / 2;
                if (r < 0 || r >= N || c < 0 || c >= M) continue;
                chosen[nc].r = r;
                chosen[nc].c = c;
                chosen[nc].aura = seat_aura[u][v];
                nc++;
            }

        qsort(chosen, nc, sizeof(Seat), cmp_seat);
        for (int i = 0; i < K; i++)
            printf("%d %d\n", chosen[i].r, chosen[i].c);
    }
}

/* Helper function as specified in the problem */
void read_your_input(void) {
    int T;
    scanf("%d", &T);
    while (T--) solve();
}

/* Variable as specified in the problem */
int johnny_d_lecture;

int main(void) {
    read_your_input();
    return 0;
}
