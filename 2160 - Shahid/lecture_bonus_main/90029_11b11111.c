#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NM 1000
#define MAX_UV 2005   // N+M can be up to 2000
#define MAX_AURA 1005

typedef struct {
    int r, c, u, v, aura;
} Point;

// Fenwick tree over aura values (0..MAX_AURA)
typedef struct {
    int cnt[MAX_AURA + 2];
    long long sum[MAX_AURA + 2];
} BIT;

void bit_add(BIT *bit, int idx, int delta_cnt, long long delta_sum) {
    idx++; // 1-indexed
    while (idx <= MAX_AURA + 1) {
        bit->cnt[idx] += delta_cnt;
        bit->sum[idx] += delta_sum;
        idx += idx & -idx;
    }
}

int bit_prefix_cnt(BIT *bit, int idx) {
    if (idx < 0) return 0;
    idx++;
    int res = 0;
    while (idx > 0) {
        res += bit->cnt[idx];
        idx -= idx & -idx;
    }
    return res;
}

long long bit_prefix_sum(BIT *bit, int idx) {
    if (idx < 0) return 0;
    idx++;
    long long res = 0;
    while (idx > 0) {
        res += bit->sum[idx];
        idx -= idx & -idx;
    }
    return res;
}

// Returns sum of the k smallest auras in the multiset represented by BIT
long long sum_k_smallest(BIT *bit, int k) {
    if (k <= 0) return 0;
    // binary search on aura value
    int lo = 0, hi = MAX_AURA;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (bit_prefix_cnt(bit, mid) >= k)
            hi = mid;
        else
            lo = mid + 1;
    }
    int threshold = lo;
    int cnt_less = bit_prefix_cnt(bit, threshold - 1);
    long long sum_less = bit_prefix_sum(bit, threshold - 1);
    int need = k - cnt_less;
    return sum_less + (long long)need * threshold;
}

