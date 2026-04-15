// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	long long t; cin >> t;
    for (int i = 0; i < t; i++){
        long long x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;

        vector<long long> temp1(101, 0);
        vector<vector<long long>> grid2(101, temp1);
        vector<vector<vector<long long>>> grid(2, grid2);
        
        grid[0][x1+50][y1+50] = 1;
        grid[0][x2+50][y2+50] = 2;
        grid[1][x1+50][y1+50] = 1;
        grid[1][x2+50][y2+50] = 2;

        for (int i = 0; i<1000; i++){
            if ((i+1)%2 == 0){
                for (int j = 0; j<101; j++){
                    for (int k = 0; k<101; k++){
                        if (grid[0][j][k] == 1){
                            if (j > 0 && grid[0][j-1][k] == 0){
                                grid[1][j-1][k] = 1;
                            }
                            if (j < 100 && grid[0][j+1][k] == 0){
                                grid[1][j+1][k] = 1;
                            }
                            if (k > 0 && grid[0][j][k-1] == 0){
                                grid[1][j][k-1] = 1;
                            }
                            if (k < 100 && grid[0][j][k+1] == 0){
                                grid[1][j][k+1] = 1;
                            }
                        }
                    }
                }
            }
            if ((i+1)% 7 == 0){
                for (int j = 0; j<101; j++){
                    for (int k = 0; k<101; k++){
                        if (grid[0][j][k] == 2){
                            if (j > 0 && grid[1][j-1][k] == 0){
                                grid[1][j-1][k] = 2;
                            }
                            if (j < 100 && grid[1][j+1][k] == 0){
                                grid[1][j+1][k] = 2;
                            }
                            if (k > 0 && grid[1][j][k-1] == 0){
                                grid[1][j][k-1] = 2;
                            }
                            if (k < 100 && grid[1][j][k+1] == 0){
                                grid[1][j][k+1] = 2;
                            }
                        }
                    }
                }
            }
            swap(grid[0], grid[1]);
            grid[1] = {};
            for (vector<long long> j: grid[0]){
                grid[1].push_back(j);
            }
        }

        long long cnt = 0;
        for (int i = 0; i<101; i++){
            for (int j = 0; j<101; j++){
                //cout << grid[0][i][j] << " ";
                if (grid[0][i][j] == 2){
                    cnt+=1;
                }
            }
            //cout << endl;
        }
        

        cout << cnt << endl;
    }
}
