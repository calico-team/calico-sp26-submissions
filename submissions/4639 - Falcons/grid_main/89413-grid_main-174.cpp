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
    set<int> st(A.begin(), A.end());
    vector<int> vs(st.begin(), st.end());
    int m = vs.size();
    vector<vector<int> > dp(N, vector<int>(m, INT_MAX / 2));
    vector<vector<int> > pre(N, vector<int>(m, -1));
    for (int k = 0; k < m;k++)
	{
        dp[0][k] = abs(A[0] - vs[k]);
    }
    for (int i = 1;i<N;i++)
	{
        for (int k=0;k<m;k++)
		{
            int cost = abs(A[i] - vs[k]);
            for (int j=0;j<m;j++)
			{
                int total = dp[i-1][j] + abs(vs[j] - vs[k]) + cost;
                if (total < dp[i][k])
				{
                    dp[i][k] = total;
                    pre[i][k] = j;
                }
            }
        }
    }
    int best = 0;
    for (int k = 1; k < m; ++k)
	{
        if (dp[N-1][k] < dp[N-1][best])
            best = k;
    }
    vector<int> B(N);
    for (int i = N-1; i >= 0; --i)
	{
        B[i] = vs[best];
        best = pre[i][best];
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
