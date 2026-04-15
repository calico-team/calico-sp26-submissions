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
    int bst = -1; //best found cost
    vector<int> ans = A; //make the array the same as the top to just update it as we find better solutions
    vector<int> B(N); //for each column we try all possible values and calculate the costs using the formula given in the example
    int lo = 0, hi = 200; //search range for each value
    auto dfs = [&](auto& self, int i)->void { //instead of looping over every value just dfs over the columns and try all values for each column
        if (i==N) { //we have filled all columns
            int c = 0; //calculated cost for the current arr
            for (int j=0; j<N; j++) c+=abs(B[j]-A[j]);
            for (int j=0; j+1<N; j++) c+=abs(B[j]-B[j+1])+abs(A[j]-A[j+1]);
            if (bst==-1||c<bst) {
                bst = c; //update best if its better
                ans = B; //set the answer to the current set to output
            }
            return;
        }
        for (int v = lo; v <= hi; v++) { //try all possible values for column i
            B[i] = v;
            self(self, i+1);
        }
    };
    dfs(dfs, 0);
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
