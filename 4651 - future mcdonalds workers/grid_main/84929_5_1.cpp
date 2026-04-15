#include <bits/stdc++.h>
#define int long long
#define pb push_back
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
    if (N==1) return {A[0]}; //if there is only one column then the second row must be the same as the first row to get a cost of 0
    int bst = -1; //best tracker
    vector<int> ans = A; //make the array the same as the top to just update it as we find better solutions
    for (int v0 = 0; v0<=100; v0++) { //check everything in the first column,
        for (int v1 = 0; v1<=100; v1++) { //everything in the second column,
            for (int v2 = 0; v2<=100; v2++) { //everything in the third column,
                vector<int> B = {v0}; //for each column we try all possible values and calculate the costs using the formula given in the example
                if (N>1) B.pb(v1); //these ifs just make sure that we dont add extra columns
                if (N>2) B.pb(v2); 
                int c = 0; //cost tracker for the current set
                for (int i=0; i<N; i++) c+=abs(B[i]-A[i]);
                for (int i=0; i+1<N; i++) c+=abs(B[i]-B[i+1])+abs(A[i]-A[i+1]);
                if (bst==-1||c<bst) {
                    bst = c; //update best if its better
                    ans = B; //set the answer to the current set to output
                }
            }
        }
    }
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; i++) cin >> A[i];
        auto res = solve(N, A);
        for (int i = 0; i < N; i++) cout << (i ? " " : "") << res[i];
        cout << '\n';
    }
    return 0;
}
