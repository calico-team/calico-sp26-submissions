#include <bits/stdc++.h>
using namespace std;

/*
 * Find an array B of N integers representing the filled-in second row,
 * chosen to minimize the sum of absolute differences of adjacent
 * numbers on the grid.
 */
vector<int> solve(int N, vector<int>& A) {

    vector<int> the_two_tower_heights(N);

    vector<int> temp = A;
    sort(temp.begin(), temp.end());

    int median = temp[N / 2];

    for(int i = 0; i < N; i++){
        the_two_tower_heights[i] = median;
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