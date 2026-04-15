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
// [x][y][z] (z is downward)
bool xview[maxn][maxn]; // [y][z]
bool yview[maxn][maxn]; // [x][z]
int ny[maxn], nx[maxn]; // [z], # of zeros in yview/xview layer
int main() {
    // freopen("6.out", "w", stdout);
    cin >> T;
    while (T--) {
        memset(ny, 0, sizeof(ny));
        memset(nx, 0, sizeof(nx));
        cin >> N;
        char c;
        getchar();

        // looking in y dir
        for (int i = 1; i <= N; i++) {     // z
            for (int j = 1; j <= N; j++) { // x
                c = getchar();
                yview[j][i] = (c == '#');
                ny[i] += (!yview[j][i]);
            }
            c = getchar();
        }

        // looking in x dir
        for (int i = 1; i <= N; i++) {     // z
            for (int j = 1; j <= N; j++) { // y
                c = getchar();
                xview[j][i] = (c == '#');
                nx[i] += (!xview[j][i]);
            }
            c = getchar();
        }

        int numair = 0, numblk = 0;

        for (int z = 1; z <= N; z++) {
            numair += nx[z] * N + ny[z] * (N - nx[z]);
            numblk += max(N - nx[z], N - ny[z]);
        }

        cout << N * N * N - numair << ' ' << numblk << endl;
    }
}