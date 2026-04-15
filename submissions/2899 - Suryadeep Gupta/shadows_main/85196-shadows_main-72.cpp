#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<string> s1(n), s2(n);
    for (int i = 0; i < n; i++) cin >> s1[i];
    for (int i = 0; i < n; i++) cin >> s2[i];
    
    // Max volume: place block at (x,y,z) if s1[z][x]=='#' AND s2[z][y]=='#'
    long long max_vol = 0;
    for (int z = 0; z < n; z++)
        for (int x = 0; x < n; x++)
            if (s1[z][x] == '#')
                for (int y = 0; y < n; y++)
                    if (s2[z][y] == '#')
                        max_vol++;

    // Min volume: for each row z, min blocks = max(#count in s1[z], #count in s2[z])
    // We pair up the '#' positions greedily across both shadows
    long long min_vol = 0;
    for (int z = 0; z < n; z++) {
        int c1 = 0, c2 = 0;
        for (int j = 0; j < n; j++) {
            if (s1[z][j] == '#') c1++;
            if (s2[z][j] == '#') c2++;
        }
        min_vol += max(c1, c2);
    }

    cout << max_vol << " " << min_vol << "\n";
}

void read_your_input() {
    int t;
    cin >> t;
    while (t--) solve();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    read_your_input();
    return 0;
}