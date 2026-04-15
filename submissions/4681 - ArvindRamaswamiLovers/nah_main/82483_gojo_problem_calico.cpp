#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, power, r, k;
        cin >> n >> power >> r >> k;
        vector<int> curses(n);
        for (int i = 0; i < n; i++) cin >> curses[i];

        int curses_defeated = 0;
        bool alive = true;

        for (int i = 0; i < n; i++) {
            if (power < curses[i]) {
                alive = false;
                break;
            }
            power -= curses[i];
            curses_defeated++;

            if (curses_defeated == k) {
                power += r;
                curses_defeated = 0;
            }
        }

        cout << (alive ? "nah i'd win" : "nah i'd lose") << "\n";
    }
    return 0;
}