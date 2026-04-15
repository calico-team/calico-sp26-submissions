#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int L, W, E, R;
        cin >> L >> W >> E >> R;

        int triangle_area = 2 * (L + W);
        int laps = E / (triangle_area * R);

        cout << laps << "\n";
    }

    return 0;
}

void read_your_input() {}