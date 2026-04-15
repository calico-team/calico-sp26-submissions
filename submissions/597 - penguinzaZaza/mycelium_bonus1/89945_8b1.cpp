#include <bits/stdc++.h>
using namespace std;

int t, xg, yg, xm, ym;

set<pair<int, int>> gg, mm;

vector<int> ord = {0, 0, 0, 1, 0, 0, 0, 0, 1};
int delx[4] = {0, 0, -1, 1}, dely[4] = {-1, 1, 0, 0};

void solve() {
    cin >> xg >> yg >> xm >> ym;
    gg.emplace(xg, yg); mm.emplace(xm, ym);
    for(int k=0;k<10;k++) {
        for(int e:ord) {
            if(e) {
                vector<pair<int, int>> toins;
                for(auto &pos:mm)
                for(int dir=0;dir<4;dir++) {
                    pair<int, int> npos={pos.first+delx[dir], pos.second + dely[dir]};
                    if(gg.find(npos)==gg.end() && mm.find(npos) == mm.end()) toins.push_back(npos);
                }
                for(auto&e:toins) mm.insert(e);
            } else {
                
                vector<pair<int, int>> toins;
                for(auto &pos:gg)
                for(int dir=0;dir<4;dir++) {
                    pair<int, int> npos={pos.first+delx[dir], pos.second + dely[dir]};
                    if(gg.find(npos)==gg.end() && mm.find(npos) == mm.end()) toins.push_back(npos);
                }
                for(auto&e:toins) gg.insert(e);
            }
        }
    }
    cout << mm.size() << '\n';
    gg.clear(); mm.clear();
}

int main() {
    cin >> t;
    while(t--) solve();
}