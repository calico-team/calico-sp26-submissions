#include <iostream>
#include <map>
#include <vector>
#include <utility>
using namespace std;

typedef long long ll;

int main() {
    int T;
    cin >> T;
    while (T--) {
        ll Xg, Yg, Xm, Ym;
        cin >> Xg >> Yg >> Xm >> Ym;

        map<pair<ll, ll>, int> grid;
        grid[{Xg, Yg}] = 1;
        grid[{Xm, Ym}] = 2;

        ll tick = 0;
        ll prev_m_count = -1;
        ll m_count = 1; 
        
        vector<pair<int, int>> dirs = { {-1,0}, {1,0}, {0,-1}, {0,1} };

        while (true) {
            tick++;
            
            if (tick % 2 == 0) {
                vector<pair<ll, ll>> new_grass;
                
                for (auto& entry : grid) {
                    if (entry.second == 1) {
                        ll x = entry.first.first;
                        ll y = entry.first.second;
                        for (auto& d : dirs) {
                            ll nx = x + d.first;
                            ll ny = y + d.second;
                            
                            if (grid.find({ nx, ny }) == grid.end()) {
                                new_grass.emplace_back(nx, ny);
                            }
                        }
                    }
                }
                
                for (auto& p : new_grass) {
                    if (grid.find(p) == grid.end()) {
                        grid[p] = 1;
                    }
                }
            }

            if (tick % 7 == 0) {
                vector<pair<ll, ll>> new_m;
                
                for (auto& entry : grid) {
                    if (entry.second == 2) {
                        ll x = entry.first.first;
                        ll y = entry.first.second;
                        for (auto& d : dirs) {
                            ll nx = x + d.first;
                            ll ny = y + d.second;
                            
                            if (grid.find({ nx, ny }) == grid.end()) {
                                new_m.emplace_back(nx, ny);
                            }
                        }
                    }
                }
                
                for (auto& p : new_m) {
                    if (grid.find(p) == grid.end()) {
                        grid[p] = 2;
                    }
                }

                prev_m_count = m_count;
                m_count = 0;
                for (auto& entry : grid) {
                    if (entry.second == 2) {
                        m_count++;
                    }
                }
                
                if (m_count == prev_m_count) {
                    break;
                }
            }
        }

        cout << m_count << endl;
    }
    return 0;
}