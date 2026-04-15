#include <bits/stdc++.h>
using namespace std;

int idx[1000][1000];

int main() {
    int T;
    cin >> T;
    while (T--) {
        int K, N, M, P, Q;
        cin >> K >> N >> M >> P >> Q;
        
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                idx[i][j] = -1;
        
        int x0, y0;
        cin >> x0 >> y0;
        
        for (int i = 1; i < K; ++i) {
            int x, y;
            cin >> x >> y;
            idx[x][y] = i;
        }
        
        int x = x0, y = y0;
        int ans = -1;
        
        while (true){
            x = (x + Q) % N;
            y = (y + P) % M;
            
            if (idx[x][y] != -1) {
                ans = idx[x][y];
                break;
            }
            if (x == x0 && y == y0) {
                ans = 0;
                break;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}