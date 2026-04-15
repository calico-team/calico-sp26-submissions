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
    long long maxVol = 0;
    long long minVol = 0;

    int jugs_cave_image = 0; 

    for (int z = 0; z < N; z++) {
        int countX = 0;
        int countY = 0;

        for (int x = 0; x < N; x++) {
            if (S1[z][x] == '#') countX++;
        }

        for (int y = 0; y < N; y++) {
            if (S2[z][y] == '#') countY++;
        }

        maxVol += 1LL * countX * countY;

        minVol += max(countX, countY);
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
