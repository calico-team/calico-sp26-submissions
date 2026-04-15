#include <bits/stdc++.h>
using namespace std;
int main() {
    int T; 
    cin >> T;
    while (T--) {
        int XG, YG, XM, YM; 
        cin>>XG>>YG>>XM>>YM;
        int dx=XM-XG, dy =YM-YG;
        set<pair<int,int>> myc, grs;
        myc.insert({dx, dy});
        grs.insert({0, 0});
        for (int t = 1; t <= 10000; t++) {
            set<pair<int,int>> ng, nm;
            if (t%2==0) {
                for (auto [x,y]:grs) {
                    for (auto [nx,ny]:{make_pair(x+1,y), {x-1,y}, {x,y+1}, {x,y-1}}) {
                        if (!myc.count({nx,ny})&&!grs.count({nx,ny})) ng.insert({nx,ny});
                    }
                }
                for (auto p : ng) grs.insert(p);
            }
            if (t % 7 == 0) {
                for (auto [x,y] : myc) {
                    for (auto [nx,ny] : {make_pair(x+1,y), {x-1,y}, {x,y+1}, {x,y-1}}) {
                        if (!grs.count({nx,ny}) && !myc.count({nx,ny})) nm.insert({nx,ny});
                    }
                }
                for (auto p:nm) myc.insert(p);
            }
            if (ng.empty()&&nm.empty()) break;
        }
        cout<<myc.size()<<endl;
    }
    return 0;
}