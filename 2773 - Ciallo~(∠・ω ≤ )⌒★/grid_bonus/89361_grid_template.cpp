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
    vector<int> lis_up;
    vector<int> idx_up(N, -1), pre_up(N, -1);
    for (int i = 0; i < N; ++i) {
        auto it = lower_bound(lis_up.begin(), lis_up.end(), A[i]);
        int pos = it - lis_up.begin();
        if (it == lis_up.end()) {
            lis_up.push_back(A[i]);
        } else {
            *it = A[i];
        }
        idx_up[pos] = i;
        if (pos > 0) pre_up[i] = idx_up[pos - 1];
    }
    int len_up = lis_up.size();
    int cur_up = idx_up[len_up - 1];
    vector<int> seq_up;
    while (cur_up != -1) {
        seq_up.push_back(cur_up);
        cur_up = pre_up[cur_up];
    }
    reverse(seq_up.begin(), seq_up.end());
        
    vector<int> lds_down;
    vector<int> idx_down(N, -1), pre_down(N, -1);
    for (int i = 0; i < N; ++i) {
        auto it = upper_bound(lds_down.begin(), lds_down.end(), A[i], greater<int>());
        int pos = it - lds_down.begin();
        if (it == lds_down.end()) {
            lds_down.push_back(A[i]);
        } else {
            *it = A[i];
        }
        idx_down[pos] = i;
        if (pos > 0) pre_down[i] = idx_down[pos - 1];
    }
    int len_down = lds_down.size();
    int cur_down = idx_down[len_down - 1];
    vector<int> seq_down;
    while (cur_down != -1) {
        seq_down.push_back(cur_down);
        cur_down = pre_down[cur_down];
    }
    reverse(seq_down.begin(), seq_down.end());

    if(lis_up.size() >= lds_down.size()) {
        for(int j=0; j<seq_up[0]; j++) {
            B[j] = A[seq_up[0]];
        }
        for (int i = 0; i < seq_up.size(); ++i) {
            B[seq_up[i]] = A[seq_up[i]];
            for(int j=seq_up[i]+1; j<(i+1<seq_up.size() ? seq_up[i+1] : N); j++) {
                int seq_min = min(A[seq_up[i]], (i+1<seq_up.size() ? A[seq_up[i+1]] : A[N-1]));
                int seq_max = max(A[seq_up[i]], (i+1<seq_up.size() ? A[seq_up[i+1]] : A[N-1]));
                if (A[j] < seq_min) {
                    B[j] = seq_min;
                } else if (A[j] > seq_max) {
                    B[j] = seq_max;
                } else {
                    B[j] = A[seq_up[i]];
                }
            }
        }
    } else {
        for(int j=0; j<seq_down[0]; j++) {
            B[j] = A[seq_down[0]];
        }
        for (int i = 0; i < seq_down.size(); ++i) {
            B[seq_down[i]] = A[seq_down[i]];
            for(int j=seq_down[i]+1; j<(i+1<seq_down.size() ? seq_down[i+1] : N); j++) {
                int seq_min = min(A[seq_down[i]], (i+1<seq_down.size() ? A[seq_down[i+1]] : A[N-1]));
                int seq_max = max(A[seq_down[i]], (i+1<seq_down.size() ? A[seq_down[i+1]] : A[N-1]));
                if (A[j] < seq_min) {
                    B[j] = seq_min;
                } else if (A[j] > seq_max) {
                    B[j] = seq_max;
                } else {
                    B[j] = A[seq_down[i]];
                }
            }
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
