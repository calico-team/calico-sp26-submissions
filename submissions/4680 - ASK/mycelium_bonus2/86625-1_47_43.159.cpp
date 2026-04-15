#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin>> T;

    while (T--) {
        int xG,yG,xM,yM; cin>>xG>>yG>>xM>>yM;

        int dist = abs(xG-xM) + abs(yG-yM);
        int minX = xM-dist, maxX = xM+dist;
        int minY = yM-dist, maxY = yM+dist;
        int numR = maxX-minX+1, numC = maxY-minY+1;

        vector<unsigned char> grid(numR*numC);
        vector<unsigned char> markGrass(numR*numC), markMyc(numR*numC);
        vector<pair<int,int>> grass,myc,newGrass,newMyc,candGrass,candMyc;

        int gR = xG-minX, gC = yG-minY;
        int mR = xM-minX, mC = yM-minY;

        grid[gR*numC + gC] = 1;
        grid[mR*numC + mC] = 2;
        grass.push_back({gR,gC});
        myc.push_back({mR,mC});

        int numM = 1;
        int grassTick = 2, mycTick = 7;

        while (!myc.empty()) {
            int tick = min(grassTick,mycTick);
            bool growGrass = tick == grassTick;
            bool growMyc = tick == mycTick;

            candGrass.clear();
            candMyc.clear();
            newGrass.clear();
            newMyc.clear();

            if (growGrass) {
                for (int i = 0; i < (int)grass.size(); i++) {
                    int r = grass[i].first, c = grass[i].second;
                    if (r) {
                        int id = (r-1)*numC + c;
                        if (!grid[id] && !markGrass[id]) {
                            markGrass[id] = 1;
                            candGrass.push_back({r-1,c});
                        }
                    }
                    if (r+1 < numR) {
                        int id = (r+1)*numC + c;
                        if (!grid[id] && !markGrass[id]) {
                            markGrass[id] = 1;
                            candGrass.push_back({r+1,c});
                        }
                    }
                    if (c) {
                        int id = r*numC + c-1;
                        if (!grid[id] && !markGrass[id]) {
                            markGrass[id] = 1;
                            candGrass.push_back({r,c-1});
                        }
                    }
                    if (c+1 < numC) {
                        int id = r*numC + c+1;
                        if (!grid[id] && !markGrass[id]) {
                            markGrass[id] = 1;
                            candGrass.push_back({r,c+1});
                        }
                    }
                }
            }

            if (growMyc) {
                for (int i = 0; i < (int)myc.size(); i++) {
                    int r = myc[i].first, c = myc[i].second;
                    if (r) {
                        int id = (r-1)*numC + c;
                        if (!grid[id] && !markMyc[id]) {
                            markMyc[id] = 1;
                            candMyc.push_back({r-1,c});
                        }
                    }
                    if (r+1 < numR) {
                        int id = (r+1)*numC + c;
                        if (!grid[id] && !markMyc[id]) {
                            markMyc[id] = 1;
                            candMyc.push_back({r+1,c});
                        }
                    }
                    if (c) {
                        int id = r*numC + c-1;
                        if (!grid[id] && !markMyc[id]) {
                            markMyc[id] = 1;
                            candMyc.push_back({r,c-1});
                        }
                    }
                    if (c+1 < numC) {
                        int id = r*numC + c+1;
                        if (!grid[id] && !markMyc[id]) {
                            markMyc[id] = 1;
                            candMyc.push_back({r,c+1});
                        }
                    }
                }
            }

            if (growGrass) {
                for (int i = 0; i < (int)candGrass.size(); i++) {
                    int r = candGrass[i].first, c = candGrass[i].second;
                    int id = r*numC + c;
                    if (!grid[id]) {
                        grid[id] = 1;
                        newGrass.push_back({r,c});
                    }
                    markGrass[id] = 0;
                }

                grass.swap(newGrass);
                grassTick += 2;
            }

            if (growMyc) {
                for (int i = 0; i < (int)candMyc.size(); i++) {
                    int r = candMyc[i].first, c = candMyc[i].second;
                    int id = r*numC + c;
                    if (!grid[id]) {
                        grid[id] = 2;
                        newMyc.push_back({r,c});
                        numM++;
                    }
                    markMyc[id] = 0;
                }

                myc.swap(newMyc);
                mycTick += 7;
            }
        }

        cout << numM << '\n';
    }
}
