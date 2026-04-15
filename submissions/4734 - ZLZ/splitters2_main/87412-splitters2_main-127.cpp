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

        // ��ĸ
        long long denom = 1;
        for (int i = 0; i < A; i++) denom *= 2;
        for (int i = 0; i < B; i++) denom *= 3;

        // ������С������ = A+B+2������ = denom+2
        int N = A + B + 2;
        int M = (int)denom + 2;
        if (N > MAXN) N = MAXN;
        if (M > MAXN) M = MAXN;

        // ��ʼ��
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                grid[i][j] = '.';

        // ���
        grid[0][0] = 's';

        // ÿ���һ�� splitter
        for (int i = 1; i <= A + B; i++) {
            grid[i][0] = 's';
        }

        // ���һ�г���
        for (int j = 0; j < denom; j++) {
            if (j < P) grid[N-1][j] = '>';
            else grid[N-1][j] = 'x';
        }

        // ���
        cout << N << " " << M << "\n";
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) cout << grid[i][j];
            cout << "\n";
        }
    }
    return 0;
}
