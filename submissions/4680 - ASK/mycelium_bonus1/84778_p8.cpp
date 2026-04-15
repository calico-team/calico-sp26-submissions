#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin>> T;

    while (T--) {
        int xG,yG,xM,yM; cin>>xG>>yG >>xM>>yM; //xg lets go

        int numM=0;
        bool done=false;

        for (int margin = 20; !done; margin *= 2) {
            int minX = min(xG,xM) - margin, maxX = max(xG,xM) + margin;
            int minY = min(yG,yM) - margin, maxY = max(yG,yM) + margin;
            int numR = maxX-minX+1, numC = maxY-minY+1;

            vector<vector<int>> grid(numR,vector<int>(numC));
            vector<pair<int,int>> grass,myc;

            int gR = xG - minX,gC = yG - minY;
            int mR = xM - minX,mC= yM - minY;

            //0 = none, 1= grass, 2= mycelion
            grid[gR][gC] = 1;
            grid[mR][mC] = 2;
            grass.push_back({gR,gC});
            myc.push_back({mR,mC});

            int total = 1;
            bool hit = false;

            for (int tick = 1; ; tick++) {
                vector<pair<int,int>> newGrass, newMyc;
                vector<vector<char>> mark_grass(numR,vector<char>(numC)), mark_myc(numR,vector<char>(numC));

                if (tick%2 == 0) {
                    for (int i = 0; i < (int)grass.size(); i++) {
                        int r = grass[i].first, c = grass[i].second;
                        if (r && !grid[r-1][c] &&!mark_grass[r-1][c]) {
                            mark_grass[r-1][c] = 1;
                            newGrass.push_back({r-1,c});
                        }
                        if (r+1 < numR && !grid[r+1][c] &&!mark_grass[r+1][c]) {
                            mark_grass[r+1][c] = 1;
                            newGrass.push_back({r+1,c});
                        }
                        if (c && !grid[r][c-1] &&!mark_grass[r][c-1]) {
                            mark_grass[r][c-1] = 1;
                            newGrass.push_back({r,c-1});
                        }
                        if (c+1 < numC && !grid[r][c+1] &&!mark_grass[r][c+1]) {
                            mark_grass[r][c+1] = 1;
                            newGrass.push_back({r,c+1});
                        }
                    }
                }

                if (tick%7 == 0){
                    for (int i = 0; i < (int)myc.size(); i++) {
                        int r = myc[i].first, c = myc[i].second;
                        if (r && !grid[r-1][c] &&!mark_myc[r-1][c]) {
                            mark_myc[r-1][c] = 1;
                            newMyc.push_back({r-1,c});
                        }
                        if (r+1 < numR && !grid[r+1][c] &&!mark_myc[r+1][c]) {
                            mark_myc[r+1][c] = 1;
                            newMyc.push_back({r+1,c});
                        }
                        if (c && !grid[r][c-1] &&!mark_myc[r][c-1]) {
                            mark_myc[r][c-1] = 1;
                            newMyc.push_back({r,c-1});
                        }
                        if (c+1 < numC && !grid[r][c+1] &&!mark_myc[r][c+1]) {
                            mark_myc[r][c+1] = 1;
                            newMyc.push_back({r,c+1});
                        }
                    }
                }

                for (auto &p: newGrass) {
                    int r = p.first, c = p.second;
                    if (!grid[r][c]) {
                        grid[r][c] = 1;
                        grass.push_back({r,c});
                    }
                }

                int grew = 0;
                for (auto &p: newMyc) {
                    int r = p.first, c = p.second;
                    if (mark_grass[r][c]) continue;
                    if (!grid[r][c]) {
                        grid[r][c] = 2;
                        myc.push_back({r,c});
                        total++;
                        grew++;
                        if (r == 0 || r==numR-1 || c==0 || c==numC-1){
                            hit = true;
                        }
                    }
                }

                if (tick % 7 == 0 && !grew) {
                    numM = total;
                    if (!hit) done = true;
                    break;
                }
            }
        }

        cout << numM << '\n';
    }
}
