#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdint>
using namespace std;

using i64 = long long;
using str = string;
const i64 ILL = 2167167167167167167;
const int INF = 2100000000;

struct Point {
    int x, y;
};

int main() {
    int t; 
    if (!(cin >> t)) return 0;
    while (t--) {
        i64 xg, yg, xm, ym;
        cin >> xg >> yg >> xm >> ym;

        i64 dist = abs(xg - xm) + abs(yg - ym);
        i64 pad = dist / 2 + 7;
        
        i64 minX = min(xg, xm) - pad;
        i64 maxX = max(xg, xm) + pad;
        i64 minY = min(yg, ym) - pad;
        i64 maxY = max(yg, ym) + pad;

        i64 width = maxX - minX + 1;
        i64 height = maxY - minY + 1;

        vector<uint8_t> grid(width * height, 0);

        auto getIdx = [&](i64 x, i64 y){
            return (x - minX) * height + (y - minY);
        };

        grid[getIdx(xg, yg)] = 1;
        grid[getIdx(xm, ym)] = 2;

        vector<Point> gQ, mQ;
        gQ.push_back({(int)xg, (int)yg});
        mQ.push_back({(int)xm, (int)ym});

        i64 myceliumCount = 1;
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for (i64 tick=1;;tick++){
            if(mQ.empty()) break;

            if(tick % 2 == 0){
                vector<Point> nextGQ;
                for(auto p :gQ){
                    for(int i=0;i<4;i++) {
                        int nx = p.x + dx[i], ny = p.y + dy[i];
                        if(nx >= minX && nx <= maxX && ny >= minY && ny <= maxY) {
                            i64 idx = getIdx(nx, ny);
                            if (grid[idx] == 0) {
                                grid[idx] = 1;
                                nextGQ.push_back({nx, ny});
                            }
                        }
                    }
                }
                gQ = move(nextGQ);
            }

            if(tick % 7 == 0) {
                vector<Point> nextMQ;
                for(auto p : mQ) {
                    for(int i=0;i<4;i++) {
                        int nx = p.x + dx[i], ny = p.y + dy[i];
                        if(nx >= minX && nx <= maxX && ny >= minY && ny <= maxY) {
                            i64 idx = getIdx(nx, ny);
                            if (grid[idx] == 0) {
                                grid[idx] = 2;
                                myceliumCount++;
                                nextMQ.push_back({nx, ny});
                            }
                        }
                    }
                }
                mQ = move(nextMQ);
            }
        }
        cout << myceliumCount << "\n";
    }

    return 0;
}