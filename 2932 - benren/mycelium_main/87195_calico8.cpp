#include <bits/stdc++.h>
using namespace std;

const int RANGE = 81;
const int OFFSET = RANGE / 2;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int main() {
	// ifstream cin("input");

	int t;
	cin >> t;
	while (t--) {
		int xg, yg, xm, ym;
		cin >> xg >> yg >> xm >> ym;
		xg += OFFSET;
		yg += OFFSET;
		xm += OFFSET;
		ym += OFFSET;
		
		int grid[RANGE][RANGE] = {};
		
		queue<array<int, 3>> grass;
		grass.push({xg, yg, 0});
		
		int total = 0;
		while (!grass.empty()) {
		    array<int, 3> node = grass.front();
		    grass.pop();
		    
		    if (grid[node[0]][node[1]] == 1) continue;
		    grid[node[0]][node[1]] = 1;
		    total++;
		    
		    for (int i = 0; i < 4; i++) {
		        int nx = node[0] + dx[i];
		        int ny = node[1] + dy[i];
		        int nt = node[2] + 2;
		        // check if valid
		        if (7 * (abs(xm - nx) + abs(ym - ny)) < nt) continue;
		        if (nx < 0 || nx >= RANGE || ny < 0 || ny >= RANGE) continue;
		        
		        grass.push({nx, ny, nt});
		    }
		}
	    cout << RANGE * RANGE - total << endl;
	}
}