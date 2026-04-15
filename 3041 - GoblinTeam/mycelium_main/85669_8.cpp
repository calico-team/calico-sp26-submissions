#include <iostream>
#include <queue>
#include <unordered_set>
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

uint64_t get_key(ll x, ll y) {
    return (uint64_t)(x + 1000000000) << 32 | (uint32_t)(y + 1000000000);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll xg, yg, xm, ym;
    cin >> xg >> yg >> xm >> ym;

    priority_queue<Node> q;
    unordered_set<uint64_t> vis;

    q.emplace(xm, ym, 0);
    vis.insert(get_key(xm, ym));

    ll ans = 0;

    while (!q.empty()) {
        Node u = q.top();
        q.pop();

        ll d = (ll)abs(u.x - xg) + (ll)abs(u.y - yg);
        ll t_grass = d * 2;

        if (u.t < t_grass) {
            ans++;
            for (int i = 0; i < 4; ++i) {
                ll nx = u.x + dx[i];
                ll ny = u.y + dy[i];
                uint64_t key = get_key(nx, ny);
                if (!vis.count(key)) {
                    vis.insert(key);
                    q.emplace(nx, ny, u.t + 7);
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}