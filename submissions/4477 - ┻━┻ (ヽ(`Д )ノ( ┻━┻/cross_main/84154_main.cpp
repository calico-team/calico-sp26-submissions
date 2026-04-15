#include <bits/stdc++.h>
using namespace std;
const int MM = 1000;
int g[MM][MM], req[MM][MM][5], deg[MM][MM];

vector<vector<int>> st = {
    {4, 5, 3, 1, 2, 4},
    {1, 2, 4, 5, 3, 1},
    {5, 3, 1, 2, 4, 5}
};

vector<vector<int>> dir = {
    {-2, 0},
    {-1, -1}, {-1, 0}, {-1, 1}, 
    {0, -2}, {0, -1}, {0, 0}, {0, 1}, {0, 2}, 
    {1, -1}, {1, 0}, {1, 1}, 
    {2, 0},
};

set<pair<int, pair<int, int>>> pq;

void upd(int r, int c, int col){
    g[r][c] = col;
    // firstly remove r, c from the pq
    pq.erase({deg[r][c], {r, c}});
    for (int j = 0; j < 5; j++) req[r][c][j] = 0;

    for (vector<int> k : dir){
        int rr = r+k[0], cc = c+k[1];
        if (0 <= rr && rr < MM && 0 <= cc && cc < MM && req[rr][cc][col]){
            pq.erase({deg[rr][cc], {rr, cc}});
            req[rr][cc][col] = 0;
            deg[rr][cc]--;
            pq.insert({deg[rr][cc], {rr, cc}});
        }
    }
}

void debug(){
    for (int r = 0; r < MM; r++) for (int c = 0; c < MM; c++) cout << g[r][c] << " \n"[c==MM-1];
}

int T, N, M;

void solve(){
    cin >> N >> M;
    for (int r = 0; r < N; r++) for (int c = 0; c < M; c++) cout << g[r][c] << " \n"[c == M-1];
}

int main(){
    for (int c = 0; c < MM; c++) g[0][c] = (c%5);
    for (int r = 1; r < MM; r++) for (int c = 0; c < MM; c++) g[r][c] = g[r-1][(c-2+MM)%MM];
    cin >> T;
    for (; T > 0; T--) solve();
}