#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T; 
    cin >> T;
    while (T--) {
        int N;
        cin >> N;

        vector<ll> the_two_tower_heights(N);
        for (int i = 0; i < N; i++) {
            cin >> the_two_tower_heights[i];
        }

        // Optimal construction:
        // b[i] = median of (A[i-1], A[i], A[i+1]) when possible
        // edges handled separately

        vector<ll> b(N);

        if (N == 1) {
            b[0] = the_two_tower_heights[0];
        } else {
            // first
            b[0] = the_two_tower_heights[0];

            // middle
            for (int i = 1; i < N - 1; i++) {
                ll x = the_two_tower_heights[i - 1];
                ll y = the_two_tower_heights[i];
                ll z = the_two_tower_heights[i + 1];

                vector<ll> v = {x, y, z};
                sort(v.begin(), v.end());
                b[i] = v[1];
            }

            // last
            b[N - 1] = the_two_tower_heights[N - 1];
        }

        for (int i = 0; i < N; i++) {
            cout << b[i] << (i + 1 < N ? ' ' : '\n');
        }
    }

    return 0;
}

void read_your_input() {}