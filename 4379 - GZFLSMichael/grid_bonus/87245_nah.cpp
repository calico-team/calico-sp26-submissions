#include <bits/stdc++.h>
using namespace std;

struct Segment {
    priority_queue<long long> left;
    priority_queue<long long, vector<long long>, greater<long long>> right;
    int size;
    long long median;
};

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<long long> A(N);
        for (int i = 0; i < N; ++i) cin >> A[i];
        vector<long long> b(N);

        if (N <= 3) {
            long long A3[3] = {0};
            for (int i = 0; i < N; ++i) A3[i] = A[i];
            long long b3[3];
            if (N == 1) {
                b3[0] = 1;
            } else if (N == 2) {
                b3[0] = A3[0];
                b3[1] = A3[1];
            } else {
                long long cand[5] = {A3[0], A3[1], A3[2], (A3[0]+A3[1])/2, (A3[1]+A3[2])/2};
                long long best_cost = 1e18;
                long long best_b[3];
                for (int i0 = 0; i0 < 5; ++i0)
                    for (int i1 = 0; i1 < 5; ++i1)
                        for (int i2 = 0; i2 < 5; ++i2) {
                            long long b0 = cand[i0], b1 = cand[i1], b2 = cand[i2];
                            long long cost = abs(A3[0]-A3[1]) + abs(A3[1]-A3[2])
                                           + abs(b0-b1) + abs(b1-b2)
                                           + abs(A3[0]-b0) + abs(A3[1]-b1) + abs(A3[2]-b2);
                            if (cost < best_cost) {
                                best_cost = cost;
                                best_b[0] = b0; best_b[1] = b1; best_b[2] = b2;
                            }
                        }
                b3[0] = best_b[0]; b3[1] = best_b[1]; b3[2] = best_b[2];
            }
            for (int i = 0; i < N; ++i) b[i] = b3[i];
        } else {
            Segment stk[100005];
            int top = 0;
            for (int i = 0; i < N; ++i) {
                stk[top].left = priority_queue<long long>();
                stk[top].right = priority_queue<long long, vector<long long>, greater<long long>>();
                stk[top].left.push(A[i]);
                stk[top].size = 1;
                stk[top].median = A[i];
                top++;
                while (top >= 2 && stk[top-2].median > stk[top-1].median) {
                    Segment &a = stk[top-2], &b = stk[top-1];
                    while (!b.left.empty()) {
                        a.left.push(b.left.top());
                        b.left.pop();
                    }
                    while (!b.right.empty()) {
                        a.right.push(b.right.top());
                        b.right.pop();
                    }
                    a.size += b.size;
                    while (a.left.size() > a.right.size() + 1) {
                        a.right.push(a.left.top());
                        a.left.pop();
                    }
                    while (a.right.size() > a.left.size()) {
                        a.left.push(a.right.top());
                        a.right.pop();
                    }
                    a.median = a.left.top();
                    --top;
                }
            }
            int idx = 0;
            for (int i = 0; i < top; ++i) {
                long long val = stk[i].median;
                int cnt = stk[i].size;
                for (int j = 0; j < cnt; ++j) b[idx++] = val;
            }
        }

        for (int i = 0; i < N; ++i) {
            if (i) cout << ' ';
            cout << b[i];
        }
        cout << '\n';
    }
    return 0;
}