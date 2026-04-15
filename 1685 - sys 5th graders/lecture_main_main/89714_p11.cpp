#include <bits/stdc++.h>
using namespace std;

struct Point {
    int u, v, x, y;
};

int n, m, k;

bool can(int D, vector<Point> &pts, vector<Point> &best) {
    multiset<int> vset;
    int l = 0;

    for (int r = 0; r < (int)pts.size(); r++) {
        vset.insert(pts[r].v);

        while (pts[r].u - pts[l].u > 2 * D) {
            vset.erase(vset.find(pts[l].v));
            l++;
        }

        if ((int)vset.size() >= k) {
            auto it1 = vset.begin();
            auto it2 = vset.end();
            --it2;

            int vmin = *it1;
            int vmax = *it2;

            if (vmax - vmin <= 2 * D) {
                // construct answer
                best.clear();
                for (int i = l; i <= r; i++) {
                    best.push_back(pts[i]);
                    if ((int)best.size() == k) break;
                }
                return true;
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        cin >> n >> m >> k;

        vector<Point> pts;

        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < m; j++) {
                if (s[j] == '-') {
                    pts.push_back({i + j, i - j, i, j});
                }
            }
        }

        if (k == 1) {
            cout << pts[0].x << " " << pts[0].y << "\n";
            continue;
        }

        sort(pts.begin(), pts.end(), [](const Point &a, const Point &b) {
            return a.u < b.u;
        });

        int lo = 0, hi = n + m, ansD = hi;
        vector<Point> best, cur;

        while (lo <= hi) {
            int mid = (lo + hi) / 2;

            if (can(mid, pts, cur)) {
                ansD = mid;
                best = cur;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        // output result
        for (int i = 0; i < k; i++) {
            cout << best[i].x << " " << best[i].y << "\n";
        }
    }

    return 0;
}