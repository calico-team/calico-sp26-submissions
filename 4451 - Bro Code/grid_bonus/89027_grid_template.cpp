#include <bits/stdc++.h>
using namespace std;
vector<int> solve(int N, vector<int>& A) {
    vector<int> the_two_tower_heights(N);
    for (int i = 0; i < N; i++) {
        vector<int> neighbors;
        if (i > 0) neighbors.push_back(A[i-1]);
        neighbors.push_back(A[i]);
        if (i < N-1) neighbors.push_back(A[i+1]);
        sort(neighbors.begin(), neighbors.end());
        the_two_tower_heights[i] = neighbors[(neighbors.size() - 1) / 2];
    }
    return the_two_tower_heights;
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