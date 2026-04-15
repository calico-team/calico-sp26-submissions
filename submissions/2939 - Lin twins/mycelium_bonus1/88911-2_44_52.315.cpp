/*
ID: connorl3   
TASK: measurement
LANG: C++17
*/


#include <bits/stdc++.h>

#include <iostream>
#include <array>
#include <fstream>
#include <set>
#include <tuple>
#include <map>
#include <cctype>
#include <unordered_map>
#include <vector>
#include <utility>
#include <random>
#include <cstdlib>
#include <sstream>

using namespace std;

ifstream fin("measurement.in");
ofstream fout("measurement.out");

void solve() {
    int gr, gc, mr, mc;
    cin >> gr >> gc >> mr >> mc;

    map<pair<int,int>, char> grid;
    set<pair<int,int>> myceliumCells;

    grid[{gr, gc}] = 'g';
    grid[{mr, mc}] = 'm';
    myceliumCells.insert({mr, mc});

    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    int t = 1;
    while(true) {
        map<pair<int,int>, char> newCells;

        if (t % 2 == 0) {
            for (auto& [pos, type] : grid) {
                if (type != 'g') continue;
                    int r = pos.first;
                    int c = pos.second;
                for (int d = 0; d < 4; d++) {
                    auto newG = make_pair(r + dx[d], c + dy[d]);
                    if (!grid.count(newG)){
                        newCells[newG] = 'g';
                    }
                }
            }
        }

        if (t % 7 == 0) {
            for (auto& [r, c] : myceliumCells) {
                for (int d = 0; d < 4; d++) {
                    auto newM = make_pair(r + dx[d], c + dy[d]);
                    if (!grid.count(newM) && !newCells.count(newM))
                        newCells[newM] = 'm';
                }
            }
        }

        for (auto& [pos, type] : newCells) {
            grid[pos] = type;
            if (type == 'm') myceliumCells.insert(pos);
        }

        bool done = true;
        for (auto& [r, c] : myceliumCells) {
            for (int d = 0; d < 4; d++) {
                if (!grid.count({r + dx[d], c + dy[d]})) { 
                    done = false; 
                    break; 
                }
            }
            if (!done) break;
        }
        if (done) break;
        t++;
    }

    cout << myceliumCells.size() << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}

