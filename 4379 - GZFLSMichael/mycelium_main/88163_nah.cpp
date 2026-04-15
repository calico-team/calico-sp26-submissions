#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int xg, yg, xm, ym;
        cin >> xg >> yg >> xm >> ym;
        const int OFFSET = 100;
        bool grass[201][201] = {false};
        bool mycelium[201][201] = {false};
        grass[xg + OFFSET][yg + OFFSET] = true;
        mycelium[xm + OFFSET][ym + OFFSET] = true;
        int total = 1;

        for (int tick = 1; tick <= 1000; ++tick) {
            if (tick % 2 == 0) {
                int new_grass_x[10000], new_grass_y[10000];
                int new_cnt = 0;
                for (int i = 0; i < 201; ++i) {
                    for (int j = 0; j < 201; ++j) {
                        if (grass[i][j]) {
                            int dx[] = {1, -1, 0, 0};
                            int dy[] = {0, 0, 1, -1};
                            for (int d = 0; d < 4; ++d) {
                                int ni = i + dx[d];
                                int nj = j + dy[d];
                                if (ni >= 0 && ni < 201 && nj >= 0 && nj < 201) {
                                    if (!grass[ni][nj] && !mycelium[ni][nj]) {
                                        new_grass_x[new_cnt] = ni;
                                        new_grass_y[new_cnt] = nj;
                                        ++new_cnt;
                                    }
                                }
                            }
                        }
                    }
                }
                for (int k = 0; k < new_cnt; ++k) {
                    grass[new_grass_x[k]][new_grass_y[k]] = true;
                }
            }
            if (tick % 7 == 0) {
                int new_myc_x[10000], new_myc_y[10000];
                int new_cnt = 0;
                for (int i = 0; i < 201; ++i) {
                    for (int j = 0; j < 201; ++j) {
                        if (mycelium[i][j]) {
                            int dx[] = {1, -1, 0, 0};
                            int dy[] = {0, 0, 1, -1};
                            for (int d = 0; d < 4; ++d) {
                                int ni = i + dx[d];
                                int nj = j + dy[d];
                                if (ni >= 0 && ni < 201 && nj >= 0 && nj < 201) {
                                    if (!grass[ni][nj] && !mycelium[ni][nj]) {
                                        new_myc_x[new_cnt] = ni;
                                        new_myc_y[new_cnt] = nj;
                                        ++new_cnt;
                                    }
                                }
                            }
                        }
                    }
                }
                for (int k = 0; k < new_cnt; k++) {
                    int ni = new_myc_x[k], nj = new_myc_y[k];
                    if (!grass[ni][nj]) {
                        mycelium[ni][nj] = true;
                        total++;
                    }
                }
            }
        }
        cout << total << '\n';
    }
    return 0;
}