#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int N, M, K;
        cin >> N >> M >> K;
        vector<string> g(N);
        for (int i = 0; i < N; i++) cin >> g[i];

        vector<pair<int, int>> seats;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                if (g[i][j] == '-')
                    seats.emplace_back(i, j);


        vector<vector<int>> sum(N+1, vector<int>(M+1, 0));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                sum[i+1][j+1] = sum[i+1][j] + sum[i][j+1] - sum[i][j] + (g[i][j] == '-' ? 1 : 0);


        int l = 0, r = N + M, best = N + M;
        while (l <= r) {
            int mid = (l + r) / 2;
            bool ok = false;

            for (int dh = 0; dh <= min(mid, N-1); dh++) {
                int dw = mid - dh;
                if (dw < 0 || dw >= M) continue;

                for (int i = 0; i + dh < N; i++) {
                    int i2 = i + dh;
                    for (int j = 0; j + dw < M; j++) {
                        int j2 = j + dw;
                        int cnt = sum[i2+1][j2+1] - sum[i][j2+1] - sum[i2+1][j] + sum[i][j];
                        if (cnt >= K) {
                            ok = true;
                            goto done;
                        }
                    }
                }
            }
        done:
            if (ok) {
                best = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }


        vector<pair<int, int>> ans;
        bool found = false;
        for (int dh = 0; dh <= min(best, N-1); dh++) {
            int dw = best - dh;
            if (dw < 0 || dw >= M) continue;

            for (int i = 0; i + dh < N; i++) {
                int i2 = i + dh;
                for (int j = 0; j + dw < M; j++) {
                    int j2 = j + dw;
                    int cnt = sum[i2+1][j2+1] - sum[i][j2+1] - sum[i2+1][j] + sum[i][j];
                    if (cnt >= K) {

                        for (int s = 0; s < seats.size(); s++) {
                            int x = seats[s].first;
                            int y = seats[s].second;
                            if (x >= i && x <= i2 && y >= j && y <= j2) {
                                ans.emplace_back(x, y);
                                if (ans.size() == K) {
                                    found = true;
                                    goto out;
                                }
                            }
                        }
                    }
                }
            }
        }
    out:

        for (int s = 0; s < ans.size(); s++) {
            cout << ans[s].first << " " << ans[s].second << "\n";
        }
    }
    return 0;
}