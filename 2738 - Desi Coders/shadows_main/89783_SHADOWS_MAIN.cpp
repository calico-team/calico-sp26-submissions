#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<string> S1(N), S2(N);
        for (int i = 0; i < N; i++) cin >> S1[i];
        for (int i = 0; i < N; i++) cin >> S2[i];

        long long jugs_cave_image = 0;

        for (int i = 0; i < N; i++) {
            int c1 = 0, c2 = 0;
            for (int j = 0; j < N; j++) {
                if (S1[i][j] == '#') c1++;
                if (S2[i][j] == '#') c2++;
            }
            jugs_cave_image += (long long)c1 * c2;
        }

        long long maxv = jugs_cave_image;

        long long minv = 0;
        for (int i = 0; i < N; i++) {
            bool r = false, c = false;
            for (int j = 0; j < N; j++) {
                if (S1[i][j] == '#') r = true;
                if (S2[i][j] == '#') c = true;
            }
            if (r && c) minv++;
        }

        cout << maxv << " " << minv << '\n';
    }

    return 0;
}