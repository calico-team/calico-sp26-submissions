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


        vector<ll> b(N);

        if (N == 1) {
            b[0] = the_two_tower_heights[0];
        } else {
            b[0] = the_two_tower_heights[0];

            for (int i = 1; i < N - 1; i++) {
                ll a = the_two_tower_heights[i - 1];
                ll c = the_two_tower_heights[i];
                ll d = the_two_tower_heights[i + 1];

                if ((a <= c && c <= d) || (d <= c && c <= a)) b[i] = c;
                else if ((c <= a && a <= d) || (d <= a && a <= c)) b[i] = a;
                else b[i] = d;
            }

            b[N - 1] = the_two_tower_heights[N - 1];
        }

        for (int i = 0; i < N; i++) {
            cout << b[i] << (i + 1 < N ? ' ' : '\n');
        }
    }

    return 0;
}

void read_your_input() {}