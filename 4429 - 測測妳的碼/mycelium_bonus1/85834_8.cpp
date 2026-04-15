#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct P {
    int x, y;
    bool operator==(const P& other) const {
        return x == other.x && y == other.y;
    }
};

struct H {
    size_t operator()(const P& p) const {
        return ((uint64_t)(uint32_t)(p.x + 1000000007) << 32) ^ (uint32_t)(p.y + 1000000009);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    const int dx[4] = {1, -1, 0, 0};
    const int dy[4] = {0, 0, 1, -1};

    while (T--) {
        int xg, yg, xm, ym;
        cin >> xg >> yg >> xm >> ym;

        int d = abs(xg - xm) + abs(yg - ym);
        int lim = d * 8 + 50;

        int lx = min(xg, xm) - lim;
        int rx = max(xg, xm) + lim;
        int ly = min(yg, ym) - lim;
        int ry = max(yg, ym) + lim;

        unordered_map<P, char, H> st;
        vector<P> g, m;
        g.push_back({xg, yg});
        m.push_back({xm, ym});
        st[{xg, yg}] = 1;
        st[{xm, ym}] = 2;

        ll ans = 1;
        int t = 0;
        vector<P> fg = g, fm = m;

        while (true) {
            t++;

            vector<P> ng, nm;
            unordered_set<P, H> sg, sm;

            if (t % 2 == 0) {
                for (auto &u : fg) {
                    for (int k = 0; k < 4; k++) {
                        int nx = u.x + dx[k];
                        int ny = u.y + dy[k];
                        if (nx < lx || nx > rx || ny < ly || ny > ry) continue;
                        P v{nx, ny};
                        if (!st.count(v)) sg.insert(v);
                    }
                }
            }

            if (t % 7 == 0) {
                for (auto &u : fm) {
                    for (int k = 0; k < 4; k++) {
                        int nx = u.x + dx[k];
                        int ny = u.y + dy[k];
                        if (nx < lx || nx > rx || ny < ly || ny > ry) continue;
                        P v{nx, ny};
                        if (!st.count(v)) sm.insert(v);
                    }
                }
            }

            for (auto &v : sg) {
                if (sm.count(v)) sm.erase(v);
            }

            if (t % 2 == 0) {
                for (auto &v : sg) {
                    st[v] = 1;
                    ng.push_back(v);
                }
                fg = ng;
            }

            if (t % 7 == 0) {
                for (auto &v : sm) {
                    st[v] = 2;
                    nm.push_back(v);
                }
                ans += (ll)nm.size();
                fm = nm;
                if (nm.empty()) break;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}