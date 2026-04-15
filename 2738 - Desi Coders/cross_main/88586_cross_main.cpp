#include <bits/stdc++.h>
using namespace std;

void make_the_criss_cross(int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << (i + j) % 5;
            if (j + 1 < m) cout << ' ';
        }
        cout << '\n';
    }
}

void read_your_input() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        make_the_criss_cross(n, m);
    }
}

int main() {
    read_your_input();
    return 0;
}