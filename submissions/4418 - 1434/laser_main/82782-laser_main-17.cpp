#include <bits/stdc++.h>
using namespace std;

int isasteroid[1000][1000];

int main() {
    int t;
    cin >> t;
    while (t--) {
        memset(isasteroid, 0, sizeof(isasteroid));
        int k, n, m, p, q;
        cin >> k >> n >> m >> p >> q;
        vector <pair <int, int>> asteroids;
        for (int i = 0; i < k; i++) {
            int x, y;
            cin >> x >> y;
            asteroids.push_back({x, y});
            isasteroid[x][y] = i + 1;
        }
        int cx = asteroids[0].first, cy = asteroids[0].second;
        while (true) {
            cx = (cx + q) % n;
            cy = (cy + p) % m;
            if (isasteroid[cx][cy]) {
                cout << isasteroid[cx][cy] - 1 << endl;
                break;
            }
        }
    }
}