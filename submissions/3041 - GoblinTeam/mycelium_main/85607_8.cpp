#include <iostream>
#include <queue>
#include <set>
using namespace std;
typedef long long ll;

struct Node {
    ll x, y, t;
    Node(ll x_, ll y_, ll t_) : x(x_), y(y_), t(t_) {}
    bool operator<(const Node& other) const {
        return t > other.t;
    }
};

int main() {
    ll xg, yg, xm, ym;
    cin >> xg >> yg >> xm >> ym;

    priority_queue<Node> q;
    set<pair<ll, ll>> vis;
    q.emplace(xm, ym, 0);
    vis.insert({xm, ym});

    ll ans = 0;
    ll dx[] = {1, -1, 0, 0};
    ll dy[] = {0, 0, 1, -1};

    while (!q.empty()) {
        Node u = q.top();
        q.pop();

        ll d = abs(u.x - xg) + abs(u.y - yg);
        ll t_goal = d;
        ll t_mon = u.t;

        if (t_mon < t_goal) {
            ans++;
            for (int i = 0; i < 4; ++i) {
                ll nx = u.x + dx[i];
                ll ny = u.y + dy[i];
                if (!vis.count({nx, ny})) {
                    vis.insert({nx, ny});
                    q.emplace(nx, ny, t_mon + 1);
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}