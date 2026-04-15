#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef long long ll;
typedef __int128 lll;

ll my_gcd(ll a, ll b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    while (b) { ll t = b; b = a % b; a = t; }
    return a;
}

int N, M;
char grid[20][20];
ll memo_num[20][20], memo_den[20][20];
int computed[20][20];

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int dir_of(char c) {
    switch (c) {
        case '^': return 0;
        case 'v': return 1;
        case '<': return 2;
        case '>': return 3;
    }
    return -1;
}

void trace(int r, int c, ll *on, ll *od) {
    if (computed[r][c]) {
        *on = memo_num[r][c];
        *od = memo_den[r][c];
        return;
    }
    computed[r][c] = 1;
    char tile = grid[r][c];

    if (tile == 'X' || tile == '.') {
        *on = 0; *od = 1;
        memo_num[r][c] = 0; memo_den[r][c] = 1;
        return;
    }

    int d = dir_of(tile);
    if (d >= 0) {
        int nr = r + dr[d], nc = c + dc[d];
        if (nr < 0 || nr >= N || nc < 0 || nc >= M) {
            *on = 1; *od = 1;
        } else {
            trace(nr, nc, on, od);
        }
        memo_num[r][c] = *on; memo_den[r][c] = *od;
        return;
    }

    if (tile == 'S') {
        int valid[4], nv = 0;
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i], nc = c + dc[i];
            if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
            char adj = grid[nr][nc];
            if (adj == 'X') {
                valid[nv++] = i;
            } else {
                int ad = dir_of(adj);
                if (ad >= 0) {
                    int br = nr + dr[ad], bc = nc + dc[ad];
                    if (!(br == r && bc == c)) {
                        valid[nv++] = i;
                    }
                }
            }
        }

        ll sum_n = 0, sum_d = 1;
        for (int i = 0; i < nv; i++) {
            int nr = r + dr[valid[i]], nc = c + dc[valid[i]];
            ll tn, td;
            trace(nr, nc, &tn, &td);
            if (tn == 0) continue;
            if (sum_n == 0) { sum_n = tn; sum_d = td; continue; }
            ll g = my_gcd(sum_d, td);
            ll la = td / g, lb = sum_d / g;
            lll nn = (lll)sum_n * la + (lll)tn * lb;
            lll nd = (lll)sum_d * la;
            lll ga = nn < 0 ? -nn : nn, gb = nd;
            while (gb) { lll t = gb; gb = ga % gb; ga = t; }
            if (ga > 0) { nn /= ga; nd /= ga; }
            sum_n = (ll)nn; sum_d = (ll)nd;
        }

        if (nv > 0 && sum_n > 0) {
            ll g = my_gcd(sum_n, (ll)nv);
            sum_n /= g;
            sum_d *= ((ll)nv / g);
        }

        *on = sum_n; *od = sum_d;
        memo_num[r][c] = sum_n; memo_den[r][c] = sum_d;
        return;
    }

    *on = 0; *od = 1;
    memo_num[r][c] = 0; memo_den[r][c] = 1;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &N, &M);
        for (int i = 0; i < N; i++) scanf("%s", grid[i]);
        memset(computed, 0, sizeof(computed));

        ll k, q;
        trace(0, 0, &k, &q);

        if (k == 0) {
            printf("0 1\n");
        } else {
            ll g = my_gcd(k, q);
            printf("%lld %lld\n", k / g, q / g);
        }
    }
    return 0;
}
