#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;


const int OFFSET = 8000; 
const int MAX_GRID = 16005;

char grid[MAX_GRID][MAX_GRID];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};



void solve() {
    long long xg, yg, xm, ym;
    cin >>xg >>yg >>xm >> ym;
    

    long long start_mx = xm - xg;
    long long start_my = ym - yg;
    long long D = abs(start_mx)+abs(start_my);
    
    if (D > 4000) {
        cout << 0 << "\n"; 
        return;
    }
    
    int clear_radius = D * 3 + 10;
    int cx = OFFSET, cy = OFFSET;
    int mx = OFFSET+start_mx, my = OFFSET+ start_my;
    
    for(int i = cx - clear_radius; i <= cx + clear_radius; i++) {
        for(int j = cy - clear_radius; j <= cy + clear_radius; j++) {
            if(i >= 0 && i < MAX_GRID && j >= 0 && j < MAX_GRID) {
                grid[i][j] = 0;
            }
        }
    }
    
    queue<pair<int, int>> qG, qM;
    grid[cx][cy] = 1; 
    qG.push({cx, cy});
     
    grid[mx][my] = 2;
    qM.push({mx, my});
    
    long long mycelium_count = 1;
    int tick = 1;

    while (!qM.empty()) {

        if (tick % 2 == 0) {
            int sizeG = qG.size();
            while (sizeG--){
                auto curr = qG.front();
                qG.pop();
                
                for (int i = 0; i < 4; i++){
                    int nx = curr.first + dx[i];
                    int ny = curr.second + dy[i];

                    if (grid[nx][ny] == 0){
                        grid[nx][ny] = 1;
                        qG.push({nx, ny});
                }
            }
        }
    }
        if (tick % 7 == 0) {
            int sizeM = qM.size();
            
            while (sizeM--) {
                auto curr = qM.front();
                qM.pop();
                
                for (int i = 0; i < 4; i++) {
                    int nx = curr.first + dx[i];
                    int ny = curr.second + dy[i];
                    
                    if (grid[nx][ny] == 0) {
                        grid[nx][ny] = 2;
                        qM.push({nx, ny});
                        mycelium_count++;
                    }
                }
            }
        }
    tick++;
    }
    cout << mycelium_count << "\n";
}



int main() {
    int T;
    if (cin >> T){
        while (T--){
            solve();
        }
    }
    return 0;
}