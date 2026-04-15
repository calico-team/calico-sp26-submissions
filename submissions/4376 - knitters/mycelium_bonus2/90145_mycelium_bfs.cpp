/*
 * Naive BFS solution.
 *
 * Simulates the full spreading process on an infinite 2D grid. At each time
 * step, grass expands first (winning ties), then mycelium expands. Both use
 * standard 4-directional BFS with their respective delays. The simulation
 * runs until mycelium can no longer expand, then counts all mycelium tiles.
 *
 * This is the simplest correct solution and serves as the ground-truth
 * reference for faster approaches.
 */
#include <deque>
#include <iostream>
#include <map>
#include <tuple>
#include <vector>

using namespace std;

const int GRASS_DELAY = 2;
const int MYCELIUM_DELAY = 7;
const vector<pair<int,int>> DIRECTIONS = {{0,1},{-1,0},{1,0},{0,-1}};

/**
 * Return the total number of tiles mycelium will ever occupy.
 *
 * X_G: x-coordinate of grass starting position
 * Y_G: y-coordinate of grass starting position
 * X_M: x-coordinate of mycelium starting position
 * Y_M: y-coordinate of mycelium starting position
 */
long long solve(int X_G, int Y_G, int X_M, int Y_M) {
    // Each BFS queue holds (x, y, time) entries in increasing time order.
    deque<tuple<int,int,int>> grass_q, mycelium_q;
    grass_q.push_back({X_G, Y_G, GRASS_DELAY});
    mycelium_q.push_back({X_M, Y_M, MYCELIUM_DELAY});

    // tiles[(x, y)] = 'G' or 'M' once a tile is claimed.
    map<pair<int,int>, char> tiles;
    tiles[{X_G, Y_G}] = 'G';
    tiles[{X_M, Y_M}] = 'M';

    int time = 1;
    while (!mycelium_q.empty()) {
        // Grass expands first at each time step (wins ties).
        while (!grass_q.empty() && get<2>(grass_q.front()) == time) {
            auto [x, y, t] = grass_q.front(); grass_q.pop_front();
            for (auto [dx, dy] : DIRECTIONS) {
                int nx = x + dx, ny = y + dy;
                if (tiles.count({nx, ny}) == 0) {
                    tiles[{nx, ny}] = 'G';
                    grass_q.push_back({nx, ny, time + GRASS_DELAY});
                }
            }
        }
        // Then mycelium expands.
        while (!mycelium_q.empty() && get<2>(mycelium_q.front()) == time) {
            auto [x, y, t] = mycelium_q.front(); mycelium_q.pop_front();
            for (auto [dx, dy] : DIRECTIONS) {
                int nx = x + dx, ny = y + dy;
                if (tiles.count({nx, ny}) == 0) {
                    tiles[{nx, ny}] = 'M';
                    mycelium_q.push_back({nx, ny, time + MYCELIUM_DELAY});
                }
            }
        }
        time++;
    }

    // Count the total number of mycelium tiles.
    long long count = 0;
    for (auto& entry : tiles)
        if (entry.second == 'M') count++;
    return count;
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
