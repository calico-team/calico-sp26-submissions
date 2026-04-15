#include<bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        long long P;
        int A, B;
        cin >> P >> A >> B;
        
        long long INF = 2000000000000LL; 
        vector<long long> d3(B);
        vector<long long> d2(A);
        
        long long current_val = 1;
        for (int j = A - 1; j >= 0; --j) {
            d2[j] = current_val;
            if (current_val > INF / 2) current_val = INF;
            else current_val *= 2;
        }
        
        for (int i = B - 1; i >= 0; --i) {
            d3[i] = current_val;
            if (current_val > INF / 3) current_val = INF;
            else current_val *= 3;
        }
        
        long long rem = P;
        vector<int> d3up(B, 0), d3down(B, 0);
        vector<int> d2down(A, 0);
        int final_coll = 0;
        
        for (int i = 0; i < B; ++i) {
            if (rem >= d3[i]) {
                rem -= d3[i];
                d3up[i] = 1;
            }
            if (rem >= d3[i]) {
                rem -= d3[i];
                d3down[i] = 1;
            }
        }
        
        for (int j = 0; j < A; ++j) {
            if (rem >= d2[j]) {
                rem -= d2[j];
                d2down[j] = 1;
            }
        }
        
        if (rem >= 1) {
            rem -= 1;
            final_coll = 1;
        }
        
        int M = 2 * A + 2 * B + 3;
        vector<string> grid(5, string(M, '.'));
        
        grid[0][0] = 'v';
        grid[1][0] = 'v';
        grid[2][0] = '>';
        if (M > 1) {
            grid[2][1] = '>';
        }
        
        int c = 2;
        for (int i = 0; i < B; ++i) {
            grid[2][c] = 'S';
            grid[2][c-1] = '>'; 
            if (d3up[i]) {
                grid[1][c] = '^';
                grid[0][c] = '^'; 
            } else {
                grid[1][c] = 'X';
            }
            
            if (d3down[i]) {
                grid[3][c] = 'v';
                grid[4][c] = 'v';
            } else {
                grid[3][c] = 'X';
            }
            c += 2;
        }
        
        for (int j = 0; j < A; ++j) {
            grid[2][c] = 'S';
            grid[2][c-1] = '>';
            if (d2down[j]) {
                grid[3][c] = 'v';
                grid[4][c] = 'v';
            } else {
                grid[3][c] = 'X';
            }
            c += 2;
        }
        
        grid[2][c-1] = '>';
        if (final_coll) {
            grid[2][c] = '>'; 
        } else {
            grid[2][c] = 'X'; 
        }
        
        cout << 5 << " " << M << "\n";
        for (int i = 0; i < 5; ++i) {
            cout << grid[i] << "\n";
        }
    }
    
    return 0;
}