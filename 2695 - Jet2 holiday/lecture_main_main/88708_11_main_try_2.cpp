#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool check(int D, int N, int M, int K, vector<vector<int>>& sum) {
    if (D < 0) return false;
    for (int dh = 0; dh <= min(D, N-1); dh++) {
        int dw = D - dh;
        if (dw < 0 || dw >= M) continue;

        vector<int> col(M, 0);
        for (int c = 0; c < M; c++) {
            col[c] = sum[dh+1][c+1] - sum[0][c+1] - sum[dh+1][c] + sum[0][c];
        }

        int cur = 0;
        for (int c = 0; c < M; c++) {
            cur += col[c];
            if (c >= dw+1) cur -= col[c - dw - 1];
            if (c >= dw && cur >= K) return true;
        }

        for (int i = 1; i + dh < N; i++) {
            int i2 = i + dh;
            for (int c = 0; c < M; c++) {
                col[c] = col[c] - (sum[i][c+1] - sum[i-1][c+1] - sum[i][c] + sum[i-1][c])
                          + (sum[i2+1][c+1] - sum[i2][c+1] - sum[i2+1][c] + sum[i2][c]);
            }
            cur = 0;
            for (int c = 0; c < M; c++) {
                cur += col[c];
                if (c >= dw+1) cur -= col[c - dw - 1];
                if (c >= dw && cur >= K) return true;
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int N, M, K;
        cin >> N >> M >> K;
        vector<string> g(N);
        for (int i = 0; i < N; i++) {
            cin >> g[i];
        }

        vector<pair<int, int>> seats;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (g[i][j] == '-') {
                    seats.emplace_back(i, j);
                }
            }
        }

        vector<vector<int>> sum(N+1, vector<int>(M+1, 0));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                sum[i+1][j+1] = sum[i+1][j] + sum[i][j+1] - sum[i][j] + (g[i][j] == '-' ? 1 : 0);
            }
        }

        int l = 0, r = N + M, best = N + M;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (check(mid, N, M, K, sum)) {
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
                        ans.clear();
                        for (size_t s = 0; s < seats.size(); s++) {
                            int x = seats[s].first;
                            int y = seats[s].second;
                            if (x >= i && x <= i2 && y >= j && y <= j2) {
                                ans.push_back({x, y});
                                if ((int)ans.size() == K) {
                                    found = true;
                                    goto out_find;
                                }
                            }
                        }
                    }
                }
            }
        }

    out_find:
        if (!found || (int)ans.size() < K) {
            ans.clear();
            for (int s = 0; s < K; s++) {
                ans.push_back(seats[s]);
            }
        }

        for (auto& p : ans) {
            cout << p.first << " " << p.second << "\n";
        }
    }
    return 0;
}