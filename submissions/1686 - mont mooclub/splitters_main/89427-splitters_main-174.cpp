// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

vector<long long> addfractions(vector<long long> a, vector<long long> b){
    long long lc = lcm(a[1], b[1]);
    return {a[0]*lc/a[1]+b[0]*lc/b[1], lc};
}

int main() {
	long long t; cin >> t;
    for (int p = 0; p<t; p++){
        long long n, m; cin >> n >> m;
        vector<vector<char>> grid;
        for (int i = 0; i < n; i++){
            grid.push_back({});
        }
        for (int i = 0; i<n; i++){
            string s; cin >> s;
            for (int j = 0; j<m; j++){
                grid[i].push_back(s[j]);
            }
        }

        vector<vector<vector<vector<long long>>>> grid2;

        vector<vector<vector<long long>>> thisproblemsucks;
        for (int i = 0; i < n; i++){
            vector<vector<long long>> temp1 = {};
            for (int j =0; j<m; j++){
                temp1.push_back({});
            }
            thisproblemsucks.push_back(temp1);
        }
        grid2.push_back(thisproblemsucks);
        grid2.push_back(thisproblemsucks);

        grid2[0][0][0] = {1,1};
        
        
        vector<long long> totalsum = {0,1};
        for (int i = 0; i<5000; i++){
            for (int j = 0; j<n; j++){
                for (int k = 0; k<m; k++){
                    if ((grid2[0][j][k]).size() > 0){
                        if (grid[j][k] == '^'){
                            if (j == 0){
                                totalsum = addfractions(totalsum, grid2[0][j][k]);
                            }
                            else{
                                if (grid2[1][j-1][k].size() != 0){
                                    grid2[1][j-1][k] = addfractions(grid2[1][j-1][k], grid2[0][j][k]);
                                }
                                else{
                                    grid2[1][j-1][k] = grid2[0][j][k];
                                }
                            }
                        }
                        
                        if (grid[j][k] == 'v'){
                            if (j == n-1){
                                totalsum = addfractions(totalsum, grid2[0][j][k]);
                            }
                            
                            else{
                                if (grid2[1][j+1][k].size() != 0){
                                    grid2[1][j+1][k] = addfractions(grid2[1][j+1][k], grid2[0][j][k]);
                                }
                                else{
                                    grid2[1][j+1][k] = grid2[0][j][k];
                                }
                                
                            }                            
                        }

                        if (grid[j][k] == '<'){
                            if (k == 0){
                                totalsum = addfractions(totalsum, grid2[0][j][k]);
                            }
                            
                            else{
                                if (grid2[1][j][k-1].size() != 0){
                                    grid2[1][j][k-1] = addfractions(grid2[1][j][k-1], grid2[0][j][k]);
                                }
                                else{
                                    grid2[1][j][k-1] = grid2[0][j][k];
                                }
                                
                            }                            
                        } 

                        if (grid[j][k] == '>'){
                            if (k == m-1){
                                totalsum = addfractions(totalsum, grid2[0][j][k]);
                            }
                            
                            else{
                                if (grid2[1][j][k+1].size() != 0){
                                    grid2[1][j][k+1] = addfractions(grid2[1][j][k+1], grid2[0][j][k]);
                                }
                                else{
                                    grid2[1][j][k+1] = grid2[0][j][k];
                                }
                                
                            }                            
                        }

                        if (grid[j][k] == 'S'){
                            long long count = 0;
                            if(j != 0){
                                if (grid[j-1][k] != 'v' && grid[j-1][k] != '.'){
                                    count++;
                                }
                            }
                            if(j != n-1){
                                if (grid[j+1][k] != '^' && grid[j+1][k] != '.'){
                                    count++;
                                }
                            }
                            if(k != 0){
                                if (grid[j][k-1] != '>' && grid[j][k-1] != '.'){
                                    count++;
                                }
                            }
                            if(k != m-1){
                                if (grid[j][k+1] != '<' && grid[j][k+1] != '.'){
                                    count++;
                                }
                            }


                            if(j != 0){
                                if (grid[j-1][k] != 'v' && grid[j-1][k] != '.'){
                                    grid2[1][j-1][k] = {grid2[0][j][k][0], grid2[0][j][k][1]*count};
                                }
                            }
                            if(j != n-1){
                                if (grid[j+1][k] != '^' && grid[j+1][k] != '.'){
                                    grid2[1][j+1][k] = {grid2[0][j][k][0], grid2[0][j][k][1]*count};
                                }
                            }
                            if(k != 0){
                                if (grid[j][k-1] != '>' && grid[j][k-1] != '.'){
                                    grid2[1][j][k-1] = {grid2[0][j][k][0], grid2[0][j][k][1]*count};
                                }
                            }
                            if(k != m-1){
                                if (grid[j][k+1] != '<' && grid[j][k+1] != '.'){
                                    grid2[1][j][k+1] = {grid2[0][j][k][0], grid2[0][j][k][1]*count};
                                }
                            }
                        }            
                    }
                }
            }
            swap(grid2[0], grid2[1]);
            for (int j = 0; j<n; j++){
                for (int k = 0; k<m; k++){
                    if (grid2[1][j][k].size() == 0){
                        //cout << 0 << " ";
                    }
                    else{
                        //cout << grid2[1][j][k][0] << grid2[1][j][k][1] << " ";
                    }
                    grid2[1][j][k] = {};
                }
                //cout << endl;
            }
            //cout << endl;
        }
        
        cout << totalsum[0]/gcd(totalsum[0], totalsum[1]) << " " << totalsum[1]/gcd(totalsum[0], totalsum[1]) << endl;
    }
}
