#include <bits/stdc++.h>
using namespace std;

void solve() {
    int p, a, b;
    cin >> p >> a >> b;
    
    int total = pow(2, a) * pow(3, b);
    int collect = p;
    
    int height = 2 + a + b + 1;
    int width = total + 2;
    
    vector<string> grid;
    
    int levels = a + b;
    
    int max_width = 1;
    for (int i = 0; i < levels; i++) {
        max_width *= 3;
    }
    max_width = max(max_width, total);
    
    if (max_width * (levels + 3) > 2000) {
        int rows = 2 * (levels + 1) + 2;
        int cols = total * 2;
        
        grid.assign(rows, string(cols, '.'));
        
        rows = 3;
        cols = total * 2 + 2;
        grid.assign(rows, string(cols, '.'));
        
        grid[0][0] = 'v';
        
        for (int i = 0; i < total; i++) {
            if (i < collect) {
                grid[1][2*i+1] = '^';
                grid[0][2*i+1] = '.';
            } else {
                grid[1][2*i+1] = 'X';
            }
        }
        
        grid[0][1] = '>';
        for (int i = 1; i < total; i++) {
            grid[0][2*i] = '>';
            grid[0][2*i+1] = 'v';
        }
        
    } else {
        int rows = 2 * levels + 3;
        int cols = max_width * 2;
        grid.assign(rows, string(cols, '.'));
        
        grid[0][0] = 'v';
        
        int current_width = 1;
        int current_col = cols / 2;
        
        vector<pair<int, int>> positions = {{1, current_col}};
        grid[1][current_col] = 'S';
    }
    
    cout << grid.size() << " " << grid[0].size() << "\n";
    for (const auto& row : grid) {
        cout << row << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}