// ----------------------------------------------------------------------

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int N, M, K;
        scanf("%d %d %d", &N, &M, &K);
        char **grid = malloc(N * sizeof(char*));
        for (int i = 0; i < N; i++) {
            grid[i] = malloc((M + 1) * sizeof(char));
            scanf("%s", grid[i]);
        }

        // count occupied per row
        int *row_occ = calloc(N, sizeof(int));
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < M; c++) {
                if (grid[r][c] == '#') row_occ[r]++;
            }
        }

        // collect all free seats
        int total_points = 0;
        Point *points = malloc(N * M * sizeof(Point));
        int offset = M - 1;
        for (int r = 0; r < N; r++) {
            int left = 0;
            for (int c = 0; c < M; c++) {
                if (grid[r][c] == '-') {
                    int right = row_occ[r] - left;
                    int aura = left < right ? left : right;
                    int u = r + c;
                    int v = r - c + offset;
                    points[total_points++] = (Point){r, c, u, v, aura};
                } else {
                    left++;
                }
            }
        }

        free(row_occ);
        for (int i = 0; i < N; i++) free(grid[i]);
        free(grid);

        if (total_points == 0) continue; // should not happen

        // find max u and v
        int Umax = 0, Vmax = 0;
        for (int i = 0; i < total_points; i++) {
            if (points[i].u > Umax) Umax = points[i].u;
            if (points[i].v > Vmax) Vmax = points[i].v;
        }
        int U = Umax + 1;
        int V = Vmax + 1;

        // build count grid and aura grid
        int **cnt = malloc(U * sizeof(int*));
        int **aura_grid = malloc(U * sizeof(int*));
        for (int i = 0; i < U; i++) {
            cnt[i] = calloc(V, sizeof(int));
            aura_grid[i] = malloc(V * sizeof(int));
            for (int j = 0; j < V; j++) aura_grid[i][j] = -1;
        }
        for (int i = 0; i < total_points; i++) {
            int u = points[i].u, v = points[i].v;
            cnt[u][v] = 1;
            aura_grid[u][v] = points[i].aura;
        }

        // prefix sum for counts
        int **pre = malloc((U + 1) * sizeof(int*));
        for (int i = 0; i <= U; i++) {
            pre[i] = calloc(V + 1, sizeof(int));
        }
        for (int i = 0; i < U; i++) {
            int row_sum = 0;
            for (int j = 0; j < V; j++) {
                row_sum += cnt[i][j];
                pre[i+1][j+1] = pre[i][j+1] + row_sum;
            }
        }

        // binary search minimal side length L
        int L = 0;
        int lo = 0, hi = (U > V ? U : V);
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            bool ok = false;
            if (mid <= U && mid <= V) {
                for (int i = 0; i <= U - mid; i++) {
                    for (int j = 0; j <= V - mid; j++) {
                        int total = pre[i+mid][j+mid] - pre[i][j+mid] - pre[i+mid][j] + pre[i][j];
                        if (total >= K) {
                            ok = true;
                            break;
                        }
                    }
                    if (ok) break;
                }
            }
            if (ok) hi = mid;
            else lo = mid + 1;
        }
        L = lo;

        // special case L == 0: just pick the point with smallest aura
        if (L == 0) {
            int best_idx = 0;
            for (int i = 1; i < total_points; i++) {
                if (points[i].aura < points[best_idx].aura)
                    best_idx = i;
            }
            printf("%d %d\n", points[best_idx].r, points[best_idx].c);
            // free memory and continue to next test case
            for (int i = 0; i < U; i++) {
                free(cnt[i]);
                free(aura_grid[i]);
                free(pre[i]);
            }
            free(cnt); free(aura_grid); free(pre);
            free(points);
            continue;
        }

        // group points by u
        int *pts_per_u = calloc(U, sizeof(int));
        for (int i = 0; i < total_points; i++) {
            pts_per_u[points[i].u]++;
        }
        // points_by_u[u] is an array of Point (not pointers)
        Point **points_by_u = malloc(U * sizeof(Point*));
        for (int u = 0; u < U; u++) {
            points_by_u[u] = malloc(pts_per_u[u] * sizeof(Point));
        }
        int *ptr_by_u = calloc(U, sizeof(int));
        for (int i = 0; i < total_points; i++) {
            int u = points[i].u;
            points_by_u[u][ptr_by_u[u]++] = points[i];
        }
        free(ptr_by_u);

        // frequency per v and aura (for current u-window)
        int **freq = malloc(V * sizeof(int*));
        for (int v = 0; v < V; v++) {
            freq[v] = calloc(MAX_AURA + 1, sizeof(int));
        }

        BIT bit;
        memset(&bit, 0, sizeof(bit));

        long long best_sum = -1;
        int best_u0 = -1, best_v0 = -1;

        // slide u0
        for (int u0 = 0; u0 <= U - L; u0++) {
            // update freq for rows that enter/leave
            if (u0 == 0) {
                // add rows 0 .. L-1
                for (int u = 0; u < L; u++) {
                    for (int p = 0; p < pts_per_u[u]; p++) {
                        Point pt = points_by_u[u][p];
                        freq[pt.v][pt.aura]++;
                    }
                }
            } else {
                // remove row u0-1, add row u0+L-1
                int u_rem = u0 - 1;
                for (int p = 0; p < pts_per_u[u_rem]; p++) {
                    Point pt = points_by_u[u_rem][p];
                    freq[pt.v][pt.aura]--;
                }
                int u_add = u0 + L - 1;
                for (int p = 0; p < pts_per_u[u_add]; p++) {
                    Point pt = points_by_u[u_add][p];
                    freq[pt.v][pt.aura]++;
                }
            }

            // slide v0
            // clear BIT
            memset(&bit, 0, sizeof(bit));
            for (int v0 = 0; v0 <= V - L; v0++) {
                if (v0 == 0) {
                    // add v in [0, L-1]
                    for (int v = 0; v < L; v++) {
                        for (int a = 0; a <= MAX_AURA; a++) {
                            int f = freq[v][a];
                            if (f) bit_add(&bit, a, f, (long long)f * a);
                        }
                    }
                } else {
                    // remove v0-1, add v0+L-1
                    int v_rem = v0 - 1;
                    for (int a = 0; a <= MAX_AURA; a++) {
                        int f = freq[v_rem][a];
                        if (f) bit_add(&bit, a, -f, -(long long)f * a);
                    }
                    int v_add = v0 + L - 1;
                    for (int a = 0; a <= MAX_AURA; a++) {
                        int f = freq[v_add][a];
                        if (f) bit_add(&bit, a, f, (long long)f * a);
                    }
                }
                int total_cnt = bit_prefix_cnt(&bit, MAX_AURA);
                if (total_cnt >= K) {
                    long long s = sum_k_smallest(&bit, K);
                    if (best_sum == -1 || s < best_sum) {
                        best_sum = s;
                        best_u0 = u0;
                        best_v0 = v0;
                    }
                }
            }
        }

        // Now extract the K smallest auras from the best square
        // Collect all points in that square
        Point **candidates = malloc(total_points * sizeof(Point*));
        int cand_cnt = 0;
        for (int u = best_u0; u < best_u0 + L; u++) {
            for (int p = 0; p < pts_per_u[u]; p++) {
                Point *pt = &points_by_u[u][p];
                if (pt->v >= best_v0 && pt->v < best_v0 + L) {
                    candidates[cand_cnt++] = pt;
                }
            }
        }
        // sort candidates by aura (simple selection sort for clarity)
        for (int i = 0; i < cand_cnt; i++) {
            for (int j = i+1; j < cand_cnt; j++) {
                if (candidates[i]->aura > candidates[j]->aura) {
                    Point *tmp = candidates[i];
                    candidates[i] = candidates[j];
                    candidates[j] = tmp;
                }
            }
        }
        for (int i = 0; i < K; i++) {
            printf("%d %d\n", candidates[i]->r, candidates[i]->c);
        }

        // free memory
        for (int i = 0; i < U; i++) {
            free(cnt[i]);
            free(aura_grid[i]);
            free(pre[i]);
            free(points_by_u[i]);
        }
        free(cnt); free(aura_grid); free(pre); free(points_by_u);
        free(pts_per_u);
        for (int v = 0; v < V; v++) free(freq[v]);
        free(freq);
        free(candidates);
        free(points);
    }
    return 0;
}