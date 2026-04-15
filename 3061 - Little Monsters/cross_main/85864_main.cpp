// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;

void solve(int x, int y){
    vector <vector <int>> grid;
    for(int i = 0; i < x; i ++){ // fill -1 to mark as empty
        vector <int> row;
        for(int j = 0; j < y; j++){
            row.push_back(-1);
        }
        grid.push_back(row);
    }
    // center tracker
    int Xc = 2;
    int Yc = 1;
    // init the umm the fking thing
    grid[1][1] = 2;
    grid[0][1] = 0;
    grid[1][2] = 3;
    grid[1][0] = 1;
    grid[2][1] = 4;
    while(Yc != (y-1) && Xc != (x-1)){ // if center is last center BAD LEAVE 
        vector <int> needs = {0,1,2,3,4};
        while(needs.size() != 0){
            // first search see which numbers r missing thne fill in
            
        }
    }
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            if(grid[i][j] == -1){
                grid[i][j] = 0;
            }
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    return;
}

int main() {
    int count;
    cin >> count;
    for(int i = 0; i < count; i ++){
        int xLen;
        int yLen;
        cin >> xLen;
        cin >> yLen;
        solve(xLen, yLen);
    }
    return 0;
}