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
    vector<pair<int,int>> seg(N);
    seg[0]={A[0],A[0]};

    for(int i=1;i<N;i++){
        auto [l,r]=seg[i-1];
        if(A[i]<l)seg[i]={A[i],l};
        else if(A[i]>r)seg[i]={r,A[i]};
        else seg[i]={A[i],A[i]};
    }

    vector<int> B(N);
    B[N-1]=seg[N-1].first;
    for(int i=N-2;i>=0;i--){
        int l=seg[i].first,r=seg[i].second;
        B[i]=min(max(B[i+1],l),r);
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
