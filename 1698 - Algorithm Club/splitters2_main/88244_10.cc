#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Rem {
    int val, div;
};

char grid[2005][10];
Rem rems[105];
int n, m, r_idx;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        ll P;
        int A, B;
        cin >> P >> A >> B;

        int rem_cnt = 0;
        ll curr = P;

        for (int i = 0; i < A; ++i) {
            rems[rem_cnt++] = {(int)(curr % 2), 2};
            curr /= 2;
        }
        for (int i = 0; i < B; ++i) {
            rems[rem_cnt++] = {(int)(curr % 3), 3};
            curr /= 3;
        }
        int final_bit = (int)curr;

        reverse(rems, rems + rem_cnt);

        for (int i = 0; i < 2005; ++i) {
            for (int j = 0; j < 5; ++j) grid[i][j] = '.';
            grid[i][5] = '\0';
        }

        m = 5;
        grid[0][0] = '>';
        grid[0][1] = '>';
        grid[0][2] = 'v';
        grid[1][2] = 'v';

        r_idx = 2;
        for (int i = 0; i < rem_cnt; ++i) {
            int rem = rems[i].val;
            int div = rems[i].div;

            grid[r_idx][2] = 'S';

            if (rem >= 1) {
                grid[r_idx][1] = '<';
                grid[r_idx][0] = '<';
            } else {
                grid[r_idx][1] = 'X';
            }

            if (div == 3) {
                if (rem == 2) {
                    grid[r_idx][3] = '>';
                    grid[r_idx][4] = '>';
                } else {
                    grid[r_idx][3] = 'X';
                }
            }

            grid[r_idx + 1][2] = 'v';
            grid[r_idx + 2][2] = 'v';
            r_idx += 3;
        }

        if (final_bit == 0) {
            grid[r_idx - 1][2] = 'X';
        } else {
            grid[r_idx - 1][2] = 'v';
        }

        n = r_idx;
        cout << n << " " << m << "\n";
        for (int i = 0; i < n; ++i) {
            cout << grid[i] << "\n";
        }
    }

    return 0;
}