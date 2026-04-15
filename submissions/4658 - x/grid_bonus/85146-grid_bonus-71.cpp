#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int N;
        cin >> N;
        vector<long long> A(N);
        for (int i = 0; i < N; ++i) cin >> A[i];

        if (N == 1) {
            cout << A[0] << "\n";
            continue;
        }

        auto solve = [](const vector<long long>& arr) {
            int n = arr.size();
            priority_queue<long long> pq;
            vector<long long> best(n);

            pq.push(arr[0]);
            pq.push(arr[0]);
            best[0] = pq.top();

            for (int i = 1; i < n - 1; ++i) {
                pq.push(arr[i]);
                pq.push(arr[i]);
                pq.pop();
                best[i] = pq.top();
            }

            pq.push(arr[n - 1]);
            pq.push(arr[n - 1]);
            pq.pop();
            pq.pop();
            best[n - 1] = pq.top();

            vector<long long> res(n);
            res[n - 1] = best[n - 1];
            for (int i = n - 2; i >= 0; --i) {
                res[i] = min(res[i + 1], best[i]);
            }
            return res;
        };

        auto calc = [](const vector<long long>& rowA, const vector<long long>& rowB) {
            long long c = 0;
            int n = rowA.size();
            for (int i = 0; i < n; ++i) c += abs(rowA[i] - rowB[i]);
            for (int i = 0; i < n - 1; ++i) c += abs(rowB[i] - rowB[i + 1]);
            return c;
        };

        vector<long long> B1 = solve(A);
        long long c1 = calc(A, B1);

        vector<long long> rev_A = A;
        reverse(rev_A.begin(), rev_A.end());
        vector<long long> B2_rev = solve(rev_A);
        vector<long long> B2 = B2_rev;
        reverse(B2.begin(), B2.end());
        long long c2 = calc(A, B2);

        vector<long long> ans = (c1 <= c2) ? B1 : B2;
        for (int i = 0; i < N; ++i) {
            cout << ans[i] << (i == N - 1 ? "" : " ");
        }
        cout << "\n";
    }
    return 0;
}