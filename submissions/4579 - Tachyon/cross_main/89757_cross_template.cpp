#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

/*
 * Create an N x M grid such that every valid cross contains 0-4 exactly once.
 * 
 * N: number of rows in the grid
 * M: number of columns in the grid
 */
vector<vector<int>> solve(int N, int M) {
    vector<vector<int>> grid(N, vector<int>(M, -1));
    
    for(int row = 1; row < N-1; row++){
        for(int col = 1; col < M-1; col++){
            unordered_set<int> seen;
            
            if(grid[row-1][col]!=-1){
                seen.insert(grid[row-1][col]);
            }
            if(grid[row][col-1]!=-1){
                seen.insert(grid[row][col-1]);
            }
            if(grid[row+1][col]!=-1){
                seen.insert(grid[row+1][col]);
            }
            if(grid[row][col+1]!=-1){
                seen.insert(grid[row][col+1]);
            }
            if(grid[row][col]!=-1){
                seen.insert(grid[row][col]);
            }
            /////////////////////////////////
            if(grid[row-1][col]==-1){
                for(int i = 0; i<=4; i++){
                    if(!seen.count(i)){
                        grid[row-1][col] = i;
                        seen.insert(i);
                        break;
                    }
                }
            }
            if(grid[row][col-1]==-1){
                for(int i = 0; i<=4; i++){
                    if(!seen.count(i)){
                        grid[row][col-1] = i;
                        seen.insert(i);
                        break;
                    }
                }
            }
            if(grid[row+1][col]==-1){
                for(int i = 0; i<=4; i++){
                    if(!seen.count(i)){
                        grid[row+1][col] = i;
                        seen.insert(i);
                        break;
                    }
                }
            }
            if(grid[row][col+1]==-1){
                for(int i = 0; i<=4; i++){
                    if(!seen.count(i)){
                        grid[row][col+1] = i;
                        seen.insert(i);
                        break;
                    }
                }
            }
            if(grid[row][col]==-1){
                for(int i = 0; i<=4; i++){
                    if(!seen.count(i)){
                        grid[row][col] = i;
                        seen.insert(i);
                        break;
                    }
                }
            }

        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (grid[i][j] == -1) {
                grid[i][j] = 0;
            }
        }
    }

    return grid;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> grid = solve(N, M);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (j > 0) cout << ' ';
                cout << grid[i][j];
            }
            cout << '\n';
        }
    }
    return 0;
}
