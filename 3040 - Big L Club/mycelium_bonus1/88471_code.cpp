#include <bits/stdc++.h>
using namespace std;
#define int long long

const int C = 210, MXN = 1e3;

vector<pair<int,int>> dirs = {{0,1},{1,0},{-1,0},{0,-1}};

int solve() {
    int x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;

    x1 += C; y1 += C; x2 += C; y2 += C;

    vector<vector<int>> grid(MXN,vector<int>(MXN,0)); // -1 for my, 1 for grass
    int cnt1 = 0, cnt2 = 0;
    set<pair<int,int>> setA, setB;
    setA.insert({x1,y1});
    setB.insert({x2,y2});

    int tick = 0; 
    while(true) {
        tick++;
        if(tick%2==0) {
            set<pair<int,int>> newSetA = setA;
            for(auto [i,j] : setA) {
                for(auto [a,b] : dirs) {
                    int ni = i+a, nj = j+b;
                    if(!setB.count({ni,nj})) newSetA.insert({ni,nj});
                }
            }
            setA = newSetA;
        }

        if(tick%7==0) {
            set<pair<int,int>> newSetB = setB;
            for(auto [i,j] : setB) {
                for(auto [a,b] : dirs) {
                    int ni = i+a, nj = j+b;
                    if(!setA.count({ni,nj})) newSetB.insert({ni,nj});
                }
            }
            if(setB.size()==newSetB.size()) break;
            setB = newSetB;
        }
    }

    return setB.size();
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) {
        cout << solve() << endl;
    }
}