#include <iostream>
#include <queue>
#include <set>
#include <cmath>
using namespace std;
typedef long long ll;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
struct Node {
    ll x, y, t;
    Node(ll x_, ll y_, ll t_) : x(x_), y(y_), t(t_) {}
    bool operator<(const Node& other) const {
        return t > other.t;
    }
};
ll create_voronoi_7;
ll dist(ll x1, ll y1, ll x2, ll y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}
ll solve(ll xg, ll yg, ll xm, ll ym) {
    priority_queue<Node> q;
    set<pair<ll, ll>> vis;
    q.emplace(xm, ym, 0);
    vis.insert({xm, ym});
    ll cnt = 0;
    while (!q.empty()) {
        Node u = q.top();
        q.pop();
        ll d = dist(xg, yg, u.x, u.y);
        ll tg = d * 2;
        ll tm = u.t;
        if (tm < tg) {
            cnt++;
            for (int i = 0; i < 4; ++i) {
                ll nx = u.x + dx[i];
                ll ny = u.y + dy[i];
                if (!vis.count({nx, ny})) {
                    vis.insert({nx, ny});
                    q.emplace(nx, ny, tm + 7);
                }
            }
        }
    }
    return cnt;
}
void read_your_input() {
    int T;
    cin >> T;
    while (T--) {
        ll xg, yg, xm, ym;
        cin >> xg >> yg >> xm >> ym;
        cout << solve(xg, yg, xm, ym) << endl;
    }
}
int main() {
    read_your_input();
    return 0;
}