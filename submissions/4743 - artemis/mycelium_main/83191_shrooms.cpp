#include <bits/stdc++.h>
using namespace std;

struct Cell {
    int row, col;
    bool operator==(const Cell& other) const {
        return row == other.row && col == other.col;
    }
};

struct CellHash {
    size_t operator()(const Cell& cell) const {
        return ((uint64_t)(uint32_t)cell.row << 32) ^ (uint32_t)cell.col;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin >> tests;

    int rowStep[4] = {1, -1, 0, 0};
    int colStep[4] = {0, 0, 1, -1};

    while (tests--) {
        int grassRow, grassCol, shroomRow, shroomCol;
        cin >> grassRow >> grassCol >> shroomRow >> shroomCol;

        unordered_set<Cell, CellHash> grass, shrooms, grassEdge, shroomEdge;

        Cell grassStart = {grassRow, grassCol};
        Cell shroomStart = {shroomRow, shroomCol};

        grass.insert(grassStart);
        shrooms.insert(shroomStart);
        grassEdge.insert(grassStart);
        shroomEdge.insert(shroomStart);

        int tickCount = 0;
        int shroomsDead = 0;

        while (true) {
            tickCount++;

            unordered_set<Cell, CellHash> newGrass, newShrooms;

            if (tickCount % 2 == 0) {
                for (auto &grassCell : grassEdge) {
                    for (int dir = 0; dir < 4; dir++) {
                        Cell nextCell = {
                            grassCell.row + rowStep[dir],
                            grassCell.col + colStep[dir]
                        };
                        if (!grass.count(nextCell) && !shrooms.count(nextCell)) {
                            newGrass.insert(nextCell);
                        }
                    }
                }
            }

            if (tickCount % 7 == 0) {
                for (auto &shroomCell : shroomEdge) {
                    for (int dir = 0; dir < 4; dir++) {
                        Cell nextCell = {
                            shroomCell.row + rowStep[dir],
                            shroomCell.col + colStep[dir]
                        };
                        if (!grass.count(nextCell) && !shrooms.count(nextCell)) {
                            newShrooms.insert(nextCell);
                        }
                    }
                }
            }

            for (auto &grassCell : newGrass) {
                if (newShrooms.count(grassCell)) {
                    newShrooms.erase(grassCell);
                }
            }

            if (tickCount % 2 == 0) {
                grassEdge.clear();
                for (auto &grassCell : newGrass) {
                    grass.insert(grassCell);
                    grassEdge.insert(grassCell);
                }
            }

            if (tickCount % 7 == 0) {
                shroomEdge.clear();
                for (auto &shroomCell : newShrooms) {
                    shrooms.insert(shroomCell);
                    shroomEdge.insert(shroomCell);
                }

                if (shroomEdge.empty()) {
                    shroomsDead++;
                    if (shroomsDead >= 1) break;
                } else {
                    shroomsDead = 0;
                }
            }
        }

        cout << shrooms.size() << '\n';
    }

    return 0;
}