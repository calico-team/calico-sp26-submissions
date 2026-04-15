#include <bits/stdc++.h>
using namespace std;

vector<string> solve(int P, int A, int B) {
    int total = 1;
    for (int i = 0; i < A; i++) total *= 2;
    for (int i = 0; i < B; i++) total *= 3;
    
    int remaining = total - P;
    
    int height = 2;
    int width = A + B + 3;
    
    vector<string> grid(height, string(width, '.'));
    
    grid[0][0] = 'v';
    grid[1][0] = '>';
    
    int col = 1;
    for (int i = 0; i < A; i++) {
        grid[0][col] = 'S';
        grid[1][col] = 'v';
        col++;
    }
    
    for (int i = 0; i < B; i++) {
        grid[0][col] = 'S';
        grid[1][col] = '>';
        col++;
    }
    
    grid[0][col] = 'v';
    grid[1][col] = 'X';
    col++;
    
    grid[0][col] = '>';
    grid[1][col] = '.';
    
    return grid;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    while (T--) {
        int P, A, B;
        cin >> P >> A >> B;
        vector<string> factory = solve(P, A, B);
        int N = (int) factory.size();
        int M = (int) factory[0].size();
        cout << N << ' ' << M << '\n';
        for (const string& row : factory) {
            cout << row << '\n';
        }
    }
    return 0;
}