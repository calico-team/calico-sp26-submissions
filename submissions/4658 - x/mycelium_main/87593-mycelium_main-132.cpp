#include<bits/stdc++.h>
using namespace std;

const int OFFSET = 5000; 
const int MAX_GRID = 10000;
int grid[MAX_GRID][MAX_GRID]; 

struct Point {
    int x, y;
};

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int main() {
    int T;
    cin >> T;
    while (T--) {
        long long XG, YG, XM, YM;
        cin >> XG >> YG >> XM >> YM;
        int start_mx = OFFSET;
        int start_my = OFFSET;
        int start_gx = OFFSET + (XG - XM);
        int start_gy = OFFSET + (YG - YM);
        queue<Point> q_grass;
        queue<Point> q_mycelium;
        
        q_grass.push({start_gx, start_gy});
        q_mycelium.push({start_mx, start_my});
        
        vector<Point> used_points;
        grid[start_gx][start_gy] = 1;
        grid[start_mx][start_my] = 2;
        used_points.push_back({start_gx, start_gy});
        used_points.push_back({start_mx, start_my});

        long long tick = 0;
        long long total_mycelium = 1;
        bool mycelium_can_grow = true;

        while (mycelium_can_grow) {
            tick++;
            if (tick % 2 == 0) {
                int size = q_grass.size();
                for (int i = 0; i < size; i++) {
                    Point p = q_grass.front();
                    q_grass.pop();
                    
                    for (int d = 0; d < 4; d++) {
                        int nx = p.x + dx[d];
                        int ny = p.y + dy[d];
                        
                        if (grid[nx][ny] == 0) {
                            grid[nx][ny] = 1;
                            q_grass.push({nx, ny});
                            used_points.push_back({nx, ny});
                        }
                    }
                }
            }
            
            if (tick % 7 == 0) {
                int size = q_mycelium.size();
                mycelium_can_grow = false; 
                
                for (int i = 0; i < size; i++) {
                    Point p = q_mycelium.front();
                    q_mycelium.pop();
                    
                    for (int d = 0; d < 4; d++) {
                        int nx = p.x + dx[d];
                        int ny = p.y + dy[d];
                        
                        if (grid[nx][ny] == 0) {
                            grid[nx][ny] = 2;
                            q_mycelium.push({nx, ny});
                            used_points.push_back({nx, ny});
                            total_mycelium++;
                            mycelium_can_grow = true; 
                        }
                    }
                }
            }
            
            if (!mycelium_can_grow) {
                break;
            }
        }

        cout << total_mycelium << "\n";
        for (Point p : used_points) {
            grid[p.x][p.y] = 0;
        }
    }
    return 0;
}