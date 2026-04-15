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
    vector<int> ans(N);
    ans[0] = A[0];
    for(int i = 1; i < N; i++){
        vector<int> temp;
        temp.push_back(ans[i - 1]);
        for(int j = i; j < N; j++){
            temp.push_back(A[j]);
        }
        sort(temp.begin(), temp.end());
        ans[i] = temp[(temp.size() / 2)];
    }
    return ans;
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
