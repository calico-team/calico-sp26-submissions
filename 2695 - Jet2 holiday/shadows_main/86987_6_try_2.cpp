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

        long long mx = 0, mn = 0;

        // 枚举 z（列）
        for (int z = 0; z < N; z++) {
            int cnt1 = 0, cnt2 = 0;

            // S1: 行=y，列=z
            for (int y = 0; y < N; y++) {
                if (S1[y][z] == '#') cnt1++;
            }

            // S2: 行=x，列=z
            for (int x = 0; x < N; x++) {
                if (S2[x][z] == '#') cnt2++;
            }

            mx += 1LL * cnt1 * cnt2;
            mn += max(cnt1, cnt2);
        }

        cout << mx << " " << mn << "\n";
    }
}