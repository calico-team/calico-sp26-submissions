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
    vector<int> B(N,0);
    B[0] = A[0];
    B[N-1] = A[N-1];
    bool Trend_Up = B[N-1] > B[0];
    int max_end = max(A[0], A[N-1]);
    int min_end = min(A[0], A[N-1]);
    for(int i=1; i<N-1; i++) {
        if(A[i] > max_end) {
            A[i] = max_end;
        }
        if(A[i] < min_end) {
            A[i] = min_end;
        }
        B[i] = A[i];
    }
    if(B[0] == B[N-1]) {
        return B;
    } else if(Trend_Up) {
        vector<int> lis;
        vector<int> idx(N, -1), pre(N, -1);
        for (int i = 1; i < N - 1; ++i) {
            auto it = lower_bound(lis.begin(), lis.end(), A[i]);
            int pos = it - lis.begin();
            if (it == lis.end()) {
                lis.push_back(A[i]);
            } else {
                *it = A[i];
            }
            idx[pos] = i;
            if (pos > 0) pre[i] = idx[pos - 1];
        }
        int len = lis.size();
        int cur = idx[len - 1];
        vector<int> seq;
        while (cur != -1) {
            seq.push_back(cur);
            cur = pre[cur];
        }
        reverse(seq.begin(), seq.end());
        B[seq[0]] = A[seq[0]];
        for(int j=0; j<seq[0]; j++) {
            B[j] = A[seq[0]];
        }
        for (int i = 1; i < seq.size(); ++i) {
            B[seq[i]] = A[seq[i]];
            for(int j=seq[i-1]+1; j<seq[i]; j++) {
                B[j] = A[seq[i-1]];
            }
        }
        for(int j=seq.back()+1; j<N-1; j++) {
            B[j] = A[seq.back()];
        }
        
        
    } else {
        vector<int> lds;
        vector<int> idx(N, -1), pre(N, -1);
        for (int i = 1; i < N - 1; ++i) {
            auto it = upper_bound(lds.begin(), lds.end(), A[i], greater<int>());
            int pos = it - lds.begin();
            if (it == lds.end()) {
                lds.push_back(A[i]);
            } else {
                *it = A[i];
            }
            idx[pos] = i;
            if (pos > 0) pre[i] = idx[pos - 1];
        }
        int len = lds.size();
        int cur = idx[len - 1];
        vector<int> seq;
        while (cur != -1) {
            seq.push_back(cur);
            cur = pre[cur];
        }
        reverse(seq.begin(), seq.end());
        for(int j=0; j<seq[0]; j++) {
            B[j] = A[seq[0]];
        }
        for (int i = 0; i < seq.size(); ++i) {
            B[seq[i]] = A[seq[i]];
            for(int j=seq[i]+1; j<(i+1<seq.size() ? seq[i+1] : N-1); j++) {
                B[j] = A[seq[i]];
            }
        }
        for(int j=seq.back()+1; j<N-1; j++) {
            B[j] = A[seq.back()];
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
