#include <stdio.h>
#include <string.h>

void read_your_input() {
    int T;
    scanf("%d", &T);
    while (T--) {
        long long P, A, B;
        scanf("%lld %lld %lld", &P, &A, &B);

        int total_factors = (int)(A + B);
        int M = 2 * total_factors + 2;
        int N = 3;

        char g[3][205];
        for (int r = 0; r < 3; r++)
            for (int c = 0; c < M; c++)
                g[r][c] = '.';

        g[1][0] = '>';

        long long cur_p = P;
        long long cur_a = A, cur_b = B;
        int col = 1;

        for (int i = 0; i < total_factors; i++) {
            int f;
            if (cur_a > 0) { f = 2; cur_a--; }
            else            { f = 3; cur_b--; }

            long long Dprime = 1;
            for (int j = 0; j < cur_a; j++) Dprime *= 2;
            for (int j = 0; j < cur_b; j++) Dprime *= 3;

            int k = (int)(cur_p / Dprime);
            cur_p = cur_p - (long long)k * Dprime;

            g[1][col] = 'S';

            if (f == 2) {
                g[0][col] = (k == 0) ? 'X' : '^';
                g[2][col] = '.';
            } else {
                if (k == 0) {
                    g[0][col] = 'X';
                    g[2][col] = 'X';
                } else if (k == 1) {
                    g[0][col] = '^';
                    g[2][col] = 'X';
                } else {
                    g[0][col] = '^';
                    g[2][col] = 'v';
                }
            }

            g[1][col + 1] = '>';
            col += 2;
        }

        g[1][col] = 'X';

        printf("%d %d\n", N, M);
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < M; c++)
                printf("%c", g[r][c]);
            printf("\n");
        }
    }
}

int main() {
    read_your_input();
    return 0;
}