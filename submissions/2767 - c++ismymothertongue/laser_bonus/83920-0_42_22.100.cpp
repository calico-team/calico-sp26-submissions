#include <iostream>
#include <vector>

using namespace std;

typedef __int128_t int128;

long long extended_gcd(long long a, long long b, long long &x, long long &y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    long long x1, y1;
    long long gcd = extended_gcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return gcd;
}

void solve() {
    int K;
    long long N, M, P, Q;
    if (!(cin >> K >> N >> M >> P >> Q)) return;

    vector<pair<long long, long long>> asteroids(K);
    for (int i = 0; i < K; i++) {
        cin >> asteroids[i].first >> asteroids[i].second;
    }

    long long startX = asteroids[0].first;
    long long startY = asteroids[0].second;

    int firstHitIndex = -1;
    int128 minSteps = -1;

    for (int i = 0; i < K; i++) {
        long long targetX = asteroids[i].first;
        long long targetY = asteroids[i].second;

        long long targetDx = (targetX - startX % N + N) % N;
        long long targetDy = (targetY - startY % M + M) % M;

        long long xInv, yInv;
        long long gcdQ = extended_gcd(Q, N, xInv, yInv);
        if (targetDx % gcdQ != 0) continue;
        long long stepX = (int128)(targetDx / gcdQ) * (xInv % (N / gcdQ)) % (N / gcdQ);
        if (stepX < 0) stepX += (N / gcdQ);

        long long xInvP, yInvP;
        long long gcdP = extended_gcd(P, M, xInvP, yInvP);
        if (targetDy % gcdP != 0) continue;
        long long stepY = (int128)(targetDy / gcdP) * (xInvP % (M / gcdP)) % (M / gcdP);
        if (stepY < 0) stepY += (M / gcdP);

        long long modX = N / gcdQ;
        long long modY = M / gcdP;

        long long xCrt, yCrt;
        long long gcdCrt = extended_gcd(modX, modY, xCrt, yCrt);
        if ((stepY - stepX) % gcdCrt != 0) continue;

        int128 combinedMod = (int128)modX * (modY / gcdCrt);
        int128 currentSteps = (int128)stepX + (int128)modX * (((int128)(stepY - stepX) / gcdCrt * xCrt) % (modY / gcdCrt));
        currentSteps %= combinedMod;
        if (currentSteps < 0) currentSteps += combinedMod;

        if (currentSteps == 0 && i == 0) currentSteps = combinedMod;

        if (currentSteps > 0) {
            if (minSteps == -1 || currentSteps < minSteps) {
                minSteps = currentSteps;
                firstHitIndex = i;
            }
        }
    }

    cout << firstHitIndex << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (cin >> T) {
        while (T--) {
            solve();
        }
    }
    return 0;
}