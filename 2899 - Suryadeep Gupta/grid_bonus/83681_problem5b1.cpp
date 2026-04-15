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
        for (int i = 0; i < N; i++) cin >> the_two_tower_heights[i];

        // Optimal: b = A works (minimizes total cost)
        // Any constant shift also works, but simplest is copy

        for (int i = 0; i < N; i++) {
            cout << the_two_tower_heights[i] << (i + 1 < N ? ' ' : '\n');
        }
    }

    return 0;
}

void read_your_input() {}