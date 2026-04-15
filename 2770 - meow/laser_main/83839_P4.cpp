#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;

void solve(){
    int k, n, m, dy, dx; cin >> k >> n >> m >> dy >> dx;
    map<pi, int> asteroids;
    int curx, cury;
    for (int i = 0; i < k; i++) {
        int x, y; cin >> x >> y;
        if (i == 0){
            curx = x;
            cury = y;
        }
        asteroids.insert({{x,y}, i});
    }
    while (true){
        curx += dx;
        cury += dy;
        if (curx >= n) curx %= n;
        if (cury >= m) cury %= m;
        auto it = asteroids.find({curx, cury});
        if (it != asteroids.end()){
            cout << it->second << "\n";
            return;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while (t--){
        solve();
    }
    return 0;
}