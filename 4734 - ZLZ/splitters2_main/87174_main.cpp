#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 2100;
char grid[MAXN][MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        long long P;
        int A, B;
        cin >> P >> A >> B;

        int denom = 1;
        for (int i = 0; i < A; i++) denom *= 2;
        for (int i = 0; i < B; i++) denom *= 3;

        int N = 1, M = denom + 2;
        cout << N << " " << M << "\n";

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) grid[i][j] = '.';
        }

        grid[0][0] = 's';


        for (int i = 1; i <= denom; i++) {
            if (i <= P) grid[0][i] = '>';
            else grid[0][i] = 'x';
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) cout << grid[i][j];
            cout << "\n";
        }
    }
    return 0;
}
