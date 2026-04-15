

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int firstAsteroidHit(long long worldX, long long worldY, long long slopeX, long long slopeY, vector<vector<int>> asteroids) {
    long long posX = asteroids[0][0], posY = asteroids[0][1];
    while (true) {
        posX += slopeX;
        posY += slopeY;
        if (posX >= worldX) {
            posX -= (posX / worldX) * worldX;
        }
        if (posY >= worldY) {
            posY -= (posY / worldY) * worldY;
        }
        // cout << posX << " " << posY << " " << worldX << " " << worldY << endl;
        for (long long i = 0; i < asteroids.size(); i++) {
            if (asteroids[i][0] == posX && asteroids[i][1] == posY) {
                return i;
            }
        }
    }
}

int main() {
    long long tests = 0;
    cin >> tests;
    for (long long i = 0; i < tests; i++) {
        long long k, n, m, p, q;
        vector<vector<int>> asteroids;
        cin >> k >> n >> m >> p >> q;
        for (long long j = 0; j < k; j++) {
            long long x, y;
            vector<int> asteroid;
            cin >> x >> y;
            asteroid.push_back(x);
            asteroid.push_back(y);
            asteroids.push_back(asteroid);
        }
        long long hitIdx = firstAsteroidHit(n, m, p, q, asteroids);
        cout << hitIdx << endl;
    }

    return 0;
}