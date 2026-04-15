#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e18; 
/*
 * Find an array B of N integers representing the filled-in second row,
 * chosen to minimize the sum of absolute differences of adjacent
 * numbers on the grid.
 * 
 * N: the number of columns in the 2 x N grid
 * A: vector of N integers giving the first row of the grid
 */
vector<int> solve(int N, vector<int>& A) {
    vector<int> v = A;
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    int M = v.size();

    vector<vector<ll>> dp(N, vector<ll>(M, INF));

    vector<vector<int>> p(N, vector<int>(M, 0));

    for (int j = 0; j < M; j++) {
        dp[0][j] = abs(A[0] - v[j]);
    }

    for (int i = 1; i < N; i++) {
        
        ll min_left = INF;
        int best_left = 0;
        vector<ll> best_from_left(M);
        vector<int> left_ans(M);
        
        for (int j = 0; j < M; j++) {
            ll tcost = dp[i-1][j] - v[j];
            if (tcost < min_left) {
                min_left = tcost;
                best_left = j;
            }
            best_from_left[j] = min_left + v[j];
            left_ans[j] = best_left;
        }
        
        ll min_right = INF;
        int best_right = M - 1;
        vector<ll> best_from_right(M);
        vector<int> right_ans(M);
        
        for (int j = M - 1; j >= 0; j--) {
            ll tcost = dp[i-1][j] + v[j];
            if (tcost < min_right) {
                min_right = tcost;
                best_right = j;
            }
            best_from_right[j] = min_right - v[j];
            right_ans[j] = best_right;
        }
        
        for (int j = 0; j < M; j++) {
            ll cost = abs(A[i] - v[j]);
            
            if (best_from_left[j] < best_from_right[j]) {
                dp[i][j] = cost + best_from_left[j];
                p[i][j] = left_ans[j];
            } else {
                dp[i][j] = cost + best_from_right[j];
                p[i][j] = right_ans[j];
            }
        }
    }

    ll final_min_cost = INF;
    int curr_j = 0;
    for (int j = 0; j < M; j++) {
        if (dp[N-1][j] < final_min_cost) {
            final_min_cost = dp[N-1][j];
            curr_j = j;
        }
    }

    vector<int> B(N);
    for (int i = N - 1; i >= 0; i--) {
        B[i] = v[curr_j];
        if (i > 0) {
            curr_j = p[i][curr_j]; 
        }
    }

    return B;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

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
