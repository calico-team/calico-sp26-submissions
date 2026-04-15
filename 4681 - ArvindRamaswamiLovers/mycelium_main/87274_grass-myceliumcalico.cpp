#include <iostream>
#include <queue>
#include <cmath>

using namespace std;


bool visited[10000][10000];
const int OFFSET = 5000; //negative coordinates

long long dist(long long x1, long long y1, long long x2, long long y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

void solve() {
    long long xg, yg, xm, ym;
    cin >> xg >> yg >> xm >> ym;

    // reset visited array for each test case
    for(int i = 0; i < 10000; i++) 
        for(int j = 0; j < 10000; j++) visited[i][j] = false;

    queue<pair<int, int>> q;
    q.push({(int)xm, (int)ym});
    visited[xm + OFFSET][ym + OFFSET] = true;

    long long count = 0;
    int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};

    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();
        count++;

        for (int i = 0; i < 4; i++) {
            int nx = curr.first + dx[i];
            int ny = curr.second + dy[i];

            if (!visited[nx + OFFSET][ny + OFFSET]) {
                if (7 * dist(nx, ny, xm, ym) < 2 * dist(nx, ny, xg, yg)) {
                    visited[nx + OFFSET][ny + OFFSET] = true;
                    q.push({nx, ny});
                }
            }
        }
    }
    cout << count << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}