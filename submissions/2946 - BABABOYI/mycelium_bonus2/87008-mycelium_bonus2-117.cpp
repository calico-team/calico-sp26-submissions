#include <bits/stdc++.h>
using namespace std;

inline int get_state(long long idx, const vector<uint8_t>& g){
    return (g[idx >> 2] >> ((idx & 3) << 1)) & 3;
}


inline void set_state(long long idx, vector<uint8_t>& g, int state) {
    int shift = (idx & 3) << 1;
    g[idx >> 2] = (g[idx >> 2] & ~(3 << shift)) | (state << shift);
}



void solve() {
    long long xg, yg, xm, ym;
    cin >> xg >> yg >> xm >> ym;
    
    long long dx = xm - xg;
    long long dy = ym - yg;
    long long D = abs(dx) + abs(dy);

    if (D > 20000) {
        cout << 0 << "\n";
        return;
    }
    
 
    long long margin = (D / 2) + 10;
    long long min_x = min(0LL, dx) - margin;
    long long max_x = max(0LL, dx) + margin;
    long long min_y = min(0LL, dy) - margin;
    long long max_y = max(0LL, dy) + margin;
    
    
    int width = max_x - min_x + 1;
    int height = max_y - min_y + 1;
    
    
    long long total_cells = (long long)width * height;
    vector<uint8_t> grid((total_cells + 3) / 4, 0);


    int cx = 0 - min_x;
    int cy = 0 - min_y;
    int mx = dx - min_x;
    int my = dy - min_y;
    
    
    queue<pair<int, int>> qG, qM;

    long long idxG = (long long)cx * height + cy;
    set_state(idxG, grid, 1);
    qG.push({cx, cy});
    
    
    long long idxM = (long long)mx * height + my;
    set_state(idxM, grid, 2);
    qM.push({mx, my});
    
    
    long long mycelium_count = 1;
    int tick = 1;
    
    
    int dirX[] = {-1, 1, 0, 0};
    int dirY[] = {0, 0, -1, 1};
    
    
    while (!qM.empty()) {
        
        if (tick % 2 == 0) {
            int sizeG = qG.size();
            while (sizeG--){
                int curr_x = qG.front().first;
                int curr_y = qG.front().second;
                qG.pop();
                
                for (int i = 0; i < 4; i++) {
                    int nx = curr_x + dirX[i];
                    int ny = curr_y + dirY[i];
                    
                    if (nx >= 0 && nx < width && ny >= 0 && ny < height){
                        long long idx = (long long)nx * height + ny;
                        if (get_state(idx, grid) == 0){
                            set_state(idx, grid, 1);
                            qG.push({nx, ny});
                        }
                    }
            }
        }
    }
        
        if (tick % 7 == 0) {
            int sizeM = qM.size();
            while (sizeM--) {
                int curr_x = qM.front().first;
                int curr_y = qM.front().second;
                qM.pop();
                
                for (int i = 0; i < 4; i++){
                    int nx = curr_x + dirX[i];
                    int ny = curr_y + dirY[i];
                    
                    if (nx >= 0 && nx < width && ny >= 0 && ny < height){
                        long long idx = (long long)nx * height + ny;
                        if (get_state(idx, grid) == 0){
                            set_state(idx, grid, 2);
                            qM.push({nx, ny});
                            mycelium_count++;
                        }
                    }
                }
            }
        }
        tick++;
    }
cout << mycelium_count << "\n";
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    if (cin >> T){
        while (T--){
            solve();
        }
    }
    return 0;
}