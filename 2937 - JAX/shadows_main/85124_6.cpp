#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
using namespace std;
const int maxn = 1e3 + 1;
int T, N;
bool shape[maxn][maxn][maxn]; // [x][y][z] (z is downward)
uint16_t ycnt[maxn][maxn];    // [x][z]
uint16_t xcnt[maxn][maxn];    // [y][z]
int main() {
    // freopen("6.out", "w", stdout);
    cin >> T;
    while (T--) {
        cin >> N;
        memset(shape, 1, sizeof(shape));
        char c;
        getchar();
        // for (int i = 1; i <= N; i++) {
        //     cout << endl
        //          << endl;
        //     for (int j = 1; j <= N; j++) {
        //         for (int k = 1; k <= N; k++) {
        //             cout << (shape[i][j][k] ? "#" : ".");
        //         }
        //         cout << endl;
        //     }
        // }
        // cout << "================\n";

        // looking in y dir
        for (int i = 1; i <= N; i++) {     // z
            for (int j = 1; j <= N; j++) { // x
                c = getchar();
                if (c == '.')                      // air
                    for (int k = 1; k <= N; k++) { // y
                        shape[j][k][i] = 0;
                    }
            }
            c = getchar();
        }

        // looking in x dir
        for (int i = 1; i <= N; i++) {     // z
            for (int j = 1; j <= N; j++) { // y
                c = getchar();
                if (c == '.')                      // air
                    for (int k = 1; k <= N; k++) { // x
                        shape[k][j][i] = 0;
                    }
            }
            c = getchar();
        }

        // for (int i = 1; i <= N; i++) {
        //     cout << endl
        //          << endl;
        //     for (int j = 1; j <= N; j++) { // z
        //         for (int k = 1; k <= N; k++) {
        //             cout << (shape[i][k][j] ? "#" : ".");
        //         }
        //         cout << endl;
        //     }
        // }

        memset(ycnt, 0, sizeof(ycnt));
        memset(xcnt, 0, sizeof(xcnt));
        int sumcnt = 0;
        int maxminus = 0;

        // looking in y dir
        for (int i = 1; i <= N; i++) {         // z
            for (int j = 1; j <= N; j++) {     // x
                for (int k = 1; k <= N; k++) { // y
                    ycnt[j][i] += shape[j][k][i];
                }
                sumcnt += ycnt[j][i];
            }
        }

        // looking in x dir
        for (int i = 1; i <= N; i++) {         // z
            for (int j = 1; j <= N; j++) {     // y
                for (int k = 1; k <= N; k++) { // x
                    xcnt[j][i] += shape[k][j][i];
                }
            }
        }

        for (int i = 1; i <= N; i++) {     // x
            for (int j = 1; j <= N; j++) { // z
                if (ycnt[i][j] > 1) {
                    for (int k = 1; k <= N; k++) { // y
                        if (xcnt[k][j] > 1) {
                            xcnt[k][j]--;
                            ycnt[i][j]--;
                            maxminus++;
                        }
                        if (ycnt[i][j] <= 1)
                            break;
                    }
                }
            }
        }

        for (int i = 1; i <= N; i++) {     // y
            for (int j = 1; j <= N; j++) { // z
                if (xcnt[i][j] > 1) {
                    for (int k = 1; k <= N; k++) { // x
                        if (ycnt[k][j] > 1) {
                            ycnt[k][j]--;
                            xcnt[i][j]--;
                            maxminus++;
                        }
                        if (xcnt[i][j] <= 1)
                            break;
                    }
                }
            }
        }

        cout << sumcnt << ' ' << sumcnt - maxminus << endl;
    }
}