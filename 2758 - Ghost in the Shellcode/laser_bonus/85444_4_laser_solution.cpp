#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void gngTsIsTry3HopefullyIllGetItRightThisTimeItsOnlyOnThePointsRight() {
    int K;
    ll N, M, P, Q;
    cin >> K >> N >> M >> P >> Q;
    map<pair<ll, ll>, int> assmap;
    ll begX, begY;

    for(int i = 0; i < K; i++) {
        ll x, y;
        cin >> x >> y;
        if(i == 0) {
            begX = x;
            begY = y;
        }
        if(assmap.find({x, y}) == assmap.end()) {
            assmap[{x, y}] = i;
        }
    }

    ll currX = begX;
    ll currY = begY;
    for(ll step = 0; step < N * M; step++) {
        currX = (currX + Q) % N;
        currY = (currY + P) % M;
        if(assmap.count({currX, currY})) {
            cout << assmap[{currX, currY}] << endl;
            return;
        }
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) gngTsIsTry3HopefullyIllGetItRightThisTimeItsOnlyOnThePointsRight();
    return 0;
}