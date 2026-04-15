
#include <bits/stdc++.h>
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
    
    vector<int> B = A;
    
    for(int i=0; i<A.size(); i++){
        long long int topRow2diff = abs(A[i] - A[i+1]);
        long long int bottomRow2diff = abs(B[i] - B[i+1]);
        
        if(topRow2diff == bottomRow2diff && topRow2diff != 1){
            B[i+1] = A[i+1] - topRow2diff;
        }
        
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