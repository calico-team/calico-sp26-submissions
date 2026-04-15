#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define all(x) x.begin(), x.end()

void solve() {
    int x_g, y_g, x_m, y_m;
    cin >> x_g >> y_g >> x_m >> y_m;

    set<pair<int, int>> grass = {{x_g, y_g}}, mycelium = {{x_m, y_m}}; 
    for (int t = 2; true; t++) {
        if (t % 2 == 0) {
            set<pair<int, int>> new_grass; 
            for (auto [x,y] : grass) {
                if (!mycelium.count({x-1, y})) new_grass.insert({x-1, y});
                if (!mycelium.count({x+1, y})) new_grass.insert({x+1, y});
                if (!mycelium.count({x, y-1})) new_grass.insert({x, y-1});
                if (!mycelium.count({x, y+1})) new_grass.insert({x, y+1});
            }
            for (auto p : new_grass) 
                grass.insert(p);
        }

        if (t % 7 == 0) {
            set<pair<int, int>> new_mycelium; 
            for (auto [x,y] : mycelium) {
                if (!grass.count({x-1, y}) && !mycelium.count({x-1, y})) new_mycelium.insert({x-1, y});
                if (!grass.count({x+1, y}) && !mycelium.count({x+1, y})) new_mycelium.insert({x+1, y});
                if (!grass.count({x, y-1}) && !mycelium.count({x, y-1})) new_mycelium.insert({x, y-1});
                if (!grass.count({x, y+1}) && !mycelium.count({x, y+1})) new_mycelium.insert({x, y+1});
            }
            if (new_mycelium.empty()) break; 
            for (auto p : new_mycelium)
                mycelium.insert(p);
        }
    }

    cout << mycelium.size() << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t; 
    while(t--)
        solve();
}