#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

using pii = pair<int,int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N, M, K;
        cin >> N >> M >> K;

        vector<string> grid(N);
        for (int i = 0; i < N; i++) cin >> grid[i];

        vector<pii> empty;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (grid[i][j] == '-') {
                    empty.push_back({i, j});
                }
            }
        }

        int lo = 0, hi = N + M;
        vector<pii> answer;

        auto can = [&](int D, vector<pii> &res) {
            for (auto &[r, c] : empty) {
                vector<pii> temp;

                for (auto &[r2, c2] : empty) {
                    if (abs(r - r2) + abs(c - c2) <= D) {
                        temp.push_back({r2, c2});
                    }
                }

                if ((int)temp.size() >= K) {
                    res.assign(temp.begin(), temp.begin() + K);
                    return true;
                }
            }
            return false;
        };

        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            vector<pii> cur;

            if (can(mid, cur)) {
                answer = cur;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        for (auto &[r, c] : answer) {
            cout << r << " " << c << "\n";
        }
    }

    return 0;
}