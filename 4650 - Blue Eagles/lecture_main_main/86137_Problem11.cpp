#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

struct Point {
    int u, v, r, c;
};

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

        vector<Point> pts;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (grid[i][j] == '-') {
                    pts.push_back({i + j, i - j, i, j});
                }
            }
        }

        int E = pts.size();

        sort(pts.begin(), pts.end(), [](auto &a, auto &b) {
            return a.u < b.u;
        });

        vector<Point> answer;

        auto can = [&](int D, vector<Point> &res) {
            multiset<pair<int,int>> ms; 

            int l = 0;

            for (int r = 0; r < E; r++) {
                ms.insert({pts[r].v, r});

                while (pts[r].u - pts[l].u > D) {
                    ms.erase(ms.find({pts[l].v, l}));
                    l++;
                }

                if ((int)ms.size() >= K) {
                    int minv = ms.begin()->first;
                    int maxv = ms.rbegin()->first;

                    if (maxv - minv <= D) {
                        res.clear();
                        int cnt = 0;
                        for (auto &p : ms) {
                            res.push_back(pts[p.second]);
                            if (++cnt == K) break;
                        }
                        return true;
                    }
                }
            }
            return false;
        };

        int lo = 0, hi = 2000;
        vector<Point> best;

        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            vector<Point> cur;

            if (can(mid, cur)) {
                best = cur;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        for (auto &p : best) {
            cout << p.r << " " << p.c << endl;
        }
    }

    return 0;
}