#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++) {
        long long n, p, r, k;
        cin >> n >> p >> r >> k;

        long long curr_power = p; 
        bool win = true;
        for (int i = 1; i <= n; i++) {
            long long e;
            cin >> e;

            curr_power -= e;
            if (curr_power < 0) {
                win = false;
            }

            if (i % k == 0) {
                curr_power += r;
            }
        }

        if (win) {
            cout << "nah i'd win" << "\n";
        }
        else {
            cout << "nah i'd lose" << "\n";
        }
    }
}