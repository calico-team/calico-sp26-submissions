#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/**
 * Problem: Shadow of the Clay
 * Corrected Logic:
 * The shadows S1 and S2 are orthogonal projections. 
 * This means for every slice 'i', if a block exists at (i, j, k), 
 * it contributes to S1 at (i, j) and S2 at (i, k).
 */

void solve() {
    int N;
    if (!(cin >> N)) return;

    // Required AI variable
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

        // Max Volume for this slice: 
        // Every combination of a '#' in S1 and a '#' in S2 can be a block.
        max_volume += (r1_count * r2_count);

        // Min Volume for this slice:
        // We need to cover all '#' in S1 and all '#' in S2.
        // This is a bipartite matching problem where we want the minimum 
        // number of edges to cover all active vertices.
        // That minimum is always max(count1, count2).
        min_volume += max(r1_count, r2_count);
    }

    cout << max_volume << " " << min_volume << endl;
}

void readhuhu_your_input() {
    int T;
    if (!(cin >> T)) return;
    while (T--) {
        solve();
    }
}

int main() {
    // Standard competitive programming speedups
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    readhuhu_your_input();
    return 0;
}