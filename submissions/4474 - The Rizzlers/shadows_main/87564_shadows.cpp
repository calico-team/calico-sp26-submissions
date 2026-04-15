#include <iostream>
#include <vector>

using namespace std;

/**
 * Return the maximal and minimal volume of the shape (in that order)
 *
 * N: max dimensions of shape
 * S1: projection (shadow) in X-Z plane
 * S2: projection (shadow) in Y-Z plane
 */

string solve(int N, vector<string> S1, vector<string> S2) {
    // 3d array
    vector<vector<int>> x(N, vector<int>(N, N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (S1[i][j] == '.') {
                x[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (S2[i][j] == '.') {
                for (int k = 0; k < N; k++) {
                    x[i][k]--;
                    if (x[i][k] < 0) x[i][k] = 0;
                }
            }
        }
    }
    // calculate mx and mn
    int mn = 0, mx = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            mx += x[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        int mx_row = 0;
        for (int j = 0; j < N; j++) {
            mx_row = max(mx_row, x[i][j]);
        }
        for (int j = 0; j < N; j++) {
            if (x[i][j] < mx_row) {
                if (x[i][j] != 0) mn++;
            }
        }
        mn += mx_row;
    }
    string smn = to_string(mn);
    string smx = to_string(mx);
    return smx + " " + smn;
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int N;
        cin >> N;
        vector<string> S1(N);
        for (int i = 0; i < N; i++) {
            cin >> S1[i];
        }
        vector<string> S2(N);
        for (int i = 0; i < N; i++) {
            cin >> S2[i];
        }
        cout << solve(N, S1, S2) << '\n';
    }
}
