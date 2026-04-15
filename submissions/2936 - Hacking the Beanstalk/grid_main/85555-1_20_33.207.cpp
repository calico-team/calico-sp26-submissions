#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>

using namespace std;

/*
 * Find an array B of N integers representing the filled-in second row,
 * chosen to minimize the sum of absolute differences of adjacent
 * numbers on the grid.
 * 
 * N: the number of columns in the 2 x N grid
 * A: vector of N integers giving the first row of the grid
 */
vector<int> solve(int N, vector<int>& A) {
    vector<int> B(N);
    // int ma = -1000000000;
    int mi = 1000000000; 
    int total = 0;
    for(int i = 0; i < N; i++) {
        total += A[i];
        // ma = max(ma,A[i]);
        mi = min(mi,A[i]);
    }
    int average = (total - mi * N) / N;
    for(int i = 0; i < N; i++) {
        B[i] = average; 
    }

    
    return B;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        vector<int> result = solve(N, A);
        for (int i = 0; i < N; i++) {
            if (i > 0) cout << ' ';
            cout << result[i];
        }
        cout << '\n';
    }
    return 0;
}
