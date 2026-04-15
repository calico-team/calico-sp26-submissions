#include "bits/stdc++.h"

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        long long P;
        int A, B;
        if (!(cin >> P >> A >> B)) break;

        vector<int> decisions;
        long long currentP = P;

        for (int i = 0; i < B; ++i) {
            decisions.push_back((int)(currentP % 3));
            currentP /= 3;
        }
        for (int i = 0; i < A; ++i) {
            decisions.push_back((int)(currentP % 2));
            currentP /= 2;
        }

        bool final_collect = (currentP == 1);

        reverse(decisions.begin(), decisions.end());

        int num_stages = A + B;
        int N = 3;
        int M = 1 + num_stages * 2 + 1;
        vector<string> grid(N, string(M, '.'));

        grid[0][0] = 'v';
        grid[1][0] = '>';

        int col = 1;
        for (int i = 0; i < num_stages; ++i) {
            grid[1][col] = 'S';


            if (i < A) {
                grid[0][col] = (decisions[i] >= 1 ? '^' : 'X');
                grid[2][col] = '.';
            } else {
                grid[0][col] = (decisions[i] >= 1 ? '^' : 'X');
                grid[2][col] = (decisions[i] >= 2 ? 'v' : 'X');
            }

            grid[1][col + 1] = '>';
            col += 2;
        }

        grid[1][col - 1] = (final_collect ? '>' : 'X');

        cout << N << " " << M << "\n";
        for (int i = 0; i < N; ++i) {
            cout << grid[i] << "\n";
        }
    }

    return 0;
}

