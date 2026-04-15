#include <iostream>
#define FASTIO std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL)
using namespace std;

int main() { FASTIO;
    int t; // # of test cases
    int m, n; // size of grid
    cin >> t;
    while (t--) {
        cin >> n >> m;
        int grid[n][m];
        int num = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                grid[i][j] = num;
                cout << num << " ";
                num++;
                if (num == 5) num = 0;
            }
            num = grid[i][2];
            cout << endl;
        }
    }
    return 0;
}