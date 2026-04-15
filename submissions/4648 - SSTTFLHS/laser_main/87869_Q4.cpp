#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int K, N, M, P, Q;
    if (!(cin >> K >> N >> M >> P >> Q)) return;

    vector<vector<int>> grid(N, vector<int>(M, -1));
    int startX, startY;

    for (int i = 0; i < K; ++i) {
        int x, y;
        cin >> x >> y;
        if (i == 0) {
            startX = x;
            startY = y;
        }
        grid[x][y] = i;
    }

    int currX = startX;
    int currY = startY;

    while (true) {
        currX = (currX + Q) % N;
        currY = (currY + P) % M;

        if (grid[currX][currY] != -1) {
            cout << grid[currX][currY] << endl;
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}