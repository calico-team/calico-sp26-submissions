#include <bits/stdc++.h>
using namespace std;
void solve() {
    long long K, N, M, P, Q;
    cin >> K >> N>>M>>P>>Q;
    map<pair<long long, long long>, int> asteroids;
    long long startX = 0, startY = 0;
    for (int i = 0; i < K; i++) {
        long long x, y;
        cin >> x >> y;
        asteroids[{x, y}] = i;
        if (i == 0) {
            startX = x;
            startY = y;
        }
    }
    bool hit = false;
    int ans = -1;
    while (!hit) {
        startX = (startX + Q) % N;
        startY = (startY + P) % M;
        auto IteratorOFCORD = asteroids.find({startX, startY});
        if (IteratorOFCORD != asteroids.end()) {
            hit = true;
            ans = IteratorOFCORD->second;
        }
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) { solve(); }
    return 0;
}