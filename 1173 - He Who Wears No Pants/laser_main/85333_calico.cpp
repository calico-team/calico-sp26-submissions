#include <bits/stdc++.h>
using namespace std;

int onedist(int x0, int y0, int p, int q, int n, int m, int x, int y) {
    int c = 1;
    int x1 = x0 + p; x1 %= n;
    int y1 = y0 + q; y1 %= m;
    while (x1 != x || y1 != y)  {
        // printf("%d %d\n", x1, y1);
        if (x1 == x0 && y1 == y0) {
            return 2147483647;
        }
        x1 += p; x1 %= n;
        y1 += q; y1 %= m;
        c++;
    }
    return c;
}

int loopdist(int x0, int y0, int p, int q, int n, int m, int x, int y) {
    int c = 1;
    int x1 = x + p; x1 %= n;
    int y1 = y + q; y1 %= m;
    while (x1 != x || y1 != y)  {
        x1 += p; x1 %= n;
        y1 += q; y1 %= m;
        c++;
    }
    return c;
}

int main() {
    int t, k, n, m, p, q, x, y, x0, y0, answer;
    scanf("%d", &t);

    while (t--) {
        scanf("%d %d %d %d %d", &k, &n, &m, &q, &p);

        answer = 0;

        scanf("%d %d", &x, &y);
        x0 = x;
        y0 = y;

        int mindist = loopdist(x0, y0, p, q, n, m, x, y);

        for (int i = 1; i < k; i++) {
            // cout << "ready: ";
            scanf("%d %d", &x, &y);

            int adjsisadj = onedist(x0, y0, p, q, n, m, x, y);
            // cout << "dist: " << adjsisadj << endl;
            if (adjsisadj < mindist) {
                mindist = adjsisadj;
                answer = i;
            }

        }
        printf("%d\n", answer);
    }
}