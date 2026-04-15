#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid (n, vector<int> (m));
        vector<int> pattern = {0, 2, 4, 1, 3};
        // 0 2 4 1 3
        for(int i = 0; i < n; i++) {
            int start = pattern[i % 5];
            for(int j = 0; j < m; j++) {
                grid[i][j] = start%5;
                start++; 
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
    }
}
