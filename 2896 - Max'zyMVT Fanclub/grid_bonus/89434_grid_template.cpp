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
    vector<int> ans(N);
    if (N==1) {
        ans[0]=A[0];
        return ans;
    }
    ans[0]=A[0];
    ans[N-1]=A[N-1];
    for (int i=1;i<N-1;i++) {
        vector<int> tmp;
        tmp.push_back({A[i-1]});
        tmp.push_back({A[i]});
        tmp.push_back({A[i+1]});
        sort(tmp.begin(),tmp.end());
        ans[i]=tmp[1];
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