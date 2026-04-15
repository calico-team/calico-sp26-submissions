#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int xg, yg, xm, ym;
        cin >> xg >> yg >> xm >> ym;
        const int OFFSET = 500;
        const int SIZE = 1001;
        int distG[SIZE][SIZE];
        int distM[SIZE][SIZE];
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                distG[i][j] = distM[i][j] = 1e9;
            }
        }
        int sxg = xg + OFFSET, syg = yg + OFFSET;
        int sxm = xm + OFFSET, sym = ym + OFFSET;
        distG[sxg][syg] = 0;
        distM[sxm][sym] = 0;
        int qgx[100000], qgy[100000];
        int headG = 0, tailG = 0;
        qgx[tailG] = sxg; qgy[tailG] = syg; ++tailG;
        while (headG < tailG) {
            int x = qgx[headG], y = qgy[headG]; ++headG;
            int d = distG[x][y];
            int nd = d + 2;
            int dx[] = {1, -1, 0, 0};
            int dy[] = {0, 0, 1, -1};
            for (int k = 0; k < 4; ++k) {
                int nx = x + dx[k], ny = y + dy[k];
                if (nx >= 0 && nx < SIZE && ny >= 0 && ny < SIZE) {
                    if (distG[nx][ny] > nd) {
                        distG[nx][ny] = nd;
                        qgx[tailG] = nx; qgy[tailG] = ny; ++tailG;
                    }
                }
            }
        }
        int qmx[100000], qmy[100000];
        int headM = 0, tailM = 0;
        qmx[tailM] = sxm; qmy[tailM] = sym; ++tailM;
        while (headM < tailM) {
            int x = qmx[headM], y = qmy[headM]; ++headM;
            int d = distM[x][y];
            int nd = d + 7;
            int dx[] = {1, -1, 0, 0};
            int dy[] = {0, 0, 1, -1};
            for (int k = 0; k < 4; ++k) {
                int nx = x + dx[k], ny = y + dy[k];
                if (nx >= 0 && nx < SIZE && ny >= 0 && ny < SIZE) {
                    if (distM[nx][ny] > nd) {
                        distM[nx][ny] = nd;
                        qmx[tailM] = nx; qmy[tailM] = ny; ++tailM;
                    }
                }
            }
        }
        int total = 0;
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                if (distM[i][j] < 1e9 && distM[i][j] < distG[i][j]) {
                    ++total;
                }
            }
        }
        cout << total << '\n';
    }
    return 0;
}