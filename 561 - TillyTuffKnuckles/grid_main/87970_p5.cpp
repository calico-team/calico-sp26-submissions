#include <bits/stdc++.h>
using namespace std;
int main() {
	int T;
    cin >> T;
    for(int i = 0; i < T; i++) {
        int N;
        cin >> N;
        int grid[N];
        for(int a = 0; a < N; a++)
        {
            cin >> grid[a]; 
        }
        sort(grid, grid + N);
        int med = N / 2;
        int bvals = grid[med];
        cout << bvals << " " << bvals << " " << bvals;

    }
}