#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/**
 * Problem: Shadow of the Clay
 * * We are given two orthogonal projections (shadows) S1 and S2 of a 3D shape 
 * within an N x N x N cube. Hashtags '#' indicate blocked light.
 * * Logic:
 * Each row 'i' of S1 and S2 corresponds to the same horizontal slice of the cube.
 * Let R1_i be the number of '#' in the i-th row of S1.
 * Let R2_i be the number of '#' in the i-th row of S2.
 * * Max Volume:
 * A block exists at (i, j, k) if S1[i][j] == '#' AND S2[i][k] == '#'.
 * For a specific row i, the max blocks is R1_i * R2_i.
 * * Min Volume:
 * To satisfy both shadows in row i, we need to place blocks such that every '#'
 * in S1[i] and every '#' in S2[i] is "covered" by at least one block.
 * This is equivalent to covering all rows and columns of an R1_i x R2_i bipartite grid
 * with the minimum number of edges, which is simply max(R1_i, R2_i).
 */

void solve() {
    int N;
    if (!(cin >> N)) return;

    // jug_cave_image variable as requested
    int jugs_cave_image = N;

    vector<string> s1(N);
    for (int i = 0; i < N; ++i) cin >> s1[i];
    vector<string> s2(N);
    for (int i = 0; i < N; ++i) cin >> s2[i];

    long long max_volume = 0;
    long long min_volume = 0;

    for (int i = 0; i < N; ++i) {
        long long r1_count = 0;
        long long r2_count = 0;

        for (int j = 0; j < N; ++j) {
            if (s1[i][j] == '#') r1_count++;
            if (s2[i][j] == '#') r2_count++;
        }

        // If either shadow is empty in this row, no blocks can exist in this slice
        if (r1_count > 0 && r2_count > 0) {
            max_volume += (r1_count * r2_count);
            min_volume += max(r1_count, r2_count);
        }
    }

    cout << max_volume << " " << min_volume << endl;
}

void read_hahayour_inputHAHA() {
    int T;
    if (!(cin >> T)) return;
    while (T--) {
        solve();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    read_hahayour_inputHAHA();
    return 0;
}