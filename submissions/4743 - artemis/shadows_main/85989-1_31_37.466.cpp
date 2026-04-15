#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
 * Return the maximal and minimal volume of the shape (in that order)
 *
 * N: max dimensions of shape
 * S1: projection (shadow) in X-Z plane
 * S2: projection (shadow) in Y-Z plane
 */
string solve(int N, vector<string> S1, vector<string> S2) {
    long long maxvol = 0;
    long long minvol = 0;

    for (int row = 0; row < N; row++) {
        int front = 0;
        int side = 0;

        for (int col = 0; col < N; col++) {
            if (S1[row][col] == '#') {
                front++;
            }
            if (S2[row][col] == '#') {
                side++;
            }
        }

        maxvol += 1LL * front * side;
        minvol += max(front, side);
    }

    return to_string(maxvol) + " " + to_string(minvol);
}

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int N;
        cin >> N;

        vector<string> S1(N);
        vector<string> S2(N);

        for (int j = 0; j < N; j++) {
            cin >> S1[j];
        }
        for (int j = 0; j < N; j++) {
            cin >> S2[j];
        }

        cout << solve(N, S1, S2) << '\n';
    }
}