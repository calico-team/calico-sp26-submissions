#include <iostream>
#include <vector>
using namespace std;

/*
 * Create an N x M grid such that every valid cross contains 0-4 exactly once.
 * 
 * N: number of rows in the grid
 * M: number of columns in the grid
 */

const int pattern[5][5] = {
    {4,0,1,2,3},
    {1,2,3,4,0},
    {3,4,0,1,2},
    {0,1,2,3,4},
    {2,3,4,0,1}
};

vector<vector<int>> solve(int N, int M) {
    vector<vector<int>> result(N, vector<int>(M, 0));
    // YOUR CODE HERE
    
    int ri = 0; //row
    for(int i=0; i <N; i++){
        int cj = 0; //collumn
        for(int j=0; j < M; j++){
            result[i][j] = pattern[ri][cj];
            cj++;
            if(cj == 5){
                cj = 0;
            }
        }
        ri++;
        if(ri == 5){
            ri = 0;
        }
    }
    return result;
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
