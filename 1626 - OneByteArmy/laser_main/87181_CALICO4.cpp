#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--){
        long long k, n, m, p, q;
        cin >> k >> n >> m >> p >> q;
        vector<pair<int,int>> coords(k);
        for(int i = 0; i < k; i++){
            cin >> coords[i].first >> coords[i].second;
        }
        int count = 0;
        vector<vector<int>> grid(n, vector<int>(m,-1));
        for(int i = 0; i < k; i++){
            int x = coords[i].first;
            int y = coords[i].second;
            if(grid[x][y] == -1){
                grid[x][y] = i;
            }
        }
        int start_x = coords[0].first;
        int start_y = coords[0].second;
        while(count < 1){
            start_x = (start_x + q)%n;
            start_y = (start_y + p)%m;

            if(grid[start_x][start_y] != -1){
                cout << grid[start_x][start_y] << endl;
                break;
            }
            
        }
    }
    
}
