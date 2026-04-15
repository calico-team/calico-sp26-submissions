#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> build_factory(long long P, int A, int B) {
    int rows = 3;
    int cols = 2 * (A + B) + 10;
    vector<string> grid(rows, string(cols, '.'));

    grid[0][0] = '>';
    int cur_c = 1;

    for (int i = 0; i < A; ++i) {
        grid[1][cur_c] = 'S';
        grid[0][cur_c] = 'v';
        grid[2][cur_c] = 'v';
        grid[1][cur_c + 1] = '>';
        cur_c += 2;
    }

    for (int i = 0; i < B; ++i) {
        grid[1][cur_c] = 'S';
        grid[0][cur_c] = 'v';
        grid[0][cur_c + 1] = '>';
        grid[2][cur_c] = 'v';
        grid[1][cur_c + 1] = '>';
        cur_c += 2;
    }

    long long collected = 0;
    for (int c = 0; c < cols; ++c) {
        if (grid[0][c] == '>' || grid[0][c] == 'v') {
            if (collected < P) {
                grid[0][c] = '^';
                collected++;
            } else {
                grid[0][c] = 'X';
            }
        }
        if (grid[2][c] == 'v') {
            if (collected < P) {
                collected++;
            } else {
                grid[2][c] = 'X';
            }
        }
    }

    return grid;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        long long P;
        int A, B;
        cin >> P >> A >> B;
        vector<string> factory = build_factory(P, A, B);
        cout << factory.size() << " " << factory[0].size() << endl;
        for (int i = 0; i < factory.size(); ++i) {
            cout << factory[i] << endl;
        }
    }

    return 0;
}