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
    // YOUR CODE HERE
    int Min = INT_MAX;
    int Toprow = 0;
    vector<int> B(N, 0);
    vector<int> best(N, 0);
    for(int i = 0; i < N-1; i++){
        Toprow += abs(A[i]-A[i+1]);
    }
    for(int j : A) {
        for(int k : A) {

            B[0] = j;
            B[1] = k;

            for(int i=2; i<N; i++) B[i] = k;

            int Bottomrow = 0;
            for(int i = 0; i < N-1; i++){
                Bottomrow += abs(B[i]-B[i+1]);
            }
            int Between = 0;
            for(int i = 0; i < N; i++){
                Between += abs(A[i]-B[i]);
            }

            if(Toprow+Bottomrow+Between < Min){
                Min = Toprow+Bottomrow+Between;
                best = B;
            }
        }
    }
    return best;
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
