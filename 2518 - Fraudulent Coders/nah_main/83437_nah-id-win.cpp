#include <bits/stdc++.h>
using namespace std;

const int MM = 1e4 + 2;
int n, p, r, k;
int ene[MM];

bool solve() {
    cin >> n >> p >> r >> k;

    for (int x = 0; x < n; x++) cin >> ene[x];

    int kills = 0;
    for (int x = 0; x < n; x++) {
        p -= ene[x];
        // if (p < 0 && kills >= k && p + r >= 0) p += r;
        // else return false;

        if (p < 0) {
            if (kills >= k && r + p >= ene[x]) p += r;
            else return false;

            kills = 0;
        }

        kills++;
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        if (solve()) {
            cout << "nah i'd win" << "\n";
        } else {
            cout << "nah i'd lose" << "\n";
        }
    }

    return 0;
}