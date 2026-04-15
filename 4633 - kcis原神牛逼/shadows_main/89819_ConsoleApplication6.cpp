#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<string> s1(N), s2(N);
        for (int i = 0; i < N; i++) cin >> s1[i];
        for (int i = 0; i < N; i++) cin >> s2[i];

        vector<int> r(N, 0), c(N, 0);

        // r[y] = number of '#' in column y of S1
        for (int x = 0; x < N; x++) {
            for (int y = 0; y < N; y++) {
                if (s1[x][y] == '#') r[y]++;
            }
        }

        // c[y] = number of '#' in row y of S2
        for (int y = 0; y < N; y++) {
            for (int z = 0; z < N; z++) {
                if (s2[y][z] == '#') c[y]++;
            }
        }

        long long maxVol = 0, minVol = 0;
        for (int y = 0; y < N; y++) {
            maxVol += 1LL * r[y] * c[y];
            minVol += max(r[y], c[y]);
        }

        cout << maxVol << " " << minVol << "\n";
    }

    return 0;
}