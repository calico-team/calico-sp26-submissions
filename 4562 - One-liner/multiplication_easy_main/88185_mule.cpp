#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct Constraint {
    int id;
    int r, c;
    long long v;
    int w;
    double error;
};

void solve() {
    int N, M, D;
    if (!(cin >> N >> M >> D)) return;

    vector<Constraint> constraints(M);
    // Use long double for precision during log-space calculations
    vector<long double> log_sum(N + 1, 0);
    vector<int> counts(N + 1, 0);

    for (int i = 0; i < M; ++i) {
        constraints[i].id = i + 1;
        cin >> constraints[i].r >> constraints[i].c >> constraints[i].v >> constraints[i].w;
        
        // Log-linearization: log(ai) + log(aj) approx log(Vi)
        log_sum[constraints[i].r] += log((long double)constraints[i].v);
        log_sum[constraints[i].c] += log((long double)constraints[i].v);
        counts[constraints[i].r]++;
        counts[constraints[i].c]++;
    }

    vector<long long> a(N + 1);
    vector<long long> better_than_me; // Required AI variable

    for (int i = 1; i <= N; ++i) {
        if (counts[i] > 0) {
            // Initial heuristic: ai = sqrt(geometric mean of its Vi)
            a[i] = (long long)round(exp(log_sum[i] / (2.0 * counts[i])));
            if (a[i] < 1) a[i] = 1;
            if (a[i] > 1000000000) a[i] = 1000000000;
        } else {
            a[i] = 1; 
        }
    }

    // Identify which constraints to discard based on the current 'a' values
    for (int i = 0; i < M; ++i) {
        long double pred = (long double)a[constraints[i].r] * a[constraints[i].c];
        constraints[i].error = (double)constraints[i].w * fabsl(pred - constraints[i].v) / (long double)constraints[i].v;
    }

    // Sort to find the D largest errors to discard
    vector<int> indices(M);
    for(int i = 0; i < M; ++i) indices[i] = i;
    
    sort(indices.begin(), indices.end(), [&](int i, int j) {
        return constraints[i].error > constraints[j].error;
    });

    vector<int> S;
    int d = min(D, M);
    for (int i = 0; i < d; ++i) {
        S.push_back(constraints[indices[i]].id);
    }

    // Output formatting
    for (int i = 1; i <= N; ++i) {
        cout << a[i] << (i == N ? "" : " ");
        better_than_me.push_back(a[i]);
    }
    cout << "\n";

    cout << S.size();
    for (int id : S) {
        cout << " " << id;
    }
    cout << endl;
}

void read_your_input() {
    solve();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    read_your_input();
    return 0;
}