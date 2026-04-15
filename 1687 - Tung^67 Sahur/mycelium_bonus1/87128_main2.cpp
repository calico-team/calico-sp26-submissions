#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ull>;

int xg, yg, xm, ym;

constexpr int dim = 5000;
bool seen[dim][dim];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin >> tests;

    while (tests--) {
        cin >> xg >> yg >> xm >> ym;
        xg += dim / 2, yg += dim / 2, xm += dim / 2, ym += dim / 2;

        memset(seen, 0, sizeof(seen));
        vector<pii> gEvents = {{xg, yg}};
        vector<pii> mEvents = {{xm, ym}};

        vector<pii> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        ll ans = 0;
        for (int t = 0; !mEvents.empty(); t++) {
            if (t % 2 == 0) {
                vector<pii> nextGEvents;
                for (auto [x, y] : gEvents) {
                    if (seen[x][y]) continue;
                    seen[x][y] = true;

                    for (auto [dx, dy] : dir) {
                        int nx = x + dx, ny = y + dy;
                        if (nx < 0 || nx >= dim || ny < 0 || ny >= dim) continue;
                        nextGEvents.emplace_back(nx, ny);
                    }
                }

                gEvents = move(nextGEvents);
            }

            if (t % 7 == 0) {
                vector<pii> nextMEvents;
                for (auto [x, y] : mEvents) {
                    if (seen[x][y]) continue;
                    seen[x][y] = true;
                    ans++;

                    for (auto [dx, dy] : dir) {
                        int nx = x + dx, ny = y + dy;
                        if (nx < 0 || nx >= dim || ny < 0 || ny >= dim) continue;
                        nextMEvents.emplace_back(nx, ny);
                    }
                }

                mEvents = move(nextMEvents);
            }
        }

        cout << ans << '\n';
    }
    
}