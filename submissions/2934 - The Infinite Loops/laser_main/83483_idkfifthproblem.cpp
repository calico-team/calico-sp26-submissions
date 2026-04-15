#include <algorithm>
#include <cstddef>
#include <cstdint>
//#include <filesystem>
#include <future>
#include <iostream>
#include <iterator>
#include <optional>
#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <fstream>
#include <cassert>
#include <numeric>
#include <unordered_set>    
#include <map>
using namespace std;
//the ultimate testing testy .cpp where you can test to your test's desire
int main() {
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        
        int A, X, Y, VY, VX;
        cin >> A >> X >> Y >> VY >> VX;
        vector< vector<int> > grid (1000, vector<int>(1000, -1));
        int LY = -1, LX = -1;
        for(int j = 0; j < A; j++){
            int x, y;
            cin >> x >> y;
            if(LY == -1){
                LY = y;
                LX = x;
            }
            grid[x][y] = j;
        }

        int res = min(VY, VX);
        while (res > 1) {
            if (VY % res == 0 && VX % res == 0)
                break;
            res--;
        }

        //cout << "gcd is " << res << endl;

        VY = VY/res;
        VX = VX/res;
        //^^^^^^^^^^^^ use GCD to do smallest steps that matter

        for(int j = 0; j < 1000000; j++){
            LX = (LX + VX)%X;
            LY = (LY + VY)%Y;
            //cout << LX << " " << LY << endl;
            if(grid[LX][LY] != -1){
                cout << grid[LX][LY] << endl;
                break;
            }
        }

    }

};
 