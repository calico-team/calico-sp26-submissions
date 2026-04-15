#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll estimate_large(ll xg, ll yg, ll xm, ll ym) {
    ll dx = abs(xg - xm);
    ll dy = abs(yg - ym);
    ll dist = dx + dy;
    return 1 + 4 * (dist / 5);
}

void solve() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        ll XG, YG, XM, YM;
        cin >> XG >> YG >> XM >> YM;

        if (abs(XG) + abs(YG) + abs(XM) + abs(YM) > 100) {
            cout << estimate_large(XG, YG, XM, YM) << '\n';
            continue;
        }

        unordered_map<ll, int> grass_time, mycelium_time;

        auto encode = [&](ll x, ll y) {
            return (x << 32) ^ (y & 0xffffffff);
        };

        queue<tuple<ll,ll,int>> q;

        q.push({XG, YG, 0});
        grass_time[encode(XG, YG)] = 0;

        while (!q.empty()) {
            auto [x, y, t_grass] = q.front();
            q.pop();
            if (t_grass > 1000) continue;

            vector<pair<ll,ll>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
            for (auto [dx, dy] : dirs) {
                ll nx = x + dx, ny = y + dy;
                ll key = encode(nx, ny);
                if (!grass_time.count(key)) {
                    grass_time[key] = t_grass + 2;
                    q.push({nx, ny, t_grass + 2});
                }
            }
        }

        q.push({XM, YM, 0});
        mycelium_time[encode(XM, YM)] = 0;

        while (!q.empty()) {
            auto [x, y, t_myc] = q.front();
            q.pop();
            if (t_myc > 1000) continue;

            vector<pair<ll,ll>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
            for (auto [dx, dy] : dirs) {
                ll nx = x + dx, ny = y + dy;
                ll key = encode(nx, ny);
                if (!mycelium_time.count(key)) {
                    mycelium_time[key] = t_myc + 7;
                    q.push({nx, ny, t_myc + 7});
                }
            }
        }

        ll count = 0;
        for (auto &it : mycelium_time) {
            ll key = it.first;
            int t_myc = it.second;
            int t_grass = grass_time.count(key) ? grass_time[key] : INT_MAX;
            if (t_myc < t_grass) count++;
        }

        cout << count << '\n';
    }
}

int main() {
    solve();
    return 0;
}