#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, M, K;
    if (!(cin >> N >> M >> K)) return;
    vector<string> g(N);
    for (int i = 0; i < N; i++) cin >> g[i];


    vector<vector<int>> col_pref(N + 1, vector<int>(M, 0));
    for (int j = 0; j < M; j++) {
        for (int i = 0; i < N; i++) {
            col_pref[i + 1][j] = col_pref[i][j] + (g[i][j] == '-' ? 1 : 0);
        }
    }

    int best_D = N + M;
    int res_i = 0, res_i2 = N - 1, res_j = 0, res_j2 = M - 1;

    for (int i = 0; i < N; i++) {

        for (int i2 = i; i2 < N; i2++) {
            int h = i2 - i + 1;

            if (h - 1 >= best_D) break;

 
            int left = 0, current_seats = 0;
            for (int right = 0; right < M; right++) {
       
                current_seats += (col_pref[i2 + 1][right] - col_pref[i][right]);
                
                while (current_seats >= K) {
                    int w = right - left + 1;
                    int dist = (h - 1) + (w - 1);
                    if (dist < best_D) {
                        best_D = dist;
                        res_i = i; res_i2 = i2;
                        res_j = left; res_j2 = right;
                    }
    
                    current_seats -= (col_pref[i2 + 1][left] - col_pref[i][left]);
                    left++;
                }
            }
        }
    }

   
    int count = 0;
    for (int i = res_i; i <= res_i2; i++) {
        for (int j = res_j; j <= res_j2; j++) {
            if (g[i][j] == '-' && count < K) {
                cout << i << " " << j << "\n";
                count++;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    if (cin >> T) {
        while (T--) solve();
    }
    return 0;
}