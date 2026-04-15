#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;
struct Point {
    int x, y;
    bool operator<(const Point& other) const {
        if (x != other.x) return x < other.x;
        return y < other.y;
    }
};
void solve() {
    int xg, yg, xm, ym;
    cin >> xg >> yg >> xm >> ym;
    map<Point, bool> occupied;
    occupied[{xg, yg}] = true;
    occupied[{xm, ym}] = false;

    vector<Point> front_g = {{xg, yg}};
    vector<Point> front_m = {{xm, ym}};
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    int tick = 1;

    while (!front_m.empty()) {
        set<Point> next_gen_g;
        set<Point> next_gen_m;

        // grass expansion
        if (tick % 2 == 0) {
            for (auto& p : front_g) {
                for (int i = 0; i < 4; i++) {
                    Point next = {p.x + dx[i], p.y + dy[i]};
                    if (occupied.find(next) == occupied.end()) {
                        next_gen_g.insert(next);
                    }
                }
            }
        }

        // mycelium expansion
        if (tick % 7 == 0) {
            for (auto& p : front_m) {
                for (int i = 0; i < 4; i++) {
                    Point next = {p.x + dx[i], p.y + dy[i]};
                    if (occupied.find(next) == occupied.end()) {
                        next_gen_m.insert(next);
                    }
                }
            }
        }
        //check for conflicts 
        if (tick % 2 == 0 || tick % 7 == 0) {
            vector<Point> actual_new_g;
            vector<Point> actual_new_m;

            for (const auto& p : next_gen_g) {
                if (occupied.find(p) == occupied.end()) {
                    occupied[p] = true;
                    actual_new_g.push_back(p);
                }
            }

            for (const auto& p : next_gen_m) {
                if (occupied.find(p) == occupied.end()) {
                    occupied[p] = false;
                    actual_new_m.push_back(p);
                }
            }

            if (tick % 2 == 0) front_g = actual_new_g;
            if (tick % 7 == 0) front_m = actual_new_m;
        }
        tick++;
    }

    int total_m = 0;
    for (auto const& [point, is_grass] : occupied) {
        if (!is_grass) total_m++;
    }
    cout << total_m << endl;
}

int main() {
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}