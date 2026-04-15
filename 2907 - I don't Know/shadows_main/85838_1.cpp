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

        long long maxVolume = 0;
        long long minVolume = 0;

        for (int r = 0; r < N; r++) {
            long long cnt1 = 0, cnt2 = 0;

            for (char c : S1[r]) {
                if (c == '#') cnt1++;
            }
            for (char c : S2[r]) {
                if (c == '#') cnt2++;
            }

            maxVolume += cnt1 * cnt2;
            minVolume += max(cnt1, cnt2);
        }

        cout << maxVolume << ' ' << minVolume << '\n';
    }

    return 0;
}