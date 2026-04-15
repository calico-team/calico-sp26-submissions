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

    for (int z = 0; z < N; z++) {
        int a = 0;
        int b = 0;

        for (int x = 0; x < N; x++) {
            if (S1[x][z] == '#') {
                a++;
            }
            if (S2[x][z] == '#') {
                b++;
            }
        }

        maxvol += 1LL * a * b;
        minvol += max(a, b);
    }

    return to_string(maxvol) + " " + to_string(minvol);
}

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;

        vector<string> S1(N);
        vector<string> S2(N);

        for (int i = 0; i < N; i++) {
            cin >> S1[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> S2[i];
        }

        cout << solve(N, S1, S2) << '\n';
    }
}