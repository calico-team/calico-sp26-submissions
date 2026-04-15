/*
ID: connorl3   
TASK: measurement
LANG: C++17
*/


// #include <bits/stdc++.h>

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

ifstream fin("measurement.in");
ofstream fout("measurement.out");

void solve() {
    long long gr, gc, mr, mc;
    cin >> gr >> gc >> mr >> mc;

    long long D = abs(gr - mr) + abs(gc - mc);
    long long R = 2 * D / 5 + 1;

    long long count = 0;
    for (long long dr = -R; dr <= R; dr++) {
        long long maxDc = R - abs(dr);
        for (long long dc = -maxDc; dc <= maxDc; dc++) {
            long long dist_m = abs(dr) + abs(dc);
            long long dist_g = abs(mr + dr - gr) + abs(mc + dc - gc);
            if (7 * dist_m < 2 * dist_g) count++;
        }
    }

    cout << count << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}

