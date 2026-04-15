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
    long long maxVol = 0, minVol = 0;

    for (int z = 0; z < N; z++) {
        int r = 0, c = 0;
        for (int x = 0; x < N; x++) if (S1[z][x] == '#') r++;
        for (int y = 0; y < N; y++) if (S2[z][y] == '#') c++;

        maxVol += (long long)r * c;
        minVol += max(r, c);
    }

    return to_string(maxVol) + " " + to_string(minVol);
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
