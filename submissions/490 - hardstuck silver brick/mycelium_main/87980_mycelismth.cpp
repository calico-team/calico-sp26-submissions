#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct State {
    ll time;
    char entity; // 'g' grass 'm' myceli whatever
    ll x, y;  // coords

    // process low times first, g>>m
    bool operator>(const State& other) const {
        if (time != other.time) return time > other.time;
        return entity > other.entity; 
    }
};

int main() {
    int t; cin >> t;
    while (t--) {
        ll xg, yg, xm, ym; cin >> xg >> yg >> xm >> ym;

        // recenter grass 0,0 to make it easier
        xm -= xg;
        ym -= yg;

        ll distance = abs(xm) + abs(ym);

        // i hate bfs
        priority_queue<State, vector<State>, greater<State>> pq;
        pq.push({0, 'G', 0, 0});
        pq.push({0, 'M', xm, ym});

        map<pair<ll, ll>, char> win;
        
        // radius for bounding box to stop searching too far... hopefully it works
        ll area = 0, radius = (distance / 2) + 5;

        while (!pq.empty()) {
            State curr = pq.top();
            pq.pop();
            pair<ll, ll> pos = {curr.x, curr.y};

            if (win.count(pos)) continue;

            win[pos] = curr.entity;
            if (curr.entity == 'M') area++;
            if (curr.entity == 'G' && (curr.x < xm - radius || curr.x > xm + radius || curr.y < ym - radius || curr.y > ym + radius)) continue;

            ll nxt = curr.time + (curr.entity == 'G' ? 2 : 7);
            ll dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};

            for (int i = 0; i < 4; i++) {
                ll nx = curr.x + dx[i], ny = curr.y + dy[i];
                if (!win.count({nx, ny})) pq.push({nxt, curr.entity, nx, ny});
            }
        }
        cout << area << endl;
    }
}