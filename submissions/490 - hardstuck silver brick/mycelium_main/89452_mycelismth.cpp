#include <bits/stdc++.h>
using namespace std;

struct Event {
    int t, type, x, y;
    bool operator>(const Event& other) const {
        if (t != other.t) return t > other.t;
        return type > other.type;
    }
};

void solve() {
    long long XG, YG, XM, YM;
    cin >> XG >> YG >> XM >> YM;

    long long D = llabs(XM - XG) + llabs(YM - YG);

    int R = (2 * D) / 3 + 5;
    long long Wll = 2LL * R + 1LL;

    if (Wll > 7000) {
        cout << 0 << "\n";
        return;
    }

    int W = (int)Wll;
    int S = W * W;

    vector<char> owner(S, 0);
    vector<int> bestG(S, INT_MAX), bestM(S, INT_MAX);

    priority_queue<Event, vector<Event>, greater<Event>> pq;

    int cx = R, cy = R;

    int mid = cx * W + cy;
    bestM[mid] = 0;
    pq.push({0, 2, cx, cy});

    auto push_boundary = [&](int i, int j) {
        long long wx = (XM - R) + i;
        long long wy = (YM - R) + j;

        long long d = llabs(wx - XG) + llabs(wy - YG);
        int t = (int)(2 * d);

        if (t >= (int)2e9) return;

        int id = i * W + j;
        if (t < bestG[id]) {
            bestG[id] = t;
            pq.push({t, 1, i, j});
        }
    };

    for (int i = 0; i < W; i++) {
        push_boundary(i, 0);
        push_boundary(i, W - 1);
    }
    for (int j = 1; j < W - 1; j++) {
        push_boundary(0, j);
        push_boundary(W - 1, j);
    }

    long long gx = XG - (XM - R);
    long long gy = YG - (YM - R);

    if (0 <= gx && gx < W && 0 <= gy && gy < W) {
        int id = gx * W + gy;
        bestG[id] = 0;
        pq.push({0, 1, (int)gx, (int)gy});
    }

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    long long myc = 0;

    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();

        int x = cur.x, y = cur.y;
        int id = x * W + y;

        if (cur.type == 1) {
            if (owner[id]) continue;
            owner[id] = 1;

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k], ny = y + dy[k];
                if (nx < 0 || nx >= W || ny < 0 || ny >= W) continue;

                int nid = nx * W + ny;
                if (owner[nid]) continue;

                int nt = cur.t + 2;
                if (nt < bestG[nid]) {
                    bestG[nid] = nt;
                    pq.push({nt, 1, nx, ny});
                }
            }
        } 
        else {
            if (owner[id]) continue;
            owner[id] = 2;
            myc++;

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k], ny = y + dy[k];
                if (nx < 0 || nx >= W || ny < 0 || ny >= W) continue;

                int nid = nx * W + ny;
                if (owner[nid]) continue;

                int nt = cur.t + 7;
                if (nt < bestM[nid]) {
                    bestM[nid] = nt;
                    pq.push({nt, 2, nx, ny});
                }
            }
        }
    }

    cout << myc << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();

    return 0;
}