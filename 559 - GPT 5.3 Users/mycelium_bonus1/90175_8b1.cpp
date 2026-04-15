/*
 * BFS solution with a pruning optimization.
 *
 * After first contact (the first tick where some grass tile becomes adjacent
 * to mycelium), the grass-mycelium boundary only tightens around mycelium.
 * We prune grass tiles with no 8-neighboring mycelium, as they are too far
 * away to contribute to the boundary and can be safely ignored.
 *
 * This significantly saves time by avoiding expansion into irrelevant
 * directions that will never come into contact with mycelium.
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

/**
 * Return the total number of tiles mycelium will ever occupy.
 *
 * X_G: x-coordinate of grass starting position
 * Y_G: y-coordinate of grass starting position
 * X_M: x-coordinate of mycelium starting position
 * Y_M: y-coordinate of mycelium starting position
 */
ll solve(int X_G, int Y_G, int X_M, int Y_M) {
    deque<tuple<int,int,int>> grass_q, mycelium_q;
    grass_q.emplace_back(X_G, Y_G, GRASS_DELAY);
    mycelium_q.emplace_back(X_M, Y_M, MYCELIUM_DELAY);

    unordered_map<pair<int,int>, char, PairHash> tiles;
    tiles[{X_G, Y_G}] = 'G';
    tiles[{X_M, Y_M}] = 'M';

    // Count total mycelium as we go so we can answer faster at the end.
    ll total_mycelium = 1;

    // Track time of first contact. Expand freely before. Begin pruning after.
    int first_contact_time = -1;

    int time = 1;
    while (!mycelium_q.empty()) {
        // Grass expands first at each time step (wins ties).
        while (!grass_q.empty() && get<2>(grass_q.front()) == time) {
            auto [x, y, t] = grass_q.front(); grass_q.pop_front();

            // After first contact, prune tiles with no 8-neighboring mycelium.
            if (first_contact_time != -1 && time > first_contact_time) {
                bool near_mycelium = false;
                for (auto [dx, dy] : EIGHT_DIRS) {
                    auto it = tiles.find({x+dx, y+dy});
                    if (it != tiles.end() && it->second == 'M') { near_mycelium = true; break; }
                }
                if (!near_mycelium) continue;
            }

            for (auto [dx, dy] : EXPAND_DIRS) {
                int nx = x + dx, ny = y + dy;
                if (!tiles.count({nx, ny})) {
                    tiles[{nx, ny}] = 'G';
                    grass_q.emplace_back(nx, ny, time + GRASS_DELAY);
                }
                // Update time of first contact when we find adjacent mycelium.
                else if (tiles[{nx, ny}] == 'M' && first_contact_time == -1) {
                    first_contact_time = time;
                }
            }
        }

        // Then mycelium expands.
        while (!mycelium_q.empty() && get<2>(mycelium_q.front()) == time) {
            auto [x, y, t] = mycelium_q.front(); mycelium_q.pop_front();
            for (auto [dx, dy] : EXPAND_DIRS) {
                int nx = x + dx, ny = y + dy;
                if (!tiles.count({nx, ny})) {
                    tiles[{nx, ny}] = 'M';
                    mycelium_q.emplace_back(nx, ny, time + MYCELIUM_DELAY);
                    total_mycelium++;
                }
            }
        }
        time++;
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