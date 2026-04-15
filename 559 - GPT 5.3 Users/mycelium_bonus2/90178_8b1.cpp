/*
 * BFS with pruning and an initial jump optimization (binary search variant).
 *
 * Same as jump_and_prune, but finds the first overlap time using binary search
 * instead of linear search. This reduces the jump phase from O(distance) to
 * O(log(distance)).
 */
#include <deque>
#include <iostream>
#include <tuple>
#include <unordered_map>
#include <vector>

using namespace std;
typedef long long ll;

const int GRASS_DELAY = 2;
const int MYCELIUM_DELAY = 7;
const vector<pair<int,int>> EXPAND_DIRS = {{0,1},{-1,0},{1,0},{0,-1}};
const vector<pair<int,int>> EIGHT_DIRS = {
    {-1,1},{0,1},{1,1},{-1,0},{1,0},{-1,-1},{0,-1},{1,-1}
};

struct PairHash {
    size_t operator()(pair<int,int> const& p) const {
        return hash<ll>()((ll)p.first << 32 | (unsigned int)p.second);
    }
};

ll l1dist(ll x1, ll y1, ll x2, ll y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

/** All tiles on the perimeter of the L1 diamond of radius r centered at (x, y). */
vector<pair<int,int>> diamond_frontier(int x, int y, int r) {
    if (r == 0) return {{x, y}};
    vector<pair<int,int>> result;
    result.reserve(4 * r);
    for (int i = 0; i < r; i++) {
        result.push_back({x+i, y+r-i});
        result.push_back({x+r-i, y-i});
        result.push_back({x-i, y-r+i});
        result.push_back({x-r+i, y+i});
    }
    return result;
}

/** Number of tiles in L1 diamond of radius r. */
ll diamond_tile_count(int r) {
    return 2LL * r * (r + 1) + 1;
}

/** Smallest multiple of m that is >= x. */
ll ceil_to_multiple(ll x, ll m) {
    return ((x + m - 1) / m) * m;
}

/**
 * Returns (time, grass_radius, mycelium_radius) at the START of the tick
 * of first overlap using binary search.
 */
tuple<ll,ll,ll> jump_using_binary_search(int X_G, int Y_G, int X_M, int Y_M) {
    ll d = l1dist(X_G, Y_G, X_M, Y_M);
    // Binary search for the smallest time where sum of radii >= d.
    // Sum of radii = t//GRASS_DELAY + t//MYCELIUM_DELAY, monotonically non-decreasing.
    ll lo = 1, hi = d * GRASS_DELAY * MYCELIUM_DELAY + 1;
    while (lo < hi) {
        ll mid = (lo + hi) / 2;
        if (mid / GRASS_DELAY + mid / MYCELIUM_DELAY >= d) hi = mid;
        else lo = mid + 1;
    }
    ll time = lo;
    ll grass_radius = (time - 1) / GRASS_DELAY;
    ll mycelium_radius = (time - 1) / MYCELIUM_DELAY;
    return {time, grass_radius, mycelium_radius};
}

// If radii exceed this limit the frontier is too large to enumerate; the BFS
// would TLE anyway (bonus3-scale inputs), so we skip the jump entirely.
const ll MAX_JUMP_RADIUS = 1e7;

/**
 * Return the total number of tiles mycelium will ever occupy.
 *
 * X_G: x-coordinate of grass starting position
 * Y_G: y-coordinate of grass starting position
 * X_M: x-coordinate of mycelium starting position
 * Y_M: y-coordinate of mycelium starting position
 */
ll solve(int X_G, int Y_G, int X_M, int Y_M) {
    // Phase 1: Binary search for the first contact time and initial radii.
    auto [time, grass_radius, mycelium_radius] = jump_using_binary_search(X_G, Y_G, X_M, Y_M);

    // Skip jump for inputs where the frontier is too large to enumerate.
    if (grass_radius > MAX_JUMP_RADIUS) { time = 1; grass_radius = 0; mycelium_radius = 0; }

    unordered_map<pair<int,int>, char, PairHash> tiles;

    // Virtual tile lookup: checks materialized tiles, then virtual jump radii.
    auto get_tile = [&](int x, int y) -> char {
        auto it = tiles.find({x, y});
        if (it != tiles.end()) return it->second;
        if (l1dist(x, y, X_G, Y_G) <= grass_radius) return 'G';
        if (l1dist(x, y, X_M, Y_M) <= mycelium_radius) return 'M';
        return 0;
    };

    // Seed BFS queues with post-jump frontiers.
    deque<tuple<int,int,int>> grass_q, mycelium_q;
    for (auto [x, y] : diamond_frontier(X_G, Y_G, (int)grass_radius))
        grass_q.emplace_back(x, y, (int)ceil_to_multiple(time, GRASS_DELAY));
    for (auto [x, y] : diamond_frontier(X_M, Y_M, (int)mycelium_radius))
        mycelium_q.emplace_back(x, y, (int)ceil_to_multiple(time, MYCELIUM_DELAY));

    // Pre-count the tiles in the mycelium diamond.
    ll total_mycelium = diamond_tile_count((int)mycelium_radius);

    // Phase 2: Run pruning BFS from the jumped state.
    int cur_time = (int)time;
    int first_contact_time = -1;

    while (!mycelium_q.empty()) {
        while (!grass_q.empty() && get<2>(grass_q.front()) == cur_time) {
            auto [x, y, t] = grass_q.front(); grass_q.pop_front();

            // After first contact, prune tiles with no 8-neighboring mycelium.
            if (first_contact_time != -1 && cur_time > first_contact_time) {
                bool near_mycelium = false;
                for (auto [dx, dy] : EIGHT_DIRS)
                    if (get_tile(x+dx, y+dy) == 'M') { near_mycelium = true; break; }
                if (!near_mycelium) continue;
            }

            for (auto [dx, dy] : EXPAND_DIRS) {
                int nx = x + dx, ny = y + dy;
                char tv = get_tile(nx, ny);
                if (!tv) {
                    tiles[{nx, ny}] = 'G';
                    grass_q.emplace_back(nx, ny, cur_time + GRASS_DELAY);
                } else if (tv == 'M' && first_contact_time == -1) {
                    first_contact_time = cur_time;
                }
            }
        }

        while (!mycelium_q.empty() && get<2>(mycelium_q.front()) == cur_time) {
            auto [x, y, t] = mycelium_q.front(); mycelium_q.pop_front();
            for (auto [dx, dy] : EXPAND_DIRS) {
                int nx = x + dx, ny = y + dy;
                if (!get_tile(nx, ny)) {
                    tiles[{nx, ny}] = 'M';
                    mycelium_q.emplace_back(nx, ny, cur_time + MYCELIUM_DELAY);
                    total_mycelium++;
                }
            }
        }
        cur_time++;
    }

    return total_mycelium;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int X_G, Y_G, X_M, Y_M;
        cin >> X_G >> Y_G >> X_M >> Y_M;
        cout << solve(X_G, Y_G, X_M, Y_M) << '\n';
    }
}