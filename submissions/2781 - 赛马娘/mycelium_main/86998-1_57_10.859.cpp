#include <bits/stdc++.h>
using namespace std;

int solve(int xg, int yg, int xm, int ym) {
    map<pair<int,int>,int> grid;
    grid[{xg, yg}] = 1;
    grid[{xm, ym}] = 2;

    for (int i = -50; i < 50; i++) {
        for (int j = -50; j < 50; j++) {
            if (grid[{i,j}] == 1 || grid[{i,j}] == 2) continue;
            grid[{i,j}] = 0;
        }
    }

    // 0 is empty, 1 is grass, 2 is mycelium
    int tick = 1;
    while (true) {
        // 3 is transitioning
        if (tick % 2 == 0) {
            for (int i = -50; i < 50; i++) {
                for (int j = -50; j < 50; j++) {
                    if (grid[{i,j}] == 0) {
                        if (grid[{i+1,j}] == 1) grid[{i,j}] = 3;
                        if (grid[{i-1,j}] == 1) grid[{i,j}] = 3;
                        if (grid[{i,j+1}] == 1) grid[{i,j}] = 3;
                        if (grid[{i,j-1}] == 1) grid[{i,j}] = 3;
                    }
                }
            }
            for (int i = -50; i < 50; i++) {
                for (int j = -50; j < 50; j++) {
                    if (grid[{i,j}] == 3) grid[{i,j}] = 1;
                }
            }
        }

        if (tick % 7 == 0) {
            bool turned = false;
            for (int i = -50; i < 50; i++) {
                for (int j = -50; j < 50; j++) {
                    if (grid[{i,j}] == 0) {
                        if (grid[{i+1,j}] == 2) grid[{i,j}] = 3;
                        if (grid[{i-1,j}] == 2) grid[{i,j}] = 3;
                        if (grid[{i,j+1}] == 2) grid[{i,j}] = 3;
                        if (grid[{i,j-1}] == 2) grid[{i,j}] = 3;
                    }
                }
            }
            for (int i = -50; i < 50; i++) {
                for (int j = -50; j < 50; j++) {
                    if (grid[{i,j}] == 3) {
                        grid[{i,j}] = 2;
                        turned = true;
                    }
                }
            }
            if (!turned) {
                break;
            }
        }

        // cout << "tick: " << tick << "\n";
        // for (int j = 10; j >= -10; j--) {
        //     for (int i = -10; i <= 10; i++) {
        //         cout << grid[{i,j}];
        //     }
        //     cout << "\n";
        // }
        // cout << "------------------------------------\n";
        // if (tick == 10) break;
        tick++;
    }

    int count = 0;
    for (int i = -50; i < 50; i++) {
        for (int j = -50; j < 50; j++) {
            if (grid[{i,j}] == 2) {
                count++;
            }
        }
    }
    cout << count << "\n";
    return 0;
}

int main() {
	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		int xg, yg, xm, ym;
        cin >> xg >> yg >> xm >> ym;
	    solve(xg, yg, xm, ym);
	}
}
