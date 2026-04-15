#include <iostream>
#include <vector>
#include <utility>

using namespace std;

/**
 * Return the total number of tiles mycelium will ever occupy.
 *
 * X_G: x-coordinate of grass starting position
 * Y_G: y-coordinate of grass starting position
 * X_M: x-coordinate of mycelium starting position
 * Y_M: y-coordinate of mycelium starting position
 */
int solve(int X_G, int Y_G, int X_M, int Y_M) {
    int size = 200;
    vector<pair<int, int>> directions = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
    vector<vector<int>> grid(size, vector<int>(size, 0));
    grid[X_G + size / 2][Y_G + size / 2] = 1;
    grid[X_M + size / 2][Y_M + size / 2] = 2;
    int count = 1;
    int tick = 2;
    while (true) {
        vector<vector<int>> new_grid = grid;
        bool changed = false;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (tick % 2 == 0 && grid[i][j] == 1) {
                    for (const pair<int, int>& direction: directions) {
                        int new_i = i + direction.first;
                        int new_j = j + direction.second;
                        if (new_i >= 0 && new_i < size && new_j >= 0 && new_j < size) {
                            if (grid[new_i][new_j] == 0) new_grid[new_i][new_j] = 1;
                        }
                    }
                }
            }
        }
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (tick % 7 == 0 && grid[i][j] == 2) {
                    for (const pair<int, int>& direction: directions) {
                        int new_i = i + direction.first;
                        int new_j = j + direction.second;
                        if (new_i >= 0 && new_i < size && new_j >= 0 && new_j < size) {
                            if (new_grid[new_i][new_j] == 0) {
                                changed = true;
                                new_grid[new_i][new_j] = 2;
                                count++;
                            }
                        }
                    }
                }
            }
        }
        if (tick % 7 == 0 && !changed) {
            break;
        }
        grid = new_grid;
        tick++;
    }
    return count;
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int X_G, Y_G, X_M, Y_M;
        cin >> X_G >> Y_G >> X_M >> Y_M;
        cout << solve(X_G, Y_G, X_M, Y_M) << '\n';
    }
}