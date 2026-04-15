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
    vector<int> ans;
    if (N<3) {
        for (int i=0;i<N;i++) {
            ans.push_back(A[0]);
        }
    }
    else {
        sort(A.begin(),A.end());
        int mid=N/2;
        if (N%2==1) {
            while(N--) {
                ans.push_back(A[mid]);
            }
        }
        else {
            for (int i=0;i<mid;i++) {
                ans.push_back(A[mid-1]);
            }
            for (int i=0;i<mid;i++) {
                ans.push_back(A[mid]);
            }
        }
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