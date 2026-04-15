/*
ID: connorl3   
TASK: measurement
LANG: C++17
*/


// #include <bits/stdc++.h>

#include <iostream>
#include <array>
#include <fstream>
#include <set>
#include <tuple>
#include <map>
#include <cctype>
#include <unordered_map>
#include <vector>
#include <utility>
#include <random>
#include <cstdlib>
#include <sstream>

using namespace std;

ifstream fin("measurement.in");
ofstream fout("measurement.out");

void solve() {
    int n, p, r, k;
    cin >> n >> p >> r >> k;
    vector<int>e(n);
    for(auto &i : e) {
        cin >> i;
    }
    bool gojoPerished = false;
    int amtOfCurses = 0;
    for(int i = 0; i < n; i++) {
        p -= e[i];
        amtOfCurses++;
        if(p < 0){
            gojoPerished = true;
            break;
        }
        if(amtOfCurses == k){
            amtOfCurses = 0;
            p += r;
        }
    }

    cout << (!gojoPerished ? "nah i’d win" : "nah i’d lose") << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}